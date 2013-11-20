//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "glZombies.h"
#include "Shader.h"

namespace glz
{
	//==================================================================|
	glZombies::glZombies()
	{
		mProgram = -1;
	}


	//==================================================================|
	void glZombies::startup()
	{
		loadShaders();

		mMeshes.push_back(Mesh2D());
		mMeshes.front().loadFromFile("zombie.glzm2");
		//mMeshes.front().setNdcPos(Vec2<Float>(-1.0, -1.0));
	}


	//==================================================================|
	void glZombies::update(Double currentTime)
	{
		static const Float clearColor[] = { 1.0f, 1.0f, 0.9f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, clearColor);

		mMeshes.front().draw(mProgram);
	}


	//==================================================================|
	void glZombies::onKey(int key, int action)
	{
		switch (key)
		{
			case GLFW_KEY_ESCAPE:
			{
				exit(0);  //TODO do better with this lol
			}

			case GLFW_KEY_LEFT:
			{
				mMeshes.front().addRotation(-0.025f);
				break;
			}
			case GLFW_KEY_RIGHT:
			{
				mMeshes.front().addRotation(0.025f);
				break;
			}
		}
	}


	//==================================================================|
	void glZombies::terminate()
	{
	}


	//==================================================================|
	void glZombies::loadShaders()
	{
		Uint shaders[2];
		shaders[0] = Shader::loadShader("standard.vert", GL_VERTEX_SHADER);
		shaders[1] = Shader::loadShader("standard.frag", GL_FRAGMENT_SHADER);

		mProgram = Shader::linkFromShaders(shaders, 2);
	}
};