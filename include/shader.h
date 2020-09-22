#pragma once

#define SHADER_H

#include "globjects.h"

namespace GLEngine
{	
	extern GLenum* ShaderTypeGLenums; 	// Stores GLenums of the respective Shader types
	
	class Shader
	{
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
		unsigned int* Compile();	// Compiles all the shaders at once if eligible
		unsigned int Link(); // Links the compiled shaders into one shader program						

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

		Shader(String vertexShaderString, String fragmentShaderString) : ShaderProgramStrings({ vertexShaderString, fragmentShaderString })
		{
			this->ShaderIDs = new unsigned int[2] {
				glCreateShader(ShaderTypeGLenums[0]), 
				glCreateShader(ShaderTypeGLenums[1])
			};
		}
		
		Shader(std::vector<String> shaderStrings) : ShaderProgramStrings(shaderStrings)
		{	
		}

		Shader(std::vector<String> shaderStrings, bool compile) : ShaderProgramStrings(shaderStrings) 
		{
			this->Compile(); 	
			this->Link();
		}
	}; 
}	