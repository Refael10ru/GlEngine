build: src/*
	make headers; 
	make source; 	

source:
	g++ -o gltest src/*.cpp -g -Iinclude -lGL -lGLU -lglfw

headers:
	g++ include/*.h 

clear:
	rm gltest include/*.gch */a.out
