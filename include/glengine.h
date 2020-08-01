#pragma once

#define GLENGINE_H

#include <GLFW/glfw3.h>
#include "cartesianobj.h"
#include "cartesian.h"
#include <vector>

namespace GLEngine 
{
	void FrameBufferCallBack(GLFWwindow* window, int width, int height);
	
	void FrameBufferCallBack(GLFWwindow* window, int width, int height) 
	{
		glViewport(0, 0, width, height);
	}
	
	class Window	// stores the config 
	{
	public:
		char* Title;
		
		Coordinates2D Dimensions;

		GLFWwindow* GLEwindow;

		Window(Coordinates2D dimensions, char* title) : Dimensions(dimensions), Title(title), GLEwindow(glfwCreateWindow(this->Dimensions.X, this->Dimensions.Y, this->Title, NULL, NULL))
		{			
			if (!this->GLEwindow)
				glfwTerminate();
		}

		Window(Coordinates2D dimensions) : Dimensions(dimensions), Title("New Window"), GLEwindow(glfwCreateWindow(this->Dimensions.X, this->Dimensions.Y, this->Title, NULL, NULL))
		{
			if (!this->GLEwindow)
				glfwTerminate();
		}

		void SwapBuffer();
	};


	class Renderer
	{
	public:
		static void Render(std::vector<Point2D> points, Window window)
		{
			window.GLEwindow = glfwCreateWindow(window.Dimensions.X, window.Dimensions.Y, "New Window", NULL, NULL);

			glfwMakeContextCurrent(window.GLEwindow);

			float vertexMatrix[] = {
				-0.5f, -0.5f,
				0.5f, -0.5f, 
				0.0f, 0.5f
			};

			while (!glfwWindowShouldClose(window.GLEwindow))
			{
				glClear(GL_COLOR_BUFFER_BIT);
				glClearColor(0.0f, 153.0f, 204.0f, 0.0f);
			
				glBegin(GL_TRIANGLES);

				// for (int x = 0; x < (points.size()); x++)
				// 	glVertex2f(points.at(x).	Coordinates.X, points.at(x).Coordinates.Y);
				
				

				// glVertex2f(vertexMatrix[x][0], vertexMatrix[x][1]);

				// glVertex2f(-0.5f, -0.5f);
				// glVertex2f(0.5f, -0.5f);
				// glVertex2f(0.0f, 0.5f);

				glEnd();
				
				glfwSwapBuffers(window.GLEwindow);
				
				glfwPollEvents();
			}

			glfwTerminate();
		}
	};
}