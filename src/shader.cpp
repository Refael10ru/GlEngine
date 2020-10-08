#include "shader.h"
#include "exceptions.h"

GLenum* GLEngine::ShaderTypeGLenums = new GLenum[2] {
	GL_VERTEX_SHADER, 
	GL_FRAGMENT_SHADER
};  

bool GLEngine::Shader::Verify()
{
	bool Validity = true;	
	
	for (int x = 0; x < 2; x++)	
		if (this->ShaderIDs[x] == NULL || this->ShaderProgramStrings.at(x) == nullptr)	
			Validity = !Validity;

	return Validity; 
}

unsigned int* GLEngine::Shader::Compile()
{
	try
	{	
		if (!this->Verify())	//	Shader validation
			throw new GLEngine::GLEInvalidShaderException();
	}
	catch(GLEngine::GLEInvalidShaderException* e)
	{
		e->LogExceptionMessage();		
		return nullptr;
	}

	unsigned int* Shaders = new unsigned int[2] {
		glCreateShader(GL_VERTEX_SHADER),
		glCreateShader(GL_FRAGMENT_SHADER)
	}; 

	for (int x = 0; x < 2; x++)
	{
		glShaderSource(Shaders[x], 1, &this->ShaderProgramStrings.at(x), NULL);
		glCompileShader(Shaders[x]);

		this->CheckErrors(Shaders[x], GL_COMPILE_STATUS);
	}

	return (this->ShaderIDs = Shaders);
}

unsigned int GLEngine::Shader::Link()
{	
	unsigned int LinkedProgram = glCreateProgram();

	for (int x= 0; x < 2; x++)
		glAttachShader(LinkedProgram, this->ShaderIDs[x]);
	
	glLinkProgram(LinkedProgram);

	this->CheckErrors(LinkedProgram, GL_LINK_STATUS);	//	checks for linking errors

	return (this->ShaderProgramID = LinkedProgram); 
}

void GLEngine::Shader::CheckErrors(unsigned int program, GLenum glStatus)
{	
	int success;	//	complie/link status

	char* GLCompilerLog = new char[512]; 

	switch (glStatus)
	{
		case GL_COMPILE_STATUS:	
			glGetShaderiv(program, glStatus, &success);

			try
	 		{
				if (!success) 
					glGetShaderInfoLog(ShaderProgramID, 512, NULL, GLCompilerLog);

				throw new GLEngine::GLEInvalidShaderException(GLCompilerLog); 
			}
			catch (GLEngine::GLEInvalidShaderException* e)
			{	
				e->LogExceptionMessage(); 
				
				Debug->Log(GLCompilerLog); 
			}

			break;

		case GL_LINK_STATUS:
			glGetProgramiv(program, glStatus, &success);

			try
			{
				if (!success) 
				{
					glGetProgramInfoLog(ShaderProgramID, 512, NULL, GLCompilerLog);
				}
			}
			catch (const GLEngine::GLEInvalidShaderException& e)
			{	
				Debug->Log(GLCompilerLog);
			}

			break;
	}
}