#include "IO.h"

namespace okek
{
    std::string IO::GetStringFile(std::string Path)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::ifstream ifstream;
        // ensure ifstream objects can throw exceptions:
        ifstream.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        try 
        {
            //std::cout << Path << "\n";
            // open files
            ifstream.open(Path);
            std::stringstream vShaderStream;
            // read file's buffer contents into streams
            vShaderStream << ifstream.rdbuf();	
            // close file handlers
            ifstream.close();
            // convert stream into string
            return vShaderStream.str();	
        }
        catch(std::ifstream::failure)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ\n" << Path << std::endl;
            return "EXCEPTION::INFILEREADING";
        }

    }
};