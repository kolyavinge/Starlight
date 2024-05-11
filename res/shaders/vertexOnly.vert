#version 330 compatibility

layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * vec4(aPos, 1.0);
}
