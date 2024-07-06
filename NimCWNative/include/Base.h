#pragma once

#ifdef _WIN32
#ifdef _WIN64
#define NIMCW_PLATFORM_WINDOWS
#else
#error "x86 builds are not supported!"
#endif
#elif defined(__linux__)
#define NIMCW_PLATFORM_LINUX
#elif defined(__APPLE__)
#define NIMCW_PLATFORM_MAC
#else
#error "Unknown Platform"
#endif

#ifdef NIMCW_BUILD_DLL
#ifdef NIMCW_PLATFORM_WINDOWS
#define NIMCW_API __declspec(dllexport)
#else
##define NIMCW_API __attribute__((visibility("default")))
#endif // NIMCW_PLATFORM_WINDOWS
#else
#define NIMCW_API
#endif
