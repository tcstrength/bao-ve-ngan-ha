#version 330

in vec2 texCoord0;

uniform vec4 color0;
uniform sampler2D sampler0;

out vec4 fragColor;

void main()
{
    vec4 texColor = color0 * texture(sampler0, texCoord0);
    if (texColor.a < 0.1)
        discard;
    fragColor = texColor;
}
