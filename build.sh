#!/bin/bash

cleanArtifacts ()
{
    rm -rf CMakeFiles/
    rm CMakeCache.txt
    rm build.ninja
    rm cmake_install.cmake
    rm .ninja_deps
    rm .ninja_log
    rm build.ninja
    rm libNimCWNative.dll.a
}

# Clean up any existing build artifacts
echo "Cleaning existing build artifacts..."
cleanArtifacts()

# Run CMake to configure the build
echo "Running CMake..."
cmake -G "Ninja" .

# Build the project using Ninja
echo "Building project with Ninja..."
ninja -j 20

# Clean up CMake build artifacts
echo "Cleaning CMake build artifacts..."
cleanArtifacts()

echo "Build complete."

