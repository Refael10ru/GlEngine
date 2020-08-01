build: src/*
	make headers; 
	make source; 	

source:
	g++ src/*.cpp -g -Iinclude -lGL -lGLU -lglfw

objects:
	g++ src/*.cpp -g -Iinclude -lGL -lGLU -lglfw

headers:
	g++ include/*.h 

clear:
	rm gltest include/*.gch a.out

test:	 
	g++  src/testfile.cpp -g -Iinclude -lGL -lGLU -lglfw -lGLEW -o bin/test
$(ObjectFile)%.o: $(SourceFiles)%.ppp 
