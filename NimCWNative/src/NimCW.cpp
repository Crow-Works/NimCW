#include "NimCW.h"
#include <cstdarg>
#ifdef NIMCW_PLATFORM_WINDOWS
#include <Windows.h>
#else
#include <dlfcn.h>
#endif

void NimCWInit(const char* libraryPath) {}

void NimShutdown(NimHandle& nimHandle)
{
#ifdef NIMCW_PLATFORM_WINDOWS
	FreeLibrary((HMODULE) nimHandle);
#else
	dlclose(nimHandle);
#endif
	nimHandle = nullptr;
}

void* LoadNimLibrary(const char* libraryPath)
{
#ifdef NIMCW_PLATFORM_WINDOWS
	return (void*) LoadLibraryA(libraryPath);
#else
	return dlopen(libraryPath, RTLD_LAZY);
#endif // NIMCW_PLATFORM_WINDOWS
}

NimFunction GetNimFunction(void* nimHandle, const char* functionName)
{
#ifdef NIMCW_PLATFORM_WINDOWS
	return (NimFunction) GetProcAddress((HMODULE) nimHandle, functionName);
#else
	return (NimFunction) dlsym(nimHandle, functionName);
#endif // NIMCW_PLATFORM_WINDOWS
}

void InvokeNimFunction(NimFunction nimFunction)
{
	if (nimFunction)
	{
		nimFunction();
	}
}

void AddInternalCall(const char* functionName, const void* function)
{
	// TODO: Register function in C++
	// Add functionality to register same function in Nim
	// When function called from Nim, make call into C++
}
