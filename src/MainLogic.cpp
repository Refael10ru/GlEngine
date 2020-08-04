

#include "shaders.h"
#include "ColoredMesh.h"
#include "TexturedMesh.h"
#include "Texture2D.h"
#include "TexturedOBJ.h"
#include "Camera.h"
#include "Window.h"

#include <string>
#include <cmath>
#include <vector>

#define PI 3.141592f

//--------GLOBAL-VARIBALES--------->

okek::Camera player = okek::Camera(glm::vec3(0,0,4));
//--------GLOBAL-VARIBALES--------->


int main(int argc, char** argv ) 
{
  

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
  
  okek::Window MainWindow(argv[0], &player);
 /*
  // get version info
  const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
  const GLubyte* version = glGetString(GL_VERSION); // version as a string
  printf("Renderer: %s\n", renderer);
  printf("OpenGL version supported %s\n", version);*/

  //--------------------------------->
  
  //Writes program params for testing
  std::cout << "Program args:" << argc << "\n";
  for(int i = 0; i < argc; i++)
    std::cout << argv[i] << "\n";

  // start GLEW extension handler
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    getchar();
    glfwTerminate();
    return -1;
  }
  

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

  

  okek::Shader TexturedmeshS(MainWindow.PathToBin ,"../Shaders/TexturedMesh.vs",
   "../Shaders/TexturedMesh.fs");

  okek::Texture2D texture1(MainWindow.PathToBin , "../resources/container.jpg", GL_RGB);
  texture1.MoveToGPU();
  okek::Texture2D texture2(MainWindow.PathToBin , "../resources/awesomeface.png", GL_RGBA);
  texture2.MoveToGPU();

  //-------------------------------------------------->
  okek::TexturedOBJ obj = okek::TexturedOBJ(&TexturedmeshS, &texture1, &tmesh);
  //-------------------------------------------------->

  std::vector<okek::TexturedOBJ> vecOBJ = std::vector<okek::TexturedOBJ>();

  for(int i = 0; i < 10; i++)
  {
    //glm::mat4 model = glm::mat4(1.0f);
    //model = glm::translate(model, cubeplayer.positions[i]);
    //float angle = 20.0f * i; 
    //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

    vecOBJ.push_back(okek::TexturedOBJ(&TexturedmeshS, &texture1, &tmesh, cubepositions[i],((float)((i*3)%10)/10)+1));
    
  }

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST); 

  while(!glfwWindowShouldClose(MainWindow.window)) 
  {

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    TexturedmeshS.use();
    texture1.use(1);
    texture2.use(0);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::perspective(glm::radians(MainWindow.FOV), MainWindow.Width/MainWindow.Height, 0.1f, 100.0f);
    
    view = player.GetMatrix();
    
    TexturedmeshS.setInt("texture1", 0);
    TexturedmeshS.setInt("texture2", 1);
    
    TexturedmeshS.setMat4("view", view);
    TexturedmeshS.setMat4("projection", projection);

    for(unsigned int i = 0; i < vecOBJ.size(); i++)
    {
      float angle = 20.0f * i; 
      glm::mat4 model = vecOBJ[i].GetTMatrix();
      
      model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
      TexturedmeshS.setMat4("model", model);
      TexturedmeshS.setFloat("size",vecOBJ[i].size);
      TexturedmeshS.setVec3("viewPos", player.position); 

      glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    }

    // swap buffers and poll IO events
    glfwSwapBuffers(MainWindow.window);
    glfwPollEvents();
    MainWindow.InputHandle();
  }
  glfwTerminate();
  return 0;

};