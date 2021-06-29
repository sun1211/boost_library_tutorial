# Boost C++ Application Libraries Tutorial
Boost is a collection of C++ libraries. Each library has been reviewed by many professional programmers before being accepted by Boost. Libraries are tested on multiple platforms using many compilers and many C++ standard library implementations. While using Boost, you can be sure that you are using one of the most portable, fast, and reliable solutions that is distributed under a license suitable for commercial and open source projects.

## Setup environment
**1. Install CMake**
```
cd ~
wget https://github.com/Kitware/CMake/releases/download/v3.14.5/cmake-3.14.5.tar.gz
tar xf cmake-3.14.5.tar.gz
cd cmake-3.14.5
./bootstrap --parallel=10
make -j4
sudo make -j4 install
```
**2. Install Boost**
```
cd ~
wget https://dl.bintray.com/boostorg/release/1.70.0/source/boost_1_70_0.tar.gz
tar xf boost_1_70_0.tar.gz
cd boost_1_70_0
./bootstrap.sh
./b2 ... cxxflags="-std=c++0x -stdlib=libc++" linkflags="-stdlib=libc++" ...
sudo ./b2 toolset=gcc -j4 install`
```
## Table of contents

### [Chapter 1:](chapter_01/README.md)

- [1. Program with option base](chapter_01/recipe_01/README.md)
- [2. Program with option short](chapter_01/recipe_02/README.md)
- [3. Storing any value in a container/variable with any](chapter_01/recipe_03/README.md)
- [4. Storing multiple chosen types in a container/variable](chapter_01/recipe_04/README.md)
- [5. Using a safer way to work with a container that stores multiple chosen types with Boost.any](chapter_01/recipe_05/README.md)
- [6. Using a safer way to work with a container that stores multiple chosen types with Boost.Variant](chapter_01/recipe_06/README.md)
- [7. Returning a value or flag where there is no value with Boost.Optional](chapter_01/recipe_07/README.md)
- [8. Returning an array from a function with Boost.array](chapter_01/recipe_08/README.md)

