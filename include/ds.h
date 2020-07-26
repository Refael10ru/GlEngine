#pragma once

#define DS_H

#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h> 
#include "cartesianobj.h"

using namespace CartesianObjects;
using namespace std;

namespace DataStructures
    {
        class Stack
        {
        public:
            static Point2D* ToArray(stack<Point2D> points)
            {
                int stackSize = points.size(); //stack size temp 
        
                Point2D* pointsArray = new Point2D[stackSize];

                for (int x = 0; x < stackSize; x++)
                {
                    pointsArray[x] = points.top(); //popped value is stored in the array.
                   
                    points.pop();
                }
                
                return pointsArray;
            }
    };
};
