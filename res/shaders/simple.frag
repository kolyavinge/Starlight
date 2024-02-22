#version 330 core

varying vec2 texCoord;
uniform sampler2D tex;

void main()
{
    gl_FragColor = vec4(1.0, 1.0, 1.0, 0.2);
    //gl_FragColor = texture2D(tex, texCoord);
}
