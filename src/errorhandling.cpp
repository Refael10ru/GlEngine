#include "errorhandling.h"

namespace GLEngine
{
	void ErrorHandler::LogError(char* message)
	{
		printf("Error: %s", message);
	}

	void ErrorHandler::LogError(char* message, bool IsWarning)
	{
		printf("\n%s: %s", (IsWarning) ? "Warning" : "Error", message);
	}

	void ErrorHandler::LogError(char* message, ErrorHandler::ErrorType errorType)
	{
		char** ErrorStrings = new char*[2] {
			"Error", 
			"Warning"
		};

		printf("\n%s: %s", ErrorStrings[(int)errorType], message);
	}
	
	void ErrorHandler::CheckErrors(unsigned int bufferID, GLenum glProcessType)
	{
		int processSuccess; 

		char Logs[512];

		switch (glProcessType)
		{
			case GL_COMPILE_STATUS:	
				glGetShaderiv(bufferID, glProcessType, &processSuccess);

				if (!processSuccess)
				{
					glGetShaderInfoLog(bufferID, sizeof(Logs), NULL, Logs);

					ErrorHandler::LogError(Logs);
				}	
		
			case GL_LINK_STATUS:
				glGetShaderiv(bufferID, glProcessType, &processSuccess);

				if (!processSuccess)
				{
					glGetProgramInfoLog(bufferID, sizeof(Logs), NULL, Logs);

					ErrorHandler::LogError(Logs);
				}

			default:
				LogError("Invalid process type.");
		}
	}
}