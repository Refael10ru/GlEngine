#include "Debug.h"

void DebugTools::Debugger::StartConsole()
{
	std::cout << UITools::ReplicateChar(' ', 50) << this->Title << "\n" 
		<< UITools::ReplicateChar('-', (50 * 2) + this->Title.size()) << '\n'; 
}

void  DebugTools::Debugger::Log(char* message)
{
	std::cout << "\nDebug " << this->LogCount++ << ": " << message << '\n';
}

void DebugTools::Debugger::Log(char** messages, int size)
{
	for (int x = 0; x < size; x++)
		std::cout << "\nDebug " << this->LogCount++ << ": " << messages[x] << '\n';
}
