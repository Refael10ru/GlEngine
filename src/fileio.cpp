#include "fileio.h"
#include "errorhandling.h"

namespace GLEngine
{
    bool FileIO::Write(char* data,  char* path) 
    {
        FILE* FilePointer = fopen(path, "w");

        if (FilePointer == NULL)
        {
            ErrorHandler::LogError(strcat(strcat(new char[MAX_STRING_SIZE], "Couldn't open"), path));

            return false;
        }        

        fprintf(FilePointer, "%s", data);

        return true;
    }

    char* FileIO::ReadData(char* path)
    {
        FILE* FilePointer = fopen(path, "r");

        char* DataBuffer = new char[MAX_STRING_SIZE];

        long FileByteSize;  //  size of filecontent in bytes.

        if (FilePointer == NULL)
        {
            ErrorHandler::LogError(strcat(strcat(new char[MAX_STRING_SIZE], "Couldn't open"), path));

            return nullptr;
        }

        fseek(FilePointer, 0L, SEEK_END);   // get the number of bytes in the file
        
        FileByteSize = ftell(FilePointer);  // sets the var to the byte size retrieved from the file using fseek()

        fseek(FilePointer, 0L, SEEK_SET);   // resets the file pointer to the beginning (0th element) of the file

        fread(DataBuffer, sizeof(char), FileByteSize, FilePointer); //  reads FileByteSize bytes from the file
        fclose(FilePointer);

        return DataBuffer;
    }
};