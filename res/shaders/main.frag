#version 420 compatibility

in vec3 Pos;
in vec3 Normal;
in vec2 TexCoord;
in vec4 ShadowCoord1;
in vec4 ShadowCoord2;
in vec4 ShadowCoord3;
in vec4 ShadowCoord4;
in vec4 ShadowCoord5;

out vec4 FragColor;

uniform vec3 lightPos;
uniform float alpha;
layout (binding = 0) uniform sampler2D ourTexture;
layout (binding = 1) uniform sampler2DShadow shadowTexture1;
layout (binding = 2) uniform sampler2DShadow shadowTexture2;
layout (binding = 3) uniform sampler2DShadow shadowTexture3;
layout (binding = 4) uniform sampler2DShadow shadowTexture4;
layout (binding = 5) uniform sampler2DShadow shadowTexture5;

void main()
{
    vec4 lightColor = vec4(1.0, 1.0, 1.0, 1.0);
    float ambient = 0.2f;
    vec3 s = normalize(lightPos - Pos);
    float sDotN = max(dot(s, Normal), 0.0);
    float diffuse = 1.0 * sDotN;
    float specular = 0.0;
    if (sDotN > 0.0)
    {
        vec3 v = normalize(-Pos);
        vec3 h = normalize(v + s);
        float hDotN = max(dot(h, Normal), 0.0);
        specular = 0.5 * pow(hDotN, 8.0);
    }

    float shadow = 0.0;
    if (gl_FrontFacing)
    {
        float shadow1 = textureProj(shadowTexture1, ShadowCoord1);
        float shadow2 = textureProj(shadowTexture2, ShadowCoord2);
        float shadow3 = textureProj(shadowTexture3, ShadowCoord3);
        float shadow4 = textureProj(shadowTexture4, ShadowCoord4);
        float shadow5 = textureProj(shadowTexture5, ShadowCoord5);
        shadow = min(min(min(shadow1, shadow2), min(shadow3, shadow4)), shadow5);
    }

    FragColor = texture(ourTexture, TexCoord) * lightColor * (shadow * (diffuse + specular) + ambient);
    FragColor.w = alpha;
}
