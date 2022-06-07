cmake_minimum_required(VERSION 3.13)

execute_process(
  COMMAND "${dumpbin}" /EXPORTS "${library}"
  OUTPUT_VARIABLE out
  ERROR_VARIABLE err
  RESULT_VARIABLE res
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_STRIP_TRAILING_WHITESPACE)

if (res)
  message(FATAL_ERROR
    "Failed to extract symbols: ${res}")
endif ()

set(symbol_names)

set(state START)

string(REPLACE "\n" ";" symbol_lines "${out}")
foreach (symbol_line IN LISTS symbol_lines)
  if (state STREQUAL "START")
    if (symbol_line STREQUAL "    ordinal hint RVA      name")
      set(state "SYMBOL_HEADER")
    endif ()
    continue ()
  endif ()
  if (state STREQUAL "SYMBOL_HEADER")
    # An empty line separates the header from the symbol table..
    if (symbol_line STREQUAL "")
      set(state "SYMBOLS")
      continue ()
    endif ()
  endif ()
  if (state STREQUAL "SYMBOLS")
    # An empty line ends the symbol table.
    if (symbol_line STREQUAL "")
      break ()
    endif ()
  endif ()

  string(REGEX REPLACE " +" ";" symbol_line "${symbol_line}")

  list(GET symbol_line 4 name)
  list(APPEND symbol_names "${name}")
endforeach ()

if (NOT symbol_names)
  message(FATAL_ERROR
    "No public symbols found in ${library}")
endif ()

list(SORT symbol_names)

# Read the list of expected symbols.
file(STRINGS "${symbols}" expected)
list(REMOVE_ITEM expected "")
list(SORT expected)

set(unexpected "${symbol_names}")
list(REMOVE_ITEM unexpected ${expected})

if (unexpected)
  string(REPLACE ";" ", " unexpected_text "${unexpected}")
  message(SEND_ERROR
    "Unexpected symbols found: ${unexpected_text}")
endif ()

set(missing "${expected}")
list(REMOVE_ITEM missing ${symbol_names})

if (missing)
  string(REPLACE ";" ", " missing_text "${missing}")
  message(SEND_ERROR
    "Missing symbols not found: ${missing_text}")
endif ()
