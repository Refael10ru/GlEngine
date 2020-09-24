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

		// Constructors forward declared for global variables depending upon this class to work.

		Window();	
		Window(bool);
		Window(String);
		Window(String, Color);
		Window(String, Point2D, Color);
		Window(Point2D, Color);

		~Window();
	};	

	extern std::vector<Window*> AllocatedWindows;	//	Stores all the window instances allocated at runtime

	// std::vector<Window*> WindowStack = std::vector<Window*>();
}