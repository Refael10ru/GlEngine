#ifndef _IO_
#define _IO_

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

namespace okek
{

    class IO
    {
    public:
        static std::string GetStringFile(std::string Path);
    };

};

#endif