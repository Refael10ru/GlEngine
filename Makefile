build: src/test/test.cpp	
	g++ -o gltest src/test/test.cpp -g -Iinclude -lGL -lGLU -lglfw -lglew 

clear:
	rm gltest
