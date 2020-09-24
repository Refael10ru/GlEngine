#include "globjects.h"
#include "window.h"

String* GLEngine::DefaultStringValues = new String[1] {
	"New Window"
}; 

GLEngine::Point2D* GLEngine::DefaultResolutions = new Point2D[1] {
	Point2D(800, 600)	
};
