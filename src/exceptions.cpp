#include "exceptions.h"


void GLEngine::GLException::LogExceptionMessage()
{
	Debug->Log(this->Message);	//	Logs the error message 
}

void GLEngine::FileNotFoundException::LogExceptionMessage()
{	
	GLException::LogExceptionMessage();	//	Logs the error message 
}

void GLEngine::GLEInvalidTypeException::LogExceptionMessage()
{	
	GLException::LogExceptionMessage();	//	Logs the error message 
}

void GLEngine::GLEInvalidShaderException::LogExceptionMessage()
{	
	GLException::LogExceptionMessage();	//	Logs the error message 
}

void GLEngine::LibraryInitializationError::LogExceptionMessage()
{
	GLException::LogExceptionMessage();	//	Logs the error message 
}

void GLEngine::GLENullShaderStringsException::LogExceptionMessage()
{
	GLException::LogExceptionMessage();	//	Logs the error message 
}

void GLEngine::GLEUncompiledShaderException::LogExceptionMessage()
{
	GLException::LogExceptionMessage();	//	Logs the error message 
}
