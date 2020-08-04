#!/usr/bin/env bash

set -e
set -x
shopt -s dotglob

readonly name="conduit"
readonly ownership="Conduit Upstream <kwrobot@kitware.com>"
readonly subtree="thirdparty/$name"
readonly repo="https://gitlab.kitware.com/third-party/conduit.git"
readonly tag="for/catalyst-20200817-v0.5.1"
readonly paths="
COPYRIGHT
.gitattributes
LICENSE
README.md
src/cmake/CMakeBasics.cmake
src/cmake/BasicTypeChecks.cmake
src/libs/conduit/CMakeLists.catalyst.txt
src/libs/conduit/c/*.cpp
src/libs/conduit/c/*.h
src/libs/conduit/c/*.hpp
src/libs/conduit/cmake/BitwidthMapping.cmake
src/libs/conduit/cmake/cmake_cxx11_check_if_long_long_is_std_int64.cpp
src/libs/conduit/*.cpp
src/libs/conduit/*.hpp
src/libs/conduit/*.h
src/libs/conduit/*.h.in
src/libs/conduit/fortran/*.*
src/thirdparty_builtin/libb64-1.2.1/README
src/thirdparty_builtin/libb64-1.2.1/LICENSE
src/thirdparty_builtin/libb64-1.2.1/AUTHORS
src/thirdparty_builtin/libb64-1.2.1/CMakeLists.catalyst.txt
src/thirdparty_builtin/libb64-1.2.1/include
src/thirdparty_builtin/libb64-1.2.1/src/*.cpp
src/thirdparty_builtin/libyaml-690a781
src/thirdparty_builtin/rapidjson
"

extract_source () {
    git_archive
    # Everything is under an extra src/libs/conduit/ directory; remove it
    # while preserving some files from the top level directory

    mv "$extractdir/$name-reduced/src/libs/conduit/"* "$extractdir/$name-reduced/"
    mv "$extractdir/$name-reduced/src/cmake/"* "$extractdir/$name-reduced/cmake/"
    mv "$extractdir/$name-reduced/src/thirdparty_builtin/libb64-1.2.1" "$extractdir/$name-reduced/libb64"
    mv "$extractdir/$name-reduced/src/thirdparty_builtin/libyaml-690a781" "$extractdir/$name-reduced/libyaml"
    mv "$extractdir/$name-reduced/src/thirdparty_builtin/rapidjson" "$extractdir/$name-reduced/rapidjson"

    rmdir "$extractdir/$name-reduced/src/libs/conduit"
    rmdir "$extractdir/$name-reduced/src/libs"
    rmdir "$extractdir/$name-reduced/src/cmake"
    rmdir "$extractdir/$name-reduced/src"

    mv "$extractdir/$name-reduced/CMakeLists.catalyst.txt" "$extractdir/$name-reduced/CMakeLists.txt"
    mv "$extractdir/$name-reduced/libyaml/CMakeLists.catalyst.txt" "$extractdir/$name-reduced/libyaml/CMakeLists.txt"
    mv "$extractdir/$name-reduced/libb64/CMakeLists.catalyst.txt" "$extractdir/$name-reduced/libb64/CMakeLists.txt"
    mv "$extractdir/$name-reduced/rapidjson/CMakeLists.catalyst.txt" "$extractdir/$name-reduced/rapidjson/CMakeLists.txt"
}

. "${BASH_SOURCE%/*}/update-common.sh"
