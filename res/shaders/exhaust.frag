#version 330 compatibility

in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main()
{
	vec2 texCoord1 = TexCoord;
	vec2 texCoord2 = TexCoord;
	texCoord2.y += 0.5;
	if (texCoord2.y > 1.0) texCoord2.y -= 1.0;

    FragColor =
		texture(ourTexture, texCoord1) +
		texture(ourTexture, texCoord2);

	FragColor.w = (FragColor.x + FragColor.y + FragColor.z) / 4.0;
}
