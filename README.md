# SPLIB2

This is my library, it has anything I decided to throw in it.

This is NOT a replacement for STL, nor is it trying to be. That said, it does not use STL, though we do use stdlib functions for printf (and its cousins) as well as malloc/free/realloc, unless specific overloads for those are provided (see `SPLib.hpp`).

To build, on Linux at least, you just need to clone the repository recursively, go into the libressl submodule and run autogen.sh, then you can use cmake to build as usual. You can turn the tests off by disabling `SPLIB_BUILD_TESTS`

If you are on a platform where you cannot run autogen.sh, delete the libressl directory and replace it with the contents of a source distribution tarball you got from https://www.libressl.org/

This is designed to be included as a submodule in other projects. For an example on how to link against it from other targets, check splib2_tests/CMakeLists.txt
