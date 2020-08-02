

#include "shaders.h"
#include "ColoredMesh.h"
#include "TexturedMesh.h"
#include "Texture2D.h"
#include "TexturedOBJ.h"
#include "camera.h"

#include <string>
#include <cmath>
#include <vector>

#define PI 3.141592f

//--------GLOBAL-VARIBALES--------->

okek::camera player = okek::camera(glm::vec3(0,0,4));
glm::mat4 projection;
int Width = 600;
int Height = 480;
std::string PathToBin;
float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0;

//--------GLOBAL-VARIBALES--------->

void ProcessInputHandle(GLFWwindow* window)
{ 
  
  float cameraSpeed = 4.5f * deltaTime;
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
      player.position += cameraSpeed * player.rotation;
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
      player.position -= cameraSpeed * player.rotation;
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
      player.position -= glm::normalize(glm::cross(player.rotation, player.up)) * cameraSpeed;
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
      player.position += glm::normalize(glm::cross(player.rotation, player.up)) * cameraSpeed;

  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, true);

  
  
}

void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{ glViewport(0, 0, width, height );Width = width;Height = height;  }  

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

  GLFWwindow* window = glfwCreateWindow(Width, Height, "GLEngine", NULL, NULL);
  if (!window) {
    fprintf(stderr, "ERROR: could not open window with GLFW3\n");
    glfwTerminate();
    return 1;
  }

  glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallBack);

  //glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  //glfwSetKeyCallback(window, ProcessInputHandle);

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
  

  float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};



  unsigned int indices[] = {  // note that we start from 0!
    0, 1, 2,  
    3, 4, 5,
    6, 7, 8,
    9,10,11,
    12,13,14,
    15,16,17,
    18,19,20,
    21,22,23,
    24,25,26,
    27,28,29,
    30,31,32,
    33,34,35
  }; 

  glm::vec3 cubepositions[] = {
    glm::vec3( 0.0f,  0.0f,  0.0f), 
    glm::vec3( 2.0f,  5.0f, -15.0f), 
    glm::vec3(-1.5f, -2.2f, -2.5f),  
    glm::vec3(-3.8f, -2.0f, -12.3f),  
    glm::vec3( 2.4f, -0.4f, -3.5f),  
    glm::vec3(-1.7f,  3.0f, -7.5f),  
    glm::vec3( 1.3f, -2.0f, -2.5f),  
    glm::vec3( 1.5f,  2.0f, -2.5f), 
    glm::vec3( 1.5f,  0.2f, -1.5f), 
    glm::vec3(-1.3f,  1.0f, -1.5f)  
  };
  
  okek::OTexturedMesh tmesh(vertices, 36, indices, 12);
  tmesh.InitializeOnGPU();

  

  okek::Shader TexturedmeshS(PathToBin ,"../Shaders/TexturedMesh.vs",
   "../Shaders/TexturedMesh.fs");

  okek::Texture2D texture1(PathToBin , "../resources/container.jpg", GL_RGB);
  texture1.MoveToGPU();
  okek::Texture2D texture2(PathToBin , "../resources/awesomeface.png", GL_RGBA);
  texture2.MoveToGPU();

  //-------------------------------------------------->
  okek::TexturedOBJ obj = okek::TexturedOBJ(&TexturedmeshS, &texture1, &tmesh);
  //-------------------------------------------------->

  std::vector<okek::TexturedOBJ> vecOBJ = std::vector<okek::TexturedOBJ>();

  for(unsigned int i = 0; i < 10; i++)
  {
    //glm::mat4 model = glm::mat4(1.0f);
    //model = glm::translate(model, cubeplayer.positions[i]);
    //float angle = 20.0f * i; 
    //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

    vecOBJ.push_back(okek::TexturedOBJ(&TexturedmeshS, &texture1, &tmesh, cubepositions[i]));
    
  }

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST); 

  while(!glfwWindowShouldClose(window)) 
  {

    // render
    // clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // be sure to activate the shader
    //glUseProgram(shaderProgram);

    TexturedmeshS.use();
    texture1.use(1);
    texture2.use(0);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 
    
    //model = obj.GetTMatrix();
    // note that we're translating the scene in the reverse direction of where we want to move
    //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.0f));
    view = player.GetMatrix(); 
    //Height / (float)Width
    projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(20.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(30.0f), glm::vec3(1.0f, 1.0f, 0.0f));
    TexturedmeshS.setInt("texture1", 0);
    TexturedmeshS.setInt("texture2", 1);

    const float radius = 10.0f;
    float camX = sin(glfwGetTime()) * radius;
    float camZ = cos(glfwGetTime()) * radius;
    //view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
    
    TexturedmeshS.setMat4f("view", view);
    TexturedmeshS.setMat4f("projection", projection);
    //TexturedmeshS.setMat4f("model", model);
    for(unsigned int i = 0; i < vecOBJ.size(); i++)
    {
      float angle = 20.0f * i; 
      glm::mat4 model = vecOBJ[i].GetTMatrix();
      if(i%3!=0)
      {
      angle +=  (float)glfwGetTime() *60.0f;
      }
      else
      {
      angle +=  (float)glfwGetTime() *40.0f;
      }
      
      model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
      TexturedmeshS.setMat4f("model", model);

      glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        
    }
      float currentFrame = glfwGetTime(); 
      deltaTime = currentFrame - lastFrame;
      lastFrame = currentFrame; 

    // swap buffers and poll IO events
    glfwSwapBuffers(window);
    glfwPollEvents();
    ProcessInputHandle(window);

  }
  glfwTerminate();
  return 0;
  
  // close GL context and any other GLFW resources
};