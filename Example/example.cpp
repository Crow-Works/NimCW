#include <NimCW.h>
#include <iostream>

#ifdef NIMCW_PLATFORM_WINDOWS
#include <Windows.h>
#else
#include <dlfcn.h>
#endif

void NativeLog(const char* msg)
{
	std::cout << "[C++]: " << msg << std::endl;
}

int main(void)
{
	const char* nimLibraryPath = "NimScripts.dll";

	NimHandle nimHandle = LoadNimLibrary(nimLibraryPath);
	if (!nimHandle)
	{
		std::cerr << "Failed to load Nim library" << std::endl;
		return -1;
	}
	else
	{
		std::cout << "Nim library loaded successfully" << std::endl;
	}

	AddInternalCall("NativeLog", reinterpret_cast<void*>(NativeLog));

	// Get the Nim function without parameters
	NimFunction helloFromNimNoParams = GetNimFunction(nimHandle, "HelloFromNimNoParams");
	if (!helloFromNimNoParams)
	{
		std::cerr << "Failed to find Nim function: HelloFromNimNoParams" << std::endl;
	}
	else
	{
		// Call the Nim function without parameters
		InvokeNimFunction(helloFromNimNoParams);
	}
	NimShutdown(nimHandle);

	return 0;
}
