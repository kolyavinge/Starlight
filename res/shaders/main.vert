#version 420 compatibility

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

out vec3 Pos;
out vec3 Normal;
out vec2 TexCoord;
out vec4 ShadowCoord1;
out vec4 ShadowCoord2;
out vec4 ShadowCoord3;
out vec4 ShadowCoord4;
out vec4 ShadowCoord5;

uniform mat4 modelMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 shadowMatrix1;
uniform mat4 shadowMatrix2;
uniform mat4 shadowMatrix3;
uniform mat4 shadowMatrix4;
uniform mat4 shadowMatrix5;

void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * vec4(aPos, 1.0);
    Pos = vec3(modelViewMatrix * vec4(aPos, 1.0));
    Normal = normalize(mat3(modelViewMatrix) * aNormal);
    TexCoord = aTexCoord;
    ShadowCoord1 = shadowMatrix1 * modelMatrix * vec4(aPos, 1.0);
    ShadowCoord2 = shadowMatrix2 * modelMatrix * vec4(aPos, 1.0);
    ShadowCoord3 = shadowMatrix3 * modelMatrix * vec4(aPos, 1.0);
    ShadowCoord4 = shadowMatrix4 * modelMatrix * vec4(aPos, 1.0);
    ShadowCoord5 = shadowMatrix5 * modelMatrix * vec4(aPos, 1.0);
}
