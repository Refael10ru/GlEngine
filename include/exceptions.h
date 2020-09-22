#pragma once

#define EXCEPTIONS_H 

#include <exception>
#include <cstring>
#include "gltypes.h"

namespace GLEngine
{
	class GLException : public std::exception	// Base exception class
	{
	public:
		String Message;	// Stores the exception message

		GLException() : Message(nullptr)
		{
		}

		GLException(String message) : Message(Message)
		{
		}
	};

	class FileNotFoundException : public GLException
	{	
	public:
		FileNotFoundException()
		{
			this->Message = strcat(new char[100], "File was not found in the provided path.");
		}
	}; 

	class GLEInvalidShaderException : public GLException	//	Thrown when shader class initialization is incomplete or any of its properties have invalid values
	{
	public:
		GLEInvalidShaderException() 
		{
			this->Message = strcat(new char[100], "The shader instance is invalid. ");
		}
	};
	
	class GLInvalidTypeException : public GLException	//	Thrown when shader class initialization is incomplete or any of its properties have invalid values
	{
	public:
		GLInvalidTypeException() 
		{
			this->Message = strcat(new char[100], "The provided type is invalid. ");
		}
	};
}