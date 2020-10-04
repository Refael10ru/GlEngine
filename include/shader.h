#pragma once

#define SHADER_H

#include "globjects.h"
#include "globals.h"

namespace GLEngine
{	
	extern GLenum* ShaderTypeGLenums; 	// Stores GLenums of the respective Shader types
	
	class Shader
	{
	private:	
		void DeleteShaders()	//	Deletes the created shaders
		{
			for (int x = 0; x < 2; x++)
				glDeleteShader(this->ShaderIDs[x]); 
		}
	
	public:
		enum ShaderType
		{
			VertexShader, 
			FragmentShader
		};
		
		unsigned int ShaderProgramID; // Stores the final compiled shader program ID

		unsigned int* ShaderIDs;	// Array to store the program IDs of the			

		std::vector<String> ShaderProgramStrings; // Array to store them shader program string

		bool Verify();	// Checks if the current instance of the Shader is eligible to get compiled and linked to the final shader program
		void CheckErrors(unsigned int, GLenum); // Checks for compiling and linking errors
		
		unsigned int* Compile();	//	Compiles all the shaders at once if eligible
		unsigned int Link();	//	Links the compiled shaders into one shader program						

		Shader()
		{	
			this->ShaderProgramStrings = {
				nullptr, 
				nullptr
			};

			this->ShaderIDs = new unsigned int[2] {
				NULL, 
				NULL
			};
		}

		Shader(String vertexShaderString, String fragmentShaderString) : ShaderProgramStrings({ new char[1000], new char[1000] })	//	
		{
			strcpy(this->ShaderProgramStrings.at(0), vertexShaderString); 
			strcpy(this->ShaderProgramStrings.at(1), fragmentShaderString); 

			this->ShaderIDs = new unsigned int[2] {
				glCreateShader(GL_VERTEX_SHADER), 
				glCreateShader(GL_FRAGMENT_SHADER)
			};
		}	

		Shader(String vertexShaderString, String fragmentShaderString, bool compile) : ShaderProgramStrings({ new char[1000], new char[1000] })	//	
		{
			strcpy(this->ShaderProgramStrings.at(0), vertexShaderString); 
			strcpy(this->ShaderProgramStrings.at(1), fragmentShaderString); 

			this->ShaderIDs = new unsigned int[2] {
				glCreateShader(GL_VERTEX_SHADER), 
				glCreateShader(GL_FRAGMENT_SHADER)
			};

			if (compile)
			{
				this->Compile();
				this->Link(); 
			}
		}
		
		Shader(std::vector<String> shaderStrings) : ShaderProgramStrings(shaderStrings)
		{
		}

		Shader(std::vector<String> shaderStrings, bool compile) : ShaderProgramStrings(shaderStrings) 
		{
			if (compile)
			{
				this->Compile();
				this->Link();
			}
		}

		~Shader()
		{
			this->DeleteShaders();
		}
	}; 
}	
