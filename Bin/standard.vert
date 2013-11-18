#version 430 core

layout (location = 0) in vec4 position;

uniform vec4 offset;

void main()
{
	
	gl_Position = position + offset;
}