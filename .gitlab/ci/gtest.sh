#!/bin/sh

set -e

readonly version="1.10.0"
readonly TARBALL="release-$version.tar.gz"
readonly TARGET="googletest-release-$version"

cd .gitlab

curl -OL "https://github.com/google/googletest/archive/$TARBALL"
cmake -E tar xf "$TARBALL"
cd "$TARGET"
mkdir build
cd build
cmake .. -DBUILD_GMOCK=OFF -Dgtest_disable_pthreads=ON
cmake --build .
cmake --build . --target install
