#version 330

layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoord;

uniform mat4 modelProjection;

out vec2 texCoord0;

void main()
{
    gl_Position = modelProjection * vec4(position.x, position.y, 0.0, 1.0);
    texCoord0 = texCoord;
}
