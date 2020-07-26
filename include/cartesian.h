#pragma once

#define CARTESIAN_H

#include <vector>
#include <stack>
#include "cartesianobj.h"

using namespace CartesianObjects;

namespace Cartesian
{
	template<typename T>  // to make the class compatiuble with both 2D and 3D points
	class Plane
	{
	public:
		std::vector<T> PointVector;  // for storing all the points present in the plane
		
		T* GLPointArray;

		Plane(std::vector<T> pointVector) : PointVector(pointVector), GLPointArray(new T[0])	// temporary contstructor
		{
		}	
	};
}