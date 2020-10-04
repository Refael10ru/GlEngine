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
		virtual void LogExceptionMessage() override;
		
		GLEInvalidShaderException() 
		{
			// this->Message = strcpy(new char[100], "The shader instance is invalid. ");
		}

		GLEInvalidShaderException(String message) 
		{
			this->Message = message;
		}
	};

	class GLENullShaderStringsException : public GLEInvalidShaderException
	{	
	public:
		enum ShaderStringType
		{
			VertexShaderString,
			FragmentShaderString		
		};

		void LogExceptionMessage() override;

		GLENullShaderStringsException()
		{
			this->Message = strcat(new char[100], "One of the shader strings are null.");	
		}

		GLENullShaderStringsException(GLENullShaderStringsException::ShaderStringType  shaderStringType)
		{
			this->Message = nullptr;

			String* ShaderTypeStrings = new String[2] {
				"Vertex Shader Stirng", 
				"Fragment Shader Stirng"
			}; 

			if ((int)shaderStringType <= 1 || (int)shaderStringType >= 0)
				this->Message = strcat(strcat(strcat(new char[100], "The "), ShaderTypeStrings[(int)shaderStringType]), "is null.");   
			else
				this->Message = strcat(new char[100], "One of th  shader strings are null.");						
		}
	};

	class GLEUncompiledShaderException : public GLEInvalidShaderException
	{
	public:
		void LogExceptionMessage() override;

		GLEUncompiledShaderException()
		{
			this->Message = strcat(new char[100], "One of the shaders are uncompiled. ");
		}
	};

	class GLEInvalidTypeException : public GLException	//	Thrown when shader class initialization is incomplete or any of its properties have invalid values
	{
	public:
		void LogExceptionMessage() override;
		
		GLEInvalidTypeException() 
		{
			this->Message = strcat(new char[100], "The provided type is invalid. ");
		}

		GLEInvalidTypeException(String objectName) 
		{
			this->Message = strcat(strcat(strcat(new char[100], "The provided"), objectName), " type is invalid. ");
		}
	};
}
