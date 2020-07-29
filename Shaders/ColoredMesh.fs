#version 400
// position attribute
out vec4 FragColor;
in vec3 ourColor;
uniform vec3 inputColor;
void main()
{
    FragColor = vec4(ourColor/2+inputColor/2, 1.0);
}