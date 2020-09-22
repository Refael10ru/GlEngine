#pragma once

#define DEFAULTS_H 

#include "globjects.h"

namespace GLEngine
{
	extern String* DefaultStringValues;	//	Array to store all default string values
	extern Point2D* DefaultResolutions;	//	Array to store all default resolutions

	enum DefaultStringType
	{
		WindowTitleStrings
	};

	enum DefaultResolutionType
	{
		DefaultWindow
	}; 
}; 