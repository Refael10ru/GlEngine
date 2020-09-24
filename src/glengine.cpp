#pragma once 

#include "glengine.h"
#include "exceptions.h"

void GLEngine::SetWindowHints(unsigned int major, unsigned int minor)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

bool GLEngine::SetupGLEW()
{
	glewExperimental = GL_TRUE; 

	try
	{
		if (glewInit() != GLEW_OK)
		{
			std::cout << "\nGLEW  initialization error..";

			return false; 
		}
	}
	catch (const LibraryInitializationError& e)
	{	
	}
	return true;
}

bool GLEngine::SetupGLFW()
{
	if (!glfwInit())
	{
		std::cout << "\nGLFW initialization error.";

		return false; 
	}

	return true;
}

void GLEngine::Renderer::Render(GLEngine::Mesh* mesh)	
{	
}

bool GLEngine::Renderer::GLLoop(GLEngine::Window window, GLEngine::Mesh* mesh)
{
	while (!glfwWindowShouldClose(window.GLWindow))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(window.BackgroundColor.R, window.BackgroundColor.G, window.BackgroundColor.B, window.BackgroundColor.A);
		
		window.ProcessInput();
		GLEngine::Renderer::Render(mesh);	//	Renders the mesh  

		glfwPollEvents();
		glfwSwapBuffers(window.GLWindow);
	}

	return true;
}

void GLEngine::Mesh::SetVAO()
{
	this->VAO = GLEngine::VertexArrayObject(); 
}

void GLEngine::VertexArrayObject::CreateBufferObject()
{
	unsigned int BufferObject;	// buffer object to be created
	
	glGenBuffers(GL_ARRAY_BUFFER, &BufferObject);

	this->VertexBufferObjects.push_back(BufferObject);
}

void GLEngine::VertexArrayObject::Bind(GLEngine::VertexArrayObject::ObjectType objectType, unsigned int id)
{
	glBindBuffer(1, this->VertexBufferObjects.at(id));
}

void GLEngine::VertexArrayObject::SetBufferData(unsigned int bufferID, Vertex3Df* vertexArray, int arraySize)
{	
	this->Bind(VertexArrayObject::VertexBuffer, bufferID); 	//	Binds the provided vertex buffer
	
	glBufferData(GL_ARRAY_BUFFER, arraySize * 3, General::VertexArrayToFloatArray(vertexArray, arraySize), GL_STATIC_DRAW);	//	Adds data to the buffer
}

void GLEngine::VertexArrayObject::SetVertexAttributePointer(unsigned int id)
{
	glVertexAttribPointer(id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(id);
}
