const char* vertex_shader2 =
    "#version 400\n"
    "layout (location = 0) in vec3 aPos;"
    "layout (location = 1) in vec3 Color;"
    "out vec3 vertexColor;"
    "out vec3 vertexPosition;"
    "void main()"
    "{"
    "    vertexPosition = aPos;"
    "    vertexColor = Color;"
    "}";

const char* fragment_shader2 =
"#version 400\n"
"uniform vec4 ourColor"

"out vec4 frag_colour;"

"void main() {"
"  frag_colour = ourColor"
"}";
const char* fragment_shader =
"#version 400\n"
// position attribute
"out vec4 FragColor;"
"in vec3 ourColor;"
  
"void main()"
"{"
"    FragColor = vec4(ourColor, 1.0);"
"}";

const char* vertex_shader =
"#version 400\n"
"layout (location = 0) in vec3 aPos;"
"out vec4 vertexColor;"
"void main()"
"{"
"    gl_Position = vec4(aPos, 1.0);"
"    vertexColor = vec4(0.5, 0.0, 0.0, 1.0);"
"}";

const char* RotationXY =
"#version 400\n"
"layout (location = 0) in vec3 aPos;"
"out vec4 vertexColor;"
"void main()"
"{"
"    gl_Position = vec4(aPos, 1.0);"
"    vertexColor = vec4(0.5, 0.0, 0.0, 1.0);"
"}";
