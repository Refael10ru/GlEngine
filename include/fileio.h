#pragma once

#define FILEIO_H 

#include <stdio.h>
#include <stdlib.h>
#include "globjects.h"
#include "gltypes.h"
#include "exceptions.h"

namespace GLEngine
{
	class FileIO
	{
	public: 
		static FILE* GetFilePointer(String path, String mode)
		{
			FILE* FilePointer; 

			try
			{
				if ((FilePointer = fopen(path, mode)) == nullptr)
					throw new FileNotFoundException();	
			}
			catch (const FileNotFoundException& e)
			{
				Debug->Log(e.Message);
			}
		
			return FilePointer; 
		}

		static bool Write(String data, String path)	//	Writes data to the provided file
		{
			FILE* FilePointer = FileIO::GetFilePointer(path, "w");

			fprintf(FilePointer, "%s", data);

			return (FilePointer != nullptr);	//	successful representation(true) when the file pointer is not nullpte
		}

		static String Read(String path)
		{
			FILE* FilePointer = FileIO::GetFilePointer(path, "r"); 
			
			long BufferSize;	// File conten byte size

			String Buffer; //	buffer to store read bytes in		

			//	Getting buffer size
			fseek(FilePointer, 0, SEEK_END);

			BufferSize = ftell(FilePointer);

			fseek(FilePointer, 0, SEEK_SET);

			Buffer = (String)malloc(BufferSize + 1);	//	Allocating the buffer
			
			//	Reading bytes
			fread(Buffer, 1, BufferSize, FilePointer);
			fclose(FilePointer); 

			Buffer[BufferSize] = 0;	//	Sets the EOF

			return Buffer;
		}
	}; 
};	