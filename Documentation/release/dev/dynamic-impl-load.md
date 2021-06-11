## Dynamically load Catalyst implmentations

  - All Catalyst API functions now return an error code. This is primarily to
    allow `catalyst_initialize` to return the status of the backing
    implementation.
