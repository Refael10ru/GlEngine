const char* vertex_shader2 =
"#version 400\n"
"in vec3 vp;"
"void main() {"
"  gl_Position = vec4(vp, 1.0);"
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
"out vec4 FragColor;"

"uniform vec4 ourColor;"

"void main()"
"{"
"   FragColor = ourColor;"
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
