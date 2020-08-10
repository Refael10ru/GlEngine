#include "globjects.h"

namespace GLEngine
{
	unsigned int GLETools::LinkShaders(std::vector<unsigned int> shaders)
	{
		unsigned int ShaderProgram = glCreateProgram();
					
		for (int x = 0; x < shaders.size(); x++)
			glAttachShader(ShaderProgram, shaders.at(x));

		glLinkProgram(ShaderProgram);

		ErrorHandler::CheckErrors(ShaderProgram, GL_LINK_STATUS);

		return ShaderProgram; 
	}

	void GLETools::DeleteShaders(std::vector<unsigned int> Shaders)
	{	
		for (int x = 0; x < Shaders.size(); x++)
			glDeleteShader(Shaders.at(x));
	}
	
	unsigned int GLETools::CreateShader(char* ShaderString, GLenum shaderType)
	{
		unsigned int shaderID = glCreateShader(shaderType);	

		glShaderSource(shaderID, 1, &ShaderString, NULL);

		return shaderID;  
	}

	unsigned int GLETools::CreateShader(char* ShaderString, GLenum shaderType, bool compile)
	{
		unsigned int shaderID = glCreateShader(shaderType);	

		glShaderSource(shaderID, 1, &ShaderString, NULL);

		if (compile)
		{
			glCompileShader(shaderID);

			ErrorHandler::CheckErrors(shaderID, GL_COMPILE_STATUS);
		}

		return shaderID;  
	}

	unsigned int GLETools::CreateObject(GLETools::GLEobject objectType)	//	alllocates the specified glObjcegt and returns it's ID
	{
		unsigned int ObjectID;

		switch (objectType)
		{
			case GLETools::VertexArray:
				glGenVertexArrays(1, &ObjectID);
				glBindVertexArray(ObjectID);
			
			case GLETools::VertexBuffer:
				glGenBuffers(GL_ARRAY_BUFFER, &ObjectID);
				glBindBuffer(GL_ARRAY_BUFFER, ObjectID);
		
			default:
				printf("Invalid GLEobject.");
				
				return -1; 
		}

		return ObjectID;
	}

	void GLETools::SetVertexAttributePointer(int size)
	{
		glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, size * sizeof(float), (void*)0);
	}

	void GLETools::ZeroBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	bool Shader::AttachString(char* shaderString, ShaderType shaderType)	// attached the shader string to the specified shader
	{	
		if (this->Shaders.at((int)shaderType) == NULL)
		{	
			ErrorHandler::LogError("Specified shader is not allocated. ");

			return false;
		}
		
		glShaderSource(this->Shaders.at((int)shaderType), 1, &shaderString, NULL);	

		return true;
	}

	bool Shader::Validate()
	{
		int ValidityCounter = 2;	//	2 just for shaderstrings rn.

		char* ShaderTypeStrings[] = {
			"Vertex Shader", 
			"Fragment Shader"
		};

		for (int x = 0; x <  2; x++)
			if (ShaderStrings[x] == nullptr)	
			{
				ErrorHandler::LogError(strcat(new char[MAX_STRING_SIZE], strcat(strcat(new char[100], ShaderTypeStrings[x]), " string is  null.")));

				ValidityCounter--; 
			}

		return (ValidityCounter >= 2);
	}

	bool Shader::Compile()	
	{	
		if (!this->Validate())
		{
			ErrorHandler::LogError("Failed to compile the shader because of missing values."); 

			return false;
		}

		for (int x = 0; this->Shaders.size(); x++)
		{	
			glCompileShader(this->Shaders.at(x));

			ErrorHandler::CheckErrors(this->Shaders.at(x), GL_COMPILE_STATUS);
		}

		return true;
	}	

	unsigned int Shader::Link()
	{
		unsigned int ShaderProgram;

		for (int x = 0; x < 2; x++)
			glAttachShader(ShaderProgram, this->Shaders.at(x));

		glLinkProgram(ShaderProgram);

		GLETools::DeleteShaders(this->Shaders);

		return ShaderProgram; 
	}
}