@echo off

REM Dirty but it works lol

echo Cleaning existing build artifacts...
REM Check and delete CMakeFiles directory if it exists
if exist CMakeFiles (
    rd /s /q CMakeFiles
)

REM Check and delete individual files if they exist
if exist CMakeCache.txt (
    del CMakeCache.txt
)
if exist build.ninja (
    del build.ninja
)
if exist cmake_install.cmake (
    del cmake_install.cmake
)
if exist .ninja_deps (
    del .ninja_deps
)
if exist .ninja_log (
    del .ninja_log
)
if exist libNimCWNative.dll.a (
    del libNimCWNative.dll.a
)

REM Run CMake to configure the build
echo Running CMake...
cmake -G "Ninja" .

REM Build the project using Ninja
echo Building project with Ninja...
ninja -j 20

REM Clean up CMake build artifacts again after the build
echo Cleaning CMake build artifacts...
if exist CMakeFiles (
    rd /s /q CMakeFiles
)

REM Check and delete individual files if they exist
if exist CMakeCache.txt (
    del CMakeCache.txt
)
if exist build.ninja (
    del build.ninja
)
if exist cmake_install.cmake (
    del cmake_install.cmake
)
if exist .ninja_deps (
    del .ninja_deps
)
if exist .ninja_log (
    del .ninja_log
)
if exist libNimCWNative.dll.a (
    del libNimCWNative.dll.a
)

echo Build complete.

