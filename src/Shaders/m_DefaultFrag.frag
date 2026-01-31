#version 330 core
out vec4 FragColor;

uniform vec3 PartColor;

void main()
{
    FragColor = vec4(PartColor, 1.0);
}
