## Dynamically load Catalyst implmentations

The `catalyst` library is now an actual library rather than an interface.
Implementations will need to provide a structure with a specific name, though
the CMake API for creating a Catalyst implementation will do this
automatically.

To select an implementation, the `catalyst_load/implementation` and
`catalyst_load/search_paths/*` settings passed into `catalyst_initialize` are
used to select and find the implementation library and load it.

  - All Catalyst API functions now return an error code. This is primarily to
    allow `catalyst_initialize` to return the status of the backing
    implementation.
  - There is now a structure containing the functions that are needed for
    Catalyst.
