#pragma once

#define WINDOW_H

#include "globjects.h"
#include "defaults.h"

namespace GLEngine
{	
	// void FrameBufferSizeCallBack(GLFWwindow* window, int height, int width);
				
	class Window	
	{
	public:
		static std::vector<Window*> WindowStack; 

		unsigned long ID; //	Window ID

		String Title;	//	Window title
		Point2D Resolution; //	Window resolution
		Color BackgroundColor; //	Window background color coordinates.
		
		GLFWwindow* GLWindow;	//	GLFWwindow pointer 		

		static void FrameBufferSizeCallBack(GLFWwindow* window, int height, int width);	// GLFW FrameBufferSizeCallBack function
	
		void Close();	//	Closes the current window instance 
		void ProcessInput(); //	Processes input events

		Window();
		Window(String);
		Window(String, Color);
		Window(String, Point2D, Color);
		Window(Point2D, Color);

		~Window();

		// Window() : /*ID(WindowStack.size()),*/ Title(DefaultStringValues[(int)DefaultStringType::WindowTitleStrings]), Resolution(DefaultResolutions[(int)DefaultResolutionType::DefaultWindow]), GLWindow(glfwCreateWindow(this->Resolution.X, this->Resolution.Y, this->Title, NULL, NULL)), BackgroundColor(Color(0, 0, 0, 0))
		// {
		// 	this->ID = AllocatedWindows.size(); 

		// 	if (this->GLWindow == nullptr)	//	Error check
		// 	{
		// 		std::cout << "\n Could not create the window. "; 
				
		// 		glfwTerminate(); 
		// 	}	
		
		// 	glViewport(0, 0, this->Resolution.X, this->Resolution.Y); 	
		// }

		// Window(String title) : Title (title), Resolution(DefaultResolutions[(int)DefaultResolutionType::DefaultWindow]), GLWindow(glfwCreateWindow(this->Resolution.X, this->Resolution.Y, this->Title, NULL, NULL)), BackgroundColor(Color(0, 0, 0, 0))
		// {
		// }

		// Window(String title, Color color) : Title (title), Resolution(DefaultResolutions[(int)DefaultResolutionType::DefaultWindow]), GLWindow(glfwCreateWindow(this->Resolution.X, this->Resolution.Y, this->Title, NULL, NULL)), BackgroundColor(Color((float)color.R, (float)color.G, (float)color.B, (float)color.A))
		// {
		// }

		// Window(String title, Point2D resolution, Color color = Color(0, 0, 0, 0)) : Title(title), Resolution(resolution), GLWindow(glfwCreateWindow(resolution.X, resolution.Y, this->Title, NULL, NULL)), BackgroundColor(Color(0, 0, 0, 0))
		// {
		// }
		
		// Window(Point2D resolution, Color color) : Title(DefaultStringValues[(int)DefaultStringType::WindowTitleStrings]), Resolution(resolution), GLWindow(glfwCreateWindow(resolution.X, resolution.Y, this->Title, NULL, NULL)), BackgroundColor(Color(0, 0, 0, 0))
		// {
		// }

		// ~Window()
		// {
		// 	std::cout << "Window " << this->GLWindow << " deallocated. "; 
		// }
	};	

	extern std::vector<Window*> AllocatedWindows;	//	Stores all the window instances allocated at runtime

	// std::vector<Window*> WindowStack = std::vector<Window*>();
}