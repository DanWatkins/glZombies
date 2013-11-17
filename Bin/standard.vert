#version 440 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

smooth out vec4 fragColor;

uniform vec2 offset;
uniform mat4 perspectiveMatrix;

void main()
{
	vec4 cameraPos = position + vec4(offset.x, offset.y, 0.0, 0.0);

	gl_Position = perspectiveMatrix * cameraPos;
	fragColor = color;
}