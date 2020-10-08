#include "window.h"
#include "tools.h"
#include "Debug.h"

// constructors to be forward declared.

std::vector<GLEngine::Window*> GLEngine::AllocatedWindows = std::vector<GLEngine::Window*>();

GLEngine::Window::Window() : /*ID(WindowStack.size()),*/ Title(DefaultStringValues[(int)DefaultStringType::WindowTitleStrings]), Resolution(DefaultResolutions[(int)DefaultResolutionType::DefaultWindow]), GLWindow(glfwCreateWindow(this->Resolution.X, this->Resolution.Y, this->Title, NULL, NULL)), BackgroundColor(Color(0, 0, 0, 0)), ID(AllocatedWindows.size())
{
	AllocatedWindows.push_back(this);

	if (this->GLWindow == nullptr)	//	Error check
	{
		std::cout << "\n Could not create the window. "; 
				
		glfwTerminate(); 
	}	
		
	glViewport(0, 0, this->Resolution.X, this->Resolution.Y); 
}

GLEngine::Window::Window(String title) : Title (title), Resolution(DefaultResolutions[(int)DefaultResolutionType::DefaultWindow]), GLWindow(glfwCreateWindow(this->Resolution.X, this->Resolution.Y, this->Title, NULL, NULL)), BackgroundColor(Color(0, 0, 0, 0)), ID(AllocatedWindows.size())
{
	AllocatedWindows.push_back(this);
}

GLEngine::Window::Window(String title, Color color) : Title (title), Resolution(DefaultResolutions[(int)DefaultResolutionType::DefaultWindow]), GLWindow(glfwCreateWindow(this->Resolution.X, this->Resolution.Y, this->Title, NULL, NULL)), BackgroundColor(Color((float)color.R, (float)color.G, (float)color.B, (float)color.A)), ID(AllocatedWindows.size())
{
	AllocatedWindows.push_back(this);

}

GLEngine::Window::Window(String title, Point2D resolution, Color color = Color(0, 0, 0, 0)) : Title(title), Resolution(resolution), GLWindow(glfwCreateWindow(resolution.X, resolution.Y, this->Title, NULL, NULL)), BackgroundColor(color), ID(AllocatedWindows.size())
{
	AllocatedWindows.push_back(this);


	Debug->Log(color.R); 
	Debug->Log(color.G); 
	Debug->Log(color.B); 
	Debug->Log(color.A); 	
}

GLEngine::Window::Window(Point2D resolution, Color color) : Title(DefaultStringValues[(int)DefaultStringType::WindowTitleStrings]), Resolution(resolution), GLWindow(glfwCreateWindow(resolution.X, resolution.Y, this->Title, NULL, NULL)), BackgroundColor(Color(0, 0, 0, 0)), ID(AllocatedWindows.size())
{
	AllocatedWindows.push_back(this);
}

GLEngine::Window::~Window()
{
	std::cout << "Window " << this->GLWindow << " deallocated. "; 
}

GLEngine::Window::Window(bool active) : /*ID(WindowStack.size()),*/ Title(DefaultStringValues[(int)DefaultStringType::WindowTitleStrings]), Resolution(DefaultResolutions[(int)DefaultResolutionType::DefaultWindow]), GLWindow(glfwCreateWindow(this->Resolution.X, this->Resolution.Y, this->Title, NULL, NULL)), BackgroundColor(Color(0, 0, 0, 0)), ID(AllocatedWindows.size())
{
	AllocatedWindows.push_back(this);

	if (this->GLWindow == nullptr)	//	Error check
	{
		std::cout << "\n Could not create the window. "; 
				
		glfwTerminate(); 
	}	
		
	glViewport(0, 0, this->Resolution.X, this->Resolution.Y);

	if (active)
	{
		glfwMakeContextCurrent(this->GLWindow); 

		glfwSetFramebufferSizeCallback(this->GLWindow, Window::FrameBufferSizeCallBack); 
	}
}

void GLEngine::Window::FrameBufferSizeCallBack(GLFWwindow* window, int height, int width)
{
	glViewport(0, 0, height, width); 
}

void GLEngine::Window::Close()	
{
	glfwSetWindowShouldClose(this->GLWindow, true);
}	

void GLEngine::Window::ProcessInput()
{
	if (glfwGetKey(this->GLWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		this->Close(); 
}
