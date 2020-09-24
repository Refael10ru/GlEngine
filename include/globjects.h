#pragma once

#define GLEOBJECTS_H 

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include "gltypes.h"
#include "Debug.h"

using namespace DebugTools;

namespace GLEngine
{	
	struct Point2D
	{	
		int X, Y; 

		Point2D() : X(0), Y(0)
		{
		}

		Point2D(int x, int y) : X(x), Y(y)
		{
		}

		Point2D operator +(const Point2D& rhs)
		{
			return Point2D(Point2D(this->X + rhs.X, this->Y + rhs.Y)); 
		}	
		
		Point2D operator -(const Point2D& rhs)
		{
			return Point2D(Point2D(this->X - rhs.X, this->Y - rhs.Y)); 
		}	
		
		Point2D operator *(const Point2D& rhs)
		{
			return Point2D(Point2D(this->X * rhs.X, this->Y * rhs.Y)); 
		}	

		Point2D operator /(const Point2D& rhs)
		{
			return Point2D(Point2D(this->X / rhs.X, this->Y / rhs.Y)); 
		}	
	}; 

	struct Point2Df
	{	
		float X, Y; 

		Point2Df() : X(0), Y(0)
		{
		}

		Point2Df(float x, float y) : X(x), Y(y)
		{
		}

		Point2Df operator +(const Point2Df& rhs)
		{
			return Point2Df(Point2Df(this->X + rhs.X, this->Y + rhs.Y)); 
		}	
		
		Point2Df operator -(const Point2Df& rhs)
		{
			return Point2Df(Point2Df(this->X - rhs.X, this->Y - rhs.Y)); 
		}	
		
		Point2Df operator *(const Point2Df& rhs)
		{
			return Point2Df(Point2Df(this->X * rhs.X, this->Y * rhs.Y)); 
		}	

		Point2Df operator /(const Point2Df& rhs)
		{
			return Point2Df(Point2Df(this->X / rhs.X, this->Y / rhs.Y)); 
		}	
	}; 

	struct Point3D	// Stores a 3D Point
	{
	public:
		int X, Y, Z; 

		Point3D() : X(0), Y(0), Z(0)
		{
		}
		
		Point3D(int x, int y, int z) : X(x), Y(y), Z(z)
		{
		}

		Point3D operator +(const Point3D& rhs)
		{
			return Point3D(this->X + rhs.X, this->Y + rhs.Y, this->Z + rhs.Z);
		}
		
		Point3D operator -(const Point3D& rhs)
		{
			return Point3D(this->X - rhs.X, this->Y - rhs.Y, this->Z - rhs.Z);
		}
		
		Point3D operator *(const Point3D& rhs)
		{
			return Point3D(this->X * rhs.X, this->Y * rhs.Y, this->Z * rhs.Z);
		}

		Point3D operator /(const Point3D& rhs)
		{
			return Point3D(this->X / rhs.X, this->Y / rhs.Y, this->Z / rhs.Z);
		}
	}; 

	struct Point3Df	// Stores a 3D Point
	{
	public:
		float X, Y, Z; 

		Point3Df() : X(0), Y(0), Z(0)
		{
		}
		
		Point3Df(float x, float y, float z) : X(x), Y(y), Z(z)
		{
		}

		Point3Df operator +(const Point3D& rhs)
		{
			return Point3Df(this->X + rhs.X, this->Y + rhs.Y, this->Z + rhs.Z);
		}
		
		Point3Df operator -(const Point3D& rhs)
		{
			return Point3Df(this->X - rhs.X, this->Y - rhs.Y, this->Z - rhs.Z);
		}
		
		Point3Df operator *(const Point3D& rhs)
		{
			return Point3Df(this->X * rhs.X, this->Y * rhs.Y, this->Z * rhs.Z);
		}

		Point3Df operator /(const Point3D& rhs)
		{
			return Point3Df(this->X / rhs.X, this->Y / rhs.Y, this->Z / rhs.Z);
		}
	}; 

	struct Color	// Stores RGB values.
	{
		float R, G, B, A; 

		Color() : R(0), G(0), B(0), A(0)
		{		
		}
		
		Color(float r, float g, float b, float a) : R(r), G(g), B(b), A(0)
		{
		}	

		Color(float r, float g, float b) : R(r), G(g), B(b)
		{
		}
	}; 

	struct Vertex2D
	{
		Point2D Position; 

		Color VertexColor;

		Vertex2D() : Position(Point2D()), VertexColor(Color())
		{
		}

		Vertex2D(Point2D position) : Position(position), VertexColor(Color())
		{
		}

		Vertex2D(Point2D position, Color color) : Position(position), VertexColor(color)
		{
		}
	}; 

	struct Vertex2Df
	{
		Point2Df Position; 

		Color VertexColor;

		Vertex2Df() : Position(Point2Df()), VertexColor(Color())
		{
		}

		Vertex2Df(Point2Df position) : Position(position), VertexColor(Color())
		{
		}

		Vertex2Df(Point2Df position, Color color) : Position(position), VertexColor(color)
		{
		}
	}; 

	struct Vertex3D
	{
		Point3D Position; 

		Color VertexColor;

		Vertex3D() : Position(Point3D()), VertexColor(Color())
		{
		}

		Vertex3D(Point3D position) : Position(position), VertexColor(Color())
		{
		}

		Vertex3D(Point3D position, Color color) : Position(position), VertexColor(color)
		{
		}
	}; 

	struct Vertex3Df
	{
		Point3Df Position; 

		Color VertexColor;

		Vertex3Df() : Position(Point3Df()), VertexColor(Color())
		{
		}

		Vertex3Df(Point3Df position) : Position(position), VertexColor(Color())
		{
		}

		Vertex3Df(Point3Df position, Color color) : Position(position), VertexColor(color)
		{
		}
	}; 
	// Contains data about a window.
}

// std::vector<GLEngine::Window*> AllocatedWindows = std::vector<GLEngine::Window*>();	// Execution Data
	