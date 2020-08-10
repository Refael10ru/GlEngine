#pragma once 

#define FILEIO_H

#include <stdio.h>
#include <stdlib.h>
#include "defaultmacro.h"

namespace GLEngine
{
	class FileIO
	{
	public:
		static bool Write(char*, char*);	//	writes data to the provided file	

		static char* ReadData(char*);	//	reads data from a file
	};
}