#pragma once

#define CARTESIANOBJ_H

#include <stack>
#include <vector>

namespace CartesianObjects  // contains all the objects required by the cartesian system
{
	struct Coordinates2D // for storing a 2D coordinates
	{
		int X, Y;

		Coordinates2D(int x, int y) : X(y), Y(y) 
		{
		}
	};

	struct Coordinates3D // for storing a 3D coordinates
	{
		int X, Y, Z; 

		Coordinates3D(int x, int y, int z) : X(x), Y(y), Z(z)
		{
		} 
	};
	
	enum GLEColor	// array index enums for pre defined color values 
	{
		Violet,
		Indigo,
		Blue,
		Green, 
		Yellow, 
		Orange,
		Red, 
		White
	};	//	todo: add RGB values for all common colors

	struct Color	// for storing RGB values
	{
		float R, G, B; 

		Color(float r, float g, float b) :  R(r), G(g), B(b) 
		{
		}
	};

	Color GLEColors[] = {	// pre defined RGB values for quick access ()
		Color(148, 0, 211),	//	Violet
		Color(75, 0, 130),	//	Indigo
		Color(0, 0, 255),	//	Blue
		Color(0, 255, 0),	//	Green
		Color(255, 255, 0),	//	Yelllow
		Color(255, 127, 0),	//	Orange
		Color(255, 0, 0),	//	Red
		Color(255, 255, 255)//	White
	};
	
	enum PlotStatus // for specifying the status of a current point on the cartesian plane(required by cartesian rendering algorithm)
	{
		Hidden,
		Plotted
	};

	static Color DefaultPointColor = GLEColors[(int)GLEColor::White]; // RGB value of the point, Object storing default color


	struct Point2D   // for storing a point recognizable by 
	{
		Coordinates2D Coordinates;
		PlotStatus plotStatus;  // current plotstatus of the point
		bool IsPlotted;   // bool for representing the plotstatus
		
		Color ColorValue;	// for storing the RGB value of the point

		Point2D(Coordinates2D coordinates) : Coordinates(coordinates), plotStatus(PlotStatus::Hidden), ColorValue(DefaultPointColor)
		{
		}
		
		Point2D(Coordinates2D coordinates, Color color) : Coordinates(coordinates), plotStatus(PlotStatus::Hidden), ColorValue(color)
		{
		}
		
		Point2D(Coordinates2D coordinates, PlotStatus plotstatus) : Coordinates(coordinates), plotStatus(plotStatus), ColorValue(DefaultPointColor)
		{
		}

		Point2D(Coordinates2D coordinates, PlotStatus plotstatus, Color color) : Coordinates(coordinates), plotStatus(plotStatus), ColorValue(color)
		{
		}

		Point2D(int x, int y) : Coordinates(Coordinates2D(x, y)), plotStatus(PlotStatus::Hidden), ColorValue(DefaultPointColor)
		{
		}
	
		Point2D(int x, int y, Color color) : Coordinates(Coordinates2D(x, y)), plotStatus(PlotStatus::Hidden), ColorValue(color)
		{
		}

		Point2D(int x, int y, PlotStatus plotstatus) : Coordinates(Coordinates2D(x, y)), plotStatus(plotStatus), IsPlotted((bool)((int)plotStatus)), ColorValue(DefaultPointColor) 
		{
		}

		Point2D(int x, int y, Color color, PlotStatus plotstatus) : Coordinates(Coordinates2D(x, y)), plotStatus(plotStatus), IsPlotted((bool)((int)plotStatus)), ColorValue(color) 
		{
		}

		Point2D(Coordinates2D coordinates, bool plotted) : Coordinates(coordinates), IsPlotted(plotted), plotStatus((PlotStatus)((int)Plotted)), ColorValue(DefaultPointColor)
		{
		}
		
		Point2D(Coordinates2D coordinates, bool plotted, Color color) : Coordinates(coordinates), IsPlotted(plotted), plotStatus((PlotStatus)((int)Plotted)), ColorValue(color)
		{
		}

