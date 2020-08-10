#pragma once

#define GLOBJECTS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "defaultmacro.h"
#include "errorhandling.h"
#include "debug.h"

namespace GLEngine
{
	class GLETools	//	to be replaced with a better name
	{
	public:	
		enum GLEobject
		{
			VertexArray, 
			VertexBuffer
		};

		static unsigned int LinkShaders(std::vector<unsigned int> shaders);	//	linkes the shaders respective to the shader ids stroed in the provided std::vector<unsigned int> into one shader program
	
		static unsigned int CreateShader(char* ShaderString, GLenum shaderType);	// creates a shader of the specified type and returns its ID

		static unsigned int CreateShader(char* ShaderString, GLenum shaderType, bool compile);	// creates a shader of the specified type and returns its ID (compiled/uncompiled depends upon the boolean)
	
		static unsigned int CreateObject(GLETools::GLEobject objectType);	//	alllocates the specified glObject and returns it's ID

		static void DeleteShaders(std::vector<unsigned int>);

		static void SetVertexAttributePointer(int size);	// sets the vertex attribute pointer of the bound vertex array object

		static void ZeroBind();	//	binds the vertex array and buffer objects with ID 0
	};
	
	class Shader
	{
	public:
		enum ShaderType
		{
			Vertex, 
			Fragment
		};

		unsigned int ShaderProgramID;

		std::vector<unsigned int> Shaders;

		char** ShaderStrings;	//	Pointer to the array containing shader strings

		bool Linked;	//	insicates if the shaders are compiled and linked into a shader program 

		bool AttachString(char* shaderString, ShaderType shaderType);	// attaches the shader string to the specified shader

		bool Validate();	// checks if any of the parameters required for a successful compile is null and returns the bool representing the same

		bool Compile();	//	compiles the shaders respective to the shader ids stores in Shader::Shaders

		unsigned int Link();

		Shader() : Shaders({ glCreateShader(GL_VERTEX_SHADER), glCreateShader(GL_FRAGMENT_SHADER) }), ShaderStrings(new char*[2]{ nullptr, nullptr }), Linked(false)
		{
		}

		Shader(unsigned int vertex, unsigned int fragment) : Shaders({ vertex, fragment }), ShaderStrings(new char*[2]{ nullptr, nullptr }), Linked(false)	//	todo: construct the ShaderStrings  array, and a complete valid overload of thi	s constuctor
		{
		}

		Shader(unsigned int vertexObj, unsigned int fragmentObj, char* vertexShaderString, char* fragmentShaderString) : Shaders({ vertexObj, fragmentObj }), ShaderStrings(new char*[2]{ vertexShaderString, fragmentShaderString })  
		{
			this->Compile();
			this->ShaderProgramID = this->Link();	// links the shader program
		}

		Shader(char* vertexShaderString, char* fragmentShaderString) : Shaders({ glCreateShader(GL_VERTEX_SHADER), glCreateShader(GL_FRAGMENT_SHADER) }), ShaderProgramID(this->Link())	//	creates and compiles the shaders as the resources are available	
		{
			Debug::Log("Shader contructor called. ");	
		}

		~Shader()
		{
			for (int x = 0; x < this->Shaders.size(); x++)
				glDeleteShader(this->Shaders.at(x));

			printf("\nShader %d deleted.", this->ShaderProgramID);
		}
	};
}
