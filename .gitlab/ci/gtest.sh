#!/bin/sh

set -e

readonly version="1.10.0"
readonly sha256sum="9dc9157a9a1551ec7a7e43daea9a694a0bb5fb8bec81235d8a1e6ef64c716dcb"
readonly tarball="release-$version.tar.gz"
readonly target="googletest-release-$version"

cd .gitlab

echo "$sha256sum  $tarball" > gtest.sha256sum
curl -OL "https://github.com/google/googletest/archive/$tarball"
sha256sum --check gtest.sha256sum

cmake -E tar xf "$tarball"
cd "$target"
mkdir build
cd build

cmake -GNinja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX="$GIT_CLONE_PATH/.gitlab/gtest" \
    -DBUILD_GMOCK=OFF \
    -Dgtest_disable_pthreads=ON \
    ..
cmake --build .
cmake --build . --target install
