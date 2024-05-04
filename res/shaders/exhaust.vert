#version 330 compatibility

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTexCoord;

uniform float lengthRate;

out vec2 TexCoord;

void main()
{
	vec3 newPos = vec3(aPos.x, aPos.y * lengthRate, aPos.z);
    gl_Position = gl_ModelViewProjectionMatrix * vec4(newPos, 1.0);
    TexCoord = aTexCoord;
}
