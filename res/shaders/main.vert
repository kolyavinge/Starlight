#version 330 compatibility

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

out vec3 Pos;
out vec3 Normal;
out vec2 TexCoord;
out vec4 ShadowCoord;

uniform mat4 modelMatrix;
uniform mat4 shadowMatrix;

void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * vec4(aPos, 1.0);
    Pos = vec3(modelMatrix * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(modelMatrix))) * aNormal;
    TexCoord = aTexCoord;
    ShadowCoord = shadowMatrix * modelMatrix * vec4(aPos, 1.0);
}
