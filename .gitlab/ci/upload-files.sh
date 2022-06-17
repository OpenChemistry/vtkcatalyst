#!/bin/sh

set -e

readonly urlbase="${CI_API_V4_URL}/projects/${CI_PROJECT_ID}"

upload_file () {
    file="$1"
    shift

    curl --header "JOB-TOKEN: ${CI_JOB_TOKEN}" \
        --upload-file "$file" \
        "$urlbase/packages/generic/catalyst/${CI_COMMIT_TAG}/$upload_file"
}

for file_to_upload in $UPLOAD_FILES; do
    upload_file "$file_to_upload"
done
