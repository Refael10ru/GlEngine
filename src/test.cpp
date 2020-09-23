#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "globjects.h"
#include "glengine.h"
#include "window.h"
#include "shader.h"
#include "fileio.h"

using namespace GLEngine; 

int main()
{  
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	if (!glfwInit())
	{
		std::cout << "\nCouldn't initialize glfw.";

		return -1; 
	}

	Window window = Window("GLEngine App", Color(1, 0.5, 0.6, 1));

	glfwMakeContextCurrent(window.GLWindow); 
	
	glfwSetFramebufferSizeCallback(window.GLWindow, window.FrameBufferSizeCallBack); 

	GLenum test;

	glewExperimental = GL_TRUE;
	
	if ((test = glewInit()) != GLEW_OK) 
	{
		// fprintf(stderr, "Failed to initialize GLEW\n");
		// getchar();
		
		std::cout << glewGetErrorString(test); 
		
		glfwTerminate();
		
		return -1;
  	}     
	
	// GLobjects initialization
	Shader shader = Shader();
	VertexArrayObject VAO = VertexArrayObject(5);// = VertexArrayObject();

	while (!glfwWindowShouldClose(window.GLWindow))
	{
		glClearColor((float)window.BackgroundColor.R, (float)window.BackgroundColor.G, (float)window.BackgroundColor.B, (float)window.BackgroundColor.A);
		glClear(GL_COLOR_BUFFER_BIT);

		window.ProcessInput();

		glfwSwapBuffers(window.GLWindow);


		glfwPollEvents(); 
	}

	return 0; 
}