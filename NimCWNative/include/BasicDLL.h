#pragma once

#if defined _WIN32 || defined __CYGWIN__
#ifdef EXAMPLE_EXPORTS
#ifdef __GNUC__
#define EXAMPLE_API __attribute__((dllexport))
#else
#define EXAMPLE_API __declspec(dllexport)
#endif
#else
#ifdef __GNUC__
#define EXAMPLE_API __attribute__((dllimport))
#else
#define EXAMPLE_API __declspec(dllimport)
#endif
#endif
#else
#if __GNUC__ >= 4
#define EXAMPLE_API __attribute__((visibility("default")))
#else
#define EXAMPLE_API
#endif
#endif

extern "C"
{
	EXAMPLE_API int addNumbers(int a, int b);
}
