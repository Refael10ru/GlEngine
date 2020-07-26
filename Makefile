build: src/*
	g++ -o gltest src/* -g -Iinclude -lGL -lGLU -lglfw 

headers:
	g++ include/*.h 

clear:
	rm gltest include/*.gch