		Point2D(int x, int y, bool plotted) : Coordinates(Coordinates2D(x, y)), IsPlotted(plotted), plotStatus((PlotStatus)((int)Plotted)), ColorValue(DefaultPointColor)		
		{
		}

		Point2D(int x, int y, bool plotted, Color color) : Coordinates(Coordinates2D(x, y)), IsPlotted(plotted), plotStatus((PlotStatus)((int)Plotted)), ColorValue(color)
		{
		}
	};
	
	struct GLPoint2D    // for storing a point recognizable by 
	{
		Coordinates2D Coordinates;
		PlotStatus plotStatus;  // current plotstatus of the point
		bool IsPlotted;   // bool for representing the plotstatus

		Color ColorValue;	//	for storing the RGB value of the point

		GLPoint2D(Coordinates2D coordinates) : Coordinates(Coordinates2D(coordinates.X / 10, coordinates.Y / 10)), plotStatus(PlotStatus::Hidden), IsPlotted((bool)((int)Hidden)), ColorValue(DefaultPointColor)		
		{
		}
		
		GLPoint2D(Coordinates2D coordinates, Color color) : Coordinates(Coordinates2D(coordinates.X / 10, coordinates.Y / 10)), plotStatus(PlotStatus::Hidden), IsPlotted((bool)((int)Hidden)), ColorValue(color)		
		{
		}

		GLPoint2D(Coordinates2D coordinates, PlotStatus plotstatus) : Coordinates(Coordinates2D(coordinates.X / 10, coordinates.Y / 10)), plotStatus(plotStatus), ColorValue(DefaultPointColor)
		{
		}

		GLPoint2D(Coordinates2D coordinates, Color color, PlotStatus plotstatus) : Coordinates(Coordinates2D(coordinates.X / 10, coordinates.Y / 10)), plotStatus(plotStatus), ColorValue(color)		
		{
		}

		GLPoint2D(int x, int y) : Coordinates(Coordinates2D(x / 10, y / 10)), plotStatus(PlotStatus::Hidden), ColorValue(DefaultPointColor)
		{
		}
		
		GLPoint2D(int x, int y, Color color) : Coordinates(Coordinates2D(x / 10, y / 10)), plotStatus(PlotStatus::Hidden), ColorValue(color)
		{
		}
		
		GLPoint2D(int x, int y, PlotStatus plotstatus) : Coordinates(Coordinates2D(x / 10, y / 10)), plotStatus(plotStatus), ColorValue(DefaultPointColor)
		{
		}
		
		GLPoint2D(int x, int y, Color color, PlotStatus plotstatus) : Coordinates(Coordinates2D(x / 10, y / 10)), plotStatus(plotStatus), ColorValue(color)
		{
		}
		
		GLPoint2D(Coordinates2D coordinates, bool plotted) : Coordinates(Coordinates2D(coordinates.X / 10, coordinates.Y / 10)), IsPlotted(plotted), plotStatus((PlotStatus)((int)Plotted)), ColorValue(DefaultPointColor)
		{
		}
		
		GLPoint2D(Coordinates2D coordinates, Color color, bool plotted) : Coordinates(Coordinates2D(coordinates.X / 10, coordinates.Y / 10)), IsPlotted(plotted), plotStatus((PlotStatus)((int)Plotted)), ColorValue(color)
		{
		}
		
		GLPoint2D(int x, int y, bool plotted) : Coordinates(Coordinates2D(x / 10, y / 10)), IsPlotted(plotted), plotStatus((PlotStatus)((int)Plotted)), ColorValue(DefaultPointColor)
		{
		}
		
		GLPoint2D(int x, int y, Color color, bool plotted) : Coordinates(Coordinates2D(x / 10, y / 10)), IsPlotted(plotted), plotStatus((PlotStatus)((int)Plotted)), ColorValue(color)
		{
		}    
	};
}