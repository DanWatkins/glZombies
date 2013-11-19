#version 430 core

layout (location = 0) in vec4 position;

uniform vec4 offset;
uniform float rotation;

void main()
{
	mat4 rotationMatrix = mat4(	cos(rotation),	-sin(rotation),		0.0,	0.0,
								sin(rotation),	cos(rotation),		0.0,	0.0,
								0.0,			0.0,				1.0,	0.0,
								0.0,			0.0,				0.0,	1.0);
	
	gl_Position = (rotationMatrix * position) + offset;
}