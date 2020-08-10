/// 	Consists of all required error handling functions. 

#pragma once

#define ERRORHANDLING_H

#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include "globjects.h"

namespace GLEngine
{
	class ErrorHandler
	{
	public:
		enum ErrorType
		{
			Error, 
			Warning
		};
		
		static void LogError(char*, bool);	// prints 

		static void LogError(char*, ErrorHandler::ErrorType);
		
		static void LogError(char*);	//	logs the error message provided as a char 	
		
		static void CheckErrors(unsigned int, GLenum);	//	checks for errors in OpenGL processes (just shader compiling and linking right now) 
	};
}