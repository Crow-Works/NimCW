#include "BasicDLL.h"

extern "C"
{
	EXAMPLE_API int addNumbers(int a, int b)
	{
		return a + b;
	}
}
