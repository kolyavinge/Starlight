#version 330 compatibility

in vec3 Pos;
in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;

uniform vec3 lightPos;
uniform vec3 cameraPos;
uniform float alpha;
uniform sampler2D ourTexture;

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
		shadow = 1.0;
	}

    FragColor = texture(ourTexture, TexCoord) * lightColor * (shadow * (diffuse + specular) + ambient);
	FragColor.w = alpha;
}
