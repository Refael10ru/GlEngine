#include "glengine.h"
#include "exceptions.h"

GLenum* GLEngine::GLObjectEnums = new GLenum[1] {
	GL_TRIANGLES
}; 

std::vector<GLEngine::GLEObject*> GLEngine::AllocatedGLEObjects = std::vector<GLEngine::GLEObject*>(); 

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
			throw new LibraryInitializationError("GLEW");
	}
	catch (const LibraryInitializationError& e)
	{	
		std::cout << "\nGLEW  initialization error..";

		return false; 
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
	glUseProgram(mesh->MeshShader.ShaderProgramID);
	// mesh->VAO.Bind(VertexArrayObject::VertexArray, 0);
	glBindVertexArray(0); 
	glDrawArrays(GL_TRIANGLES, 0, 3); 
}	

void GLEngine::Renderer::Render(GLEngine::GLEObject* object)
{		
	glUseProgram(object->ObjectMesh->MeshShader.ShaderProgramID);
	// mesh->VAO.Bind(VertexArrayObject::VertexArray, 0);
	glBindVertexArray(0); 
	glDrawArrays(GL_TRIANGLES, 0, 3); // temporary rendering type
}	

bool GLEngine::Renderer::GLLoop(GLEngine::Window window, Mesh* mesh)
{
	while (!glfwWindowShouldClose(window.GLWindow))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(window.BackgroundColor.R, window.BackgroundColor.G, window.BackgroundColor.B, window.BackgroundColor.A);
		
		window.ProcessInput();
		
		GLEngine::Renderer::Render(mesh);	//	Renders the mesh  

		glfwSwapBuffers(window.GLWindow);
		glfwPollEvents();
	}

	return true;
}

bool GLEngine::Renderer::GLLoop(GLEngine::Window window, GLEObject* object)
{
	while (!glfwWindowShouldClose(window.GLWindow))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(window.BackgroundColor.R, window.BackgroundColor.G, window.BackgroundColor.B, window.BackgroundColor.A);
		
		window.ProcessInput();
		
		GLEngine::Renderer::Render(object);	//	Renders the mesh  

		glfwSwapBuffers(window.GLWindow);
		glfwPollEvents();
	}

	return true;
}

// void GLEngine::Mesh::SetVAO()
// {
// 	this->VAO = GLEngine::VertexArrayObject(this->VertexMatrixArray, this->MatrixSize); 
// }

void GLEngine::VertexArrayObject::CreateBufferObject()
{
	unsigned int BufferObject;	// buffer object to be created

	glGenBuffers(1, &BufferObject);

	this->VertexBufferObjects.push_back(BufferObject);
}

void GLEngine::VertexArrayObject::Bind(GLEngine::VertexArrayObject::ObjectType objectType, unsigned int id)
{
	try
	{
		switch (objectType)
		{
			case VertexArrayObject::VertexBuffer: 
				glBindBuffer(GL_ARRAY_BUFFER, id);
				
				break;

			case VertexArrayObject::VertexArray: 
				glBindVertexArray(id); 

				break;

			default:
				throw new GLEInvalidTypeException("VertexObject"); 		

				break; 
		}
	}
	catch (const GLEInvalidTypeException& e)
	{
		Debug->Log(e.Message);	
	}
}

void GLEngine::VertexArrayObject::SetBufferData(unsigned int bufferID, float* vertexArray, unsigned int arraySize)
{	
	// this->Bind(VertexArrayObject::VertexBuffer, bufferID); 	//	Binds the provided vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);

	glBufferData(GL_ARRAY_BUFFER, arraySize, vertexArray, GL_STATIC_DRAW);	//	Adds data to the buffer
}

void GLEngine::VertexArrayObject::SetVertexAttributePointer(unsigned int id)
{
	// this->Bind(VertexArrayObject::VertexArray, id);
	glBindVertexArray(id); 
	glVertexAttribPointer(id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(id);
}	

GLEngine::GLEObject::GLEObject() : ID(GLEngine::AllocatedGLEObjects.size()), VAO(VertexArrayObject()), MeshArray(std::vector<Mesh*>()), ObjectMesh(new Mesh())
{
}

GLEngine::GLEObject::GLEObject(float* vertexMatrixArray) : ID(GLEngine::AllocatedGLEObjects.size()), VAO(VertexArrayObject()), MeshArray({ new Mesh(vertexMatrixArray, 9, Shader()) }), ObjectMesh(this->MeshArray.at(0))
{
}

GLEngine::GLEObject::GLEObject(std::vector<Vertex3Df> vertexVectorArray) : ID(AllocatedGLEObjects.size()), VAO(VertexArrayObject()), MeshArray({ new Mesh(vertexVectorArray) }), ObjectMesh(this->MeshArray.at(0))
{
	this->VAO = VertexArrayObject(this->ObjectMesh->VertexMatrixArray, 9);
}

GLEngine::GLEObject::GLEObject(std::vector<Vertex3Df> vertexVectorArray, GLEngine::Shader shader) : ID(AllocatedGLEObjects.size()), MeshArray({ new Mesh(vertexVectorArray, shader) })//, ObjectMesh(this->MeshArray.at(0))
{	
	this->ObjectMesh = this->MeshArray.at(0);
	// General::PrintVertexFloatArray(this->ObjectMesh->VertexMatrixArray, 9); s
	this->VAO = VertexArrayObject(General::VertexVectorToFloatArray(this->ObjectMesh->VertexMatrixVector), this->ObjectMesh->VertexMatrixVector.size() * 3); 	
}

GLEngine::GLEObject::GLEObject(float* vertexVectorArray, int arraySize, GLEngine::Shader shader) : ID(AllocatedGLEObjects.size()), MeshArray({ new Mesh(vertexVectorArray, arraySize, shader) }), ObjectMesh(this->MeshArray.at(0))
{
}
