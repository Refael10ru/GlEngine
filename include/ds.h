#pragma once

#define DS_H

#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h> 
#include "cartesianobj.h"

using namespace std;

namespace GLEngine
{
	class Stack
	{
	public:
		static Point2D* ToArray(stack<Point2D> points);
	};
}
