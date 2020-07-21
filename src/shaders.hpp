const char* vertex_shader =
"#version 400\n"
"in vec3 vp;"
"void main() {"
"  gl_Position = vec4(vp, 1.0);"
"}";
const char* fragment_shader =
"#version 400\n"
"out vec4 frag_colour;"
"void main() {"
"  frag_colour = vec4(0.9, 1.0, 0.5, 1.0);"
"}";