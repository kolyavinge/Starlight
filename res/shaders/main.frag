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
uniform vec3 cameraPos;
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

    vec3 lightDirection = normalize(lightPos - Pos);
    float diffuse = max(dot(Normal, lightDirection), 0.0f);

    float specularLight = 0.5f;
    vec3 viewDirection = normalize(cameraPos - Pos);
    vec3 reflectionDirection = reflect(-lightDirection, Normal);
    float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8);
    float specular = specAmount * specularLight;

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
