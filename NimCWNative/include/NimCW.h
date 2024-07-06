#pragma once

#include "Base.h"
#include <tuple>

typedef void (*NimFunction)(void);
typedef void* NimHandle;

// Initialize the NimCW library
extern "C" NIMCW_API void NimCWInit(const char* libraryPath);

// Shutdown the NimCW library
extern "C" NIMCW_API void NimShutdown(NimHandle& nimHandle);

// Load a Nim dll
extern "C" NIMCW_API void* LoadNimLibrary(const char* libraryPath);

// Get the function pointer of a Nim function from the DLL using its name
extern "C" NIMCW_API NimFunction GetNimFunction(NimHandle nimHandle, const char* functionName);

// Invoke a function inside of Nim
extern "C" NIMCW_API void InvokeNimFunction(NimFunction nimFunction);

extern "C" NIMCW_API void AddInternalCall(const char* functionName, const void* function);
