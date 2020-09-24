#pragma once

#define EXCEPTIONS_H 

#include <exception>
#include <cstring>
#include "gltypes.h"
#include "Debug.h"
#include "globals.h"

namespace GLEngine
{
	class GLException : public std::exception	// Base exception class
	{
	public:
		String Message;	// Stores the exception message

		virtual void LogExceptionMessage();  // Outputs the log message to the console

		GLException() : Message(nullptr)
		{
		}

		GLException(String message) : Message(Message)
		{
		}
	};

	class LibraryInitializationError : public GLException
	{
	public:
		String Title; 

		void LogExceptionMessage() override;

		LibraryInitializationError(String libname) : GLException()
		{
			this->Title = strcat(strcat(new char[100], libname), " failed to initialize. "); 
		}		
	}; 

	class FileNotFoundException : public GLException
	{	
	public:
		void LogExceptionMessage() override;
		
		FileNotFoundException()
		{
			this->Message = strcat(new char[100], "File was not found in the provided path.");
		}
	}; 

	class GLEInvalidShaderException : public GLException	//	Thrown when shader class initialization is incomplete or any of its properties have invalid values
	{
	public:
		void LogExceptionMessage() override;
		
		GLEInvalidShaderException() 
		{
			this->Message = strcat(new char[100], "The shader instance is invalid. ");
		}
	};
	
	class GLInvalidTypeException : public GLException	//	Thrown when shader class initialization is incomplete or any of its properties have invalid values
	{
	public:
		void LogExceptionMessage() override;
		
		GLInvalidTypeException() 
		{
			this->Message = strcat(new char[100], "The provided type is invalid. ");
		}
	};
}