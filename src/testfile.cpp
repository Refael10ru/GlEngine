#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

enum Shader
{
	Vertex,
	Fragment
};


unsigned int GenerateVertexBufferObject(float* array, int size);
unsigned int GenerateVertexArrayObject(int);
unsigned int CreateShader(Shader);
unsigned int LinkShaders(unsigned int, unsigned int);
unsigned int GenerateShaders();

void CompileShader(unsigned int);
void FrameBufferSizeCallBack(GLFWwindow*, int, int);
void Render(float*, int);	//renders a vertex matrix'
void SetupObjects(unsigned int, unsigned int);
void AddBufferData(float*, int);


GLFWwindow* CreateWindow(int, int , char*);

unsigned int LinkedShaderID;

char** ShaderStrings = new char*[2]{
	"#verison core 330\n"
	"layout (location = 0) in vec3\n"
	"void main()\n"
	"{\n" 
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);"
	"}\0", 

	"#version core 330\n"
	"void main()\n"
	"{\n"
	"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}"
};

unsigned int* Shaders = new unsigned int[2];

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwMakeContextCurrent(CreateWindow(480, 640, "Hello World "));	//	creates a window and makes it the current context

	//	Initializing GLEW
	glewExperimental =  GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Glew couldn't be initialized.");

		return -1;
	}   

	glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallBack);	

	float vertexMatrix[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};
	
	Render(vertexMatrix, sizeof(vertexMatrix));

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
	
		glClearColor(0.5f, 0.3f, 0.3f, 0.0f);
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

GLFWwindow* CreateWindow(int height, int width, char* title)
{
	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!window) 
	{
		glfwTerminate();

		return NULL;
	}

	return window;
}

int GenerateVertexBufferObject(int size)
{
	unsigned int BufferID;

	glGenBuffers(size, &BufferID);

	return BufferID;
}

unsigned int CreateShader(Shader shader)
{
	GLenum args[] = {
		GL_VERTEX_SHADER, 
		GL_FRAGMENT_SHADER
	};

	bool generationSuccess;

	char logs[512];

	unsigned int GeneratedShader = glCreateShader(args[(int)shader]); 

	glShaderSource(GeneratedShader, 1, &ShaderStrings[(int)shader], NULL);
	glCompileShader(GeneratedShader);

	glGetShaderiv(GeneratedShader, GL_COMPILE_STATUS, (int*)(&generationSuccess));
	
	if (!generationSuccess)
	{	
		glGetShaderInfoLog(GeneratedShader, GL_COMPILE_STATUS, (int*)(&generationSuccess), NULL);
		
		printf("%s", logs);
	}
	return GeneratedShader;
}


unsigned int LinkShaders(unsigned int shader, unsigned int shader1)
{
	unsigned int ShaderProgram = glCreateProgram();

	char log[512];

	bool linkSuccess;

	glAttachShader(ShaderProgram, shader);
	glAttachShader(ShaderProgram, shader1);

	glLinkProgram(ShaderProgram);

	glGetProgramiv(ShaderProgram, GL_LINK_STATUS,(int*)(&linkSuccess));


	if (!linkSuccess)
	{
		glGetProgramInfoLog(ShaderProgram, sizeof(log), NULL, log);

		printf("%s", log);
	}

	for (int x = 0; x < 2; x++) // deletes the individually allocated shaders
		glDeleteShader(Shaders[x]);

	return ShaderProgram;
}

unsigned int GenerateVertexArrayObject(int size)	// returns the vertex array object
{
	unsigned int VertexArrayObject;
	
	glCreateVertexArrays(size, &VertexArrayObject);

	return VertexArrayObject; 
}	

void Render(float* vertexMatrix, int arraySize)
{
	unsigned int VAO, VBO;

	SetupObjects((VAO = GenerateVertexArrayObject(1)), (VBO =GenerateVertexBufferObject(1)));
	AddBufferData(vertexMatrix, arraySize);	

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glUseProgram(GenerateShaders());
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void AddBufferData(float* vertexMatrix, int arraySize)
{
	glBufferData(GL_ARRAY_BUFFER, arraySize, vertexMatrix, GL_STATIC_DRAW);
}

void SetupObjects(unsigned int vertexArrayObject, unsigned int vertexBufferObject)
{
	glBindVertexArray(vertexArrayObject = GenerateVertexArrayObject(1));
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject = GenerateVertexBufferObject(1));
}

unsigned int GenerateShaders()
{
	unsigned int shaderIDs[2];

	for (int x = 0; x < 2; x++)
		shaderIDs[x] = CreateShader((Shader)x);

	return (LinkedShaderID = LinkShaders(shaderIDs[0], shaderIDs[1]));
}