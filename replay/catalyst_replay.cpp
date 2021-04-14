#include <catalyst.hpp>

#include "mpi.h"

#if defined(_WIN32) && !defined(__CYGWIN__)
#include "windows.h"
#else
#include "dirent.h"
#endif

#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

void replay_catalyst_initialize(const std::string& node_dir, int num_ranks, int rank)
{
  conduit_cpp::Node params;
  std::stringstream node_path;
  node_path << node_dir << "initialize_params.conduit_bin"
            << "." << num_ranks << "." << rank;

  conduit_node_load(params.c_node, node_path.str().c_str(), "conduit_bin");

  catalyst_initialize(params.c_node);
}

void replay_catalyst_execute(
  const std::string& node_dir, int num_ranks, int rank, unsigned long num_execute_invoc_per_rank)
{
  for (unsigned long i = 0; i < num_execute_invoc_per_rank; i++)
  {
    conduit_cpp::Node params;
    std::stringstream node_path;
    node_path << node_dir << "execute_invc" << i << "_params.conduit_bin"
              << "." << num_ranks << "." << rank;

    conduit_node_load(params.c_node, node_path.str().c_str(), "conduit_bin");

    catalyst_execute(params.c_node);
  }
}

void replay_catalyst_finalize(const std::string& node_dir, int num_ranks, int rank)
{
  conduit_cpp::Node params;
  std::stringstream node_path;
  node_path << node_dir << "finalize_params.conduit_bin"
            << "." << num_ranks << "." << rank;

  conduit_node_load(params.c_node, node_path.str().c_str(), "conduit_bin");

  catalyst_finalize(params.c_node);
}

// Write out the number of node files for the
// initialize, execute, and finalize stages to a stringstream.
// These values are included when a related exception is thrown.
void write_num_nodes_per_stage(
  std::stringstream& ss, unsigned num_initialize, unsigned num_execute, unsigned num_finalize)
{
  ss << "Number of node files for initialization stage: " << num_initialize << std::endl
     << "Number of node files for execute stage: " << num_execute << std::endl
     << "Number of node files for finalize stage: " << num_finalize << std::endl;
}

// Parses relevant data from the filename passed in using regex matching.
void parse_fname(const std::regex& fname_patterns, const std::string& fname, int num_ranks,
  unsigned& num_initialize, unsigned& num_execute, unsigned& num_finalize,
  unsigned long& num_execute_invoc_per_rank)
{
  std::smatch matches;
  std::string d_name_str(fname);
  std::regex_search(d_name_str, matches, fname_patterns);

  if (matches.size() != 5)
  {
    return;
  }

  // Check that we get the expected number of ranks
  unsigned num_ranks_retrieved = 0;
  std::stringstream(matches[4]) >> num_ranks_retrieved;

  // Error if the number of ranks aren't equal.
  if (num_ranks_retrieved != num_ranks)
  {
    std::stringstream msg;
    msg << "Catalyst replayer was run with " << num_ranks << " ranks. Simulation was run with "
        << num_ranks_retrieved << " ranks. These should match.";
    throw std::runtime_error(msg.str());
  }

  // Check to see if we called execute. If we did, check if this is
  // the highest invocation number so far, so we know how many calls
  // we make.
  if (matches[3].length())
  {
    unsigned long execute_invc_num;
    std::stringstream(matches[3]) >> execute_invc_num;

    if (execute_invc_num + 1 > num_execute_invoc_per_rank)
      num_execute_invoc_per_rank = execute_invc_num + 1;
  }

  std::string stage = matches[1];

  if (stage == "initialize")
    num_initialize++;

  else if (stage == "execute")
    num_execute++;

  else if (stage == "finalize")
    num_finalize++;
}

#if defined(_WIN32) && !defined(__CYGWIN__)
// Windows implementation. Loops through each file in the data dump directory
// and calls parse_fname to extract the relevant data from the filename. This
// includes things like the number of ranks that were used, which stage the
// data is from, etc.
void parse_directory(const std::string& catalyst_data_dump_directory,
  const std::regex& fname_patterns, int num_ranks, unsigned& num_initialize, unsigned& num_execute,
  unsigned& num_finalize, unsigned long& num_execute_invoc_per_rank)
{
  WIN32_FIND_DATA ffd;
  HANDLE hFind = INVALID_HANDLE_VALUE;

  hFind = FindFirstFile(catalyst_data_dump_directory.c_str(), &ffd);

  if (hFind == INVALID_HANDLE_VALUE)
  {
    std::stringstream msg;
    msg << "Error opening directory " << catalyst_data_dump_directory;
    throw std::runtime_error(msg.str());
  }

  do
  {
    if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
    {
      parse_fname(fname_patterns, ffd.cFileName, num_ranks, num_initialize, num_execute,
        num_finalize, num_execute_invoc_per_rank);
    }
  } while (FindNextFile(hFind, &ffd) != 0);
  FindClose(hFind);
}

