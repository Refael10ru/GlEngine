#include "ds.h"

namespace DataStructures
{
    Point2D* Stack::ToArray(stack<Point2D> points)
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
}