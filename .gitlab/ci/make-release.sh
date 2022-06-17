#!/bin/sh

set -e

make_release () {
    exec release-cli create --name "Catalyst $CI_COMMIT_TAG" --tag-name "$CI_COMMIT_TAG" "$@"
}

readonly urlbase="${CI_API_V4_URL}/projects/${CI_PROJECT_ID}/packages/generic/catalyst/${CI_COMMIT_TAG}"

assets=""
case "$CI_COMMIT_TAG" in
    v*)
        # Asset discovery.
        readonly source_gz_tarball="$( ls catalyst-*.tar.gz )"
        readonly source_zip_tarball="$( ls catalyst-*.zip )"

        make_release \
            --assets-link "{\"name\":\"$CI_COMMIT_TAG source .tar.gz\",\"url\":\"$urlbase/$source_gz_tarball\"}" \
            --assets-link "{\"name\":\"$CI_COMMIT_TAG source .zip\",\"url\":\"$urlbase/$source_zip_tarball\"}"
        ;;
    *)
        echo >&2 "Unknown release artifact set."
        exit 1
esac
