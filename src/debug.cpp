#include "debug.h"

namespace GLEngine
{
	void Debug::Log(char* message)
	{
		char* nullMessage = "Debug logger called. ";

		if (message == nullptr)
			printf("\n%s", nullMessage);
		else
			printf("\nDebug: %s", message); 
	}
	
	void Debug::Log(char* message, bool call)
	{
		char* nullMessage = "Debug logger called. ";

		if (message == nullptr)
			printf("\n%s", nullMessage);
		else
			printf("\nDebug %d: %s", (call) ? DebugCallIndex : NULL, message); 

		DebugCallIndex += (int)(call); 
	}

	void Debug::ResetIndex()
	{
	   DebugCallIndex = 0; 
	}
}