/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */

#ifndef catalyst_dump_node_h
#define catalyst_dump_node_h

#include "mpi.h"
#include <string.h>

// Constructs the absolute path of the file to write out.
// Similar to python's os.path.join.
char* construct_full_path(
  const char* out_dir, const char* stage, unsigned long invocations, int use_invocations)
{
  int num_ranks = 1;
  int rank = 0;

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &num_ranks);

  size_t full_path_len = 0;
  char* full_path = NULL;

  if (use_invocations)
  {
    full_path_len = snprintf(NULL, 0, "%s%s_invc%lu_params.conduit_bin.%d.%d", out_dir, stage,
      invocations, num_ranks, rank);

    full_path = (char*)calloc(full_path_len + 1, sizeof(char));
    snprintf(full_path, full_path_len + 1, "%s%s_invc%lu_params.conduit_bin.%d.%d", out_dir, stage,
      invocations, num_ranks, rank);
  }
  else
  {
    full_path_len =
      snprintf(NULL, 0, "%s%s_params.conduit_bin.%d.%d", out_dir, stage, num_ranks, rank);

    full_path = (char*)calloc(full_path_len + 1, sizeof(char));
    snprintf(full_path, full_path_len + 1, "%s%s_params.conduit_bin.%d.%d", out_dir, stage,
      num_ranks, rank);
  }

  if (!(full_path_len && full_path))
  {
    fprintf(stderr, "Invalid dump_node filename convention.\n");
    exit(1);
  }

  return full_path;
}

// Check if a data dump directory has been set. If it has,
// write out the params argument to disk to load later.
void dump_node(
  const conduit_node* params, const char* stage, unsigned long invocations, int use_invocations)
{
  if (const char* out_dir = getenv("CATALYST_DATA_DUMP_DIRECTORY"))
  {
    char* full_path = construct_full_path(out_dir, stage, invocations, use_invocations);
    conduit_node_save(const_cast<conduit_node*>(params), full_path, "conduit_bin");
    free(full_path);
  }
}

#endif
