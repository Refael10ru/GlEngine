
#include <stdio.h>
#include <cmath>
#include "ColoredMesh.h"
#include "TexturedMesh.h"

//--------GLOBAL-VARIBALES--------->

std::string PathToBin;

//--------GLOBAL-VARIBALES--------->

void FrameBufferSizeCallBack(GLFWwindow* window, int height, int width)
{ glViewport(0, 0, height, width);  }  
int main(int argc, char** argv ) 
{
  //--------------------------------->
  PathToBin = argv[0];
  for(int i = PathToBin.length()-1 ; i >= 0; i--)
    if(*(&PathToBin[i]) == '/')
    {
      PathToBin.resize(i+1);
      break;
    }
  //--------------------------------->
  
  //Writes program params for testing
  std::cout << "Program args:" << argc << "\n";
  for(int i = 0; i < argc; i++)
    std::cout << argv[i] << "\n";

  // start GL context and O/S window using the GLFW helper library
  if (!glfwInit()) {
    fprintf(stderr, "ERROR: could not start GLFW3\n");
    return 1;
  } 

  // these make Apple OS X happy
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(640, 480, "GLEngine", NULL, NULL);
  if (!window) {
    fprintf(stderr, "ERROR: could not open window with GLFW3\n");
    glfwTerminate();
    return 1;
  }

  glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallBack);

  glfwMakeContextCurrent(window);

  // start GLEW extension handler
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    getchar();
    glfwTerminate();
    return -1;
  }

  /*
  // get version info
  const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
  const GLubyte* version = glGetString(GL_VERSION); // version as a string
  printf("Renderer: %s\n", renderer);
  printf("OpenGL version supported %s\n", version);*/

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


  float ColoredVertices[] = {
    // positions         // colors
     1.0f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   // top 
    -0.5f,  0.5f, 0.0f,  0.5f, 0.5f, 0.5f,
     0.0f,  1.0f, 0.0f,  0.0f, 1.0f, 1.0f,
     1.0f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f  
  };    
  float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
  };
  unsigned int indices[] = {  // note that we start from 0!
    0, 1, 2,   // first triangle
    1, 2, 3,   // second triangle
    2, 3, 4,   // third triangle
    2, 3, 4    // forth triangle
  }; 
  float texCoords[] = {
    0.0f, 0.0f,  // lower-left corner  
    1.0f, 0.0f,  // lower-right corner
    0.5f, 1.0f   // top-center corner
  };
  
  okek::ColoredMesh mesh(ColoredVertices ,5 ,indices, 3);
  mesh.InitializeOnGPU();

  okek::Shader ourShader(PathToBin ,"../Shaders/ColoredMesh.vs",
   "../Shaders/ColoredMesh.fs");


  for(int i = 0; i < 5; i++)
    mesh.debug1(i);


  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  while(!glfwWindowShouldClose(window)) 
  {

    // render
    // clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // be sure to activate the shader
    //glUseProgram(shaderProgram);

    ourShader.use();
  
    // update the uniform color
    float timeValue = glfwGetTime();
    float redValue = sin(timeValue) / 2.0f + 0.5f;
    float greenValue = sin(timeValue+1) / 2.0f + 0.5f;
    float blueValue = sin(timeValue+2) / 2.0f + 0.5f;

    ourShader.setfvec3("inputColor", redValue, greenValue, blueValue);

    // now render the triangle
    //glBindVertexArray(VAO);
    mesh.use();
    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
  
    // swap buffers and poll IO events
    glfwSwapBuffers(window);
    glfwPollEvents();

  }

  // close GL context and any other GLFW resources
  glfwTerminate();
  return 0;
}