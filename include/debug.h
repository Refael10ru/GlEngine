#pragma once

#define DEBUG_H 

#include <stdio.h>
#include <cstring>

namespace GLEngine
{
	inline int DebugCallIndex = 0; //   stores the number of debug calls.
   
	class Debug
	{
	public:

		static void ResetIndex();

		static void Log(char*); // prints the provided message to the console

		static void Log(char*, bool);    // prints the provided message to the console with current call index
	};
};