#else
// POSIX implementation. See above for documentation.
void parse_directory(const std::string& catalyst_data_dump_directory,
  const std::regex& fname_patterns, int num_ranks, unsigned& num_initialize, unsigned& num_execute,
  unsigned& num_finalize, unsigned long& num_execute_invoc_per_rank)
{
  DIR* dir = opendir(catalyst_data_dump_directory.c_str());
  if (!dir)
  {
    std::stringstream msg;
    msg << "Error opening directory " << catalyst_data_dump_directory;
    throw std::runtime_error(msg.str());
  }

  for (dirent* item = readdir(dir); item; item = readdir(dir))
  {
    parse_fname(fname_patterns, item->d_name, num_ranks, num_initialize, num_execute, num_finalize,
      num_execute_invoc_per_rank);
  }

  closedir(dir);
}
#endif

// Opens the data dump directory and makes sure that the data
// was output correctly. This includes things like making sure that
// there was the correct number of files written out for each stage.
void validate_data_dump(const std::string& catalyst_data_dump_directory, int num_ranks,
  unsigned long& num_execute_invoc_per_rank)
{
  // First check that all files in this directory were generated
  // with same number of ranks. Note that these are the TOTAL number of
  // calls to a certain API function. This includes calls across
  // ranks and timesteps.
  unsigned num_initialize = 0;
  unsigned num_execute = 0;
  unsigned num_finalize = 0;
  const std::regex fname_patterns(
    "^(initialize|execute|finalize)(_invc([0-9])*)?_params\\.conduit_bin\\.([0-9])+\\.[0-9]+$");

  parse_directory(catalyst_data_dump_directory, fname_patterns, num_ranks, num_initialize,
    num_execute, num_finalize, num_execute_invoc_per_rank);

  // Check that none are 0
  if (!(num_initialize && num_execute && num_finalize))
  {
    std::stringstream msg;
    msg << "Missing node data for at least one stage." << std::endl;
    write_num_nodes_per_stage(msg, num_initialize, num_execute, num_finalize);
    throw std::runtime_error(msg.str());
  }

  // Check that they're called the correct number of times.
  // Initialize and finalize should be called once per rank
  if (!(num_ranks == num_initialize && num_ranks == num_finalize))
  {
    std::stringstream msg;
    msg << "ERROR: Number of calls to initialize: " << num_initialize << std::endl
        << "Number of calls to finalize: " << num_finalize << std::endl
        << "Number of ranks: " << num_ranks << std::endl
        << "These should all match." << std::endl;
    throw std::runtime_error(msg.str());
  }

  // Execute is different since there are timesteps.
  if (num_execute != num_ranks * num_execute_invoc_per_rank)
  {
    std::stringstream msg;
    msg << "ERROR: Unexpected number of calls to execute." << std::endl
        << "Expected: " << num_ranks * num_execute_invoc_per_rank << std::endl
        << "Got: " << num_execute << std::endl;
    throw std::runtime_error(msg.str());
  }
}

int main(int argc, char** argv)
{
  MPI_Init(&argc, &argv);

  int num_ranks = 1;
  int rank = 0;

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &num_ranks);

  if (argc != 2)
  {
    throw std::runtime_error("Expected 1 argument");
  }

  std::string catalyst_data_dump_directory(argv[1]);

  unsigned long num_execute_invoc_per_rank = 0;
  validate_data_dump(catalyst_data_dump_directory, num_ranks, num_execute_invoc_per_rank);

  replay_catalyst_initialize(catalyst_data_dump_directory, num_ranks, rank);
  replay_catalyst_execute(
    catalyst_data_dump_directory, num_ranks, rank, num_execute_invoc_per_rank);
  replay_catalyst_finalize(catalyst_data_dump_directory, num_ranks, rank);

  MPI_Finalize();

  return 0;
}
