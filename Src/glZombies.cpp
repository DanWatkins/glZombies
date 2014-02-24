//=======================================================================================================================|
// Created 2013.11.16 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "glZombies.h"
#include "./Core/Core.h"
#include "./World/World.h"


std::thread luaBackground;

void initLua()
{
	std::string buffer = "a=10";
	Int error;

	lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);


	while (buffer != "exit")
	{
		std::cin >> buffer;
		
		error = luaL_loadstring(lua, buffer.c_str()) || lua_pcall(lua, 0, 0, 0);
		
		if (error)
		{
			std::cout << lua_tostring(lua, -1);	
			lua_pop(lua, 1);	
		}
	}
};


namespace glz
{	
	glZombies::glZombies() : mWorld(this), mCamera(&mWorld)
	{
	}

	
	void glZombies::onStartup()
	{
		luaBackground = std::thread(initLua);

		loadShaders();

		mWorld.init();
		mWorld.loadWorldFile("main.world");
		
	}

	
	void glZombies::onUpdate(Double currentTime)
	{
		static const Float clearColor[] = { 1.0f, 1.0f, 0.9f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, clearColor);

		mWorld.update();
		mCamera.draw();
	}


	void glZombies::onKey(Int key, Int action)
	{
		switch (key)
		{
			case GLFW_KEY_ESCAPE:
			{
				terminate();
			}
			case GLFW_KEY_A:
			{
				mCamera.move(-0.1, 0.0);
				break;
			}
			case GLFW_KEY_W:
			{
				mCamera.move(-0.0, -0.1);
				break;
			}
			case GLFW_KEY_D:
			{
				mCamera.move(0.1, 0.0);
				break;
			}
			case GLFW_KEY_S:
			{
				mCamera.move(0.0, 0.1);
				break;
			}
			case GLFW_KEY_EQUAL:
			{
				addZoom(Vec2f(0.005f, 0.005f));
				break;
			}
			case GLFW_KEY_M:
			{
				addZoom(Vec2f(-0.005f, -0.005f));

				break;
			}
		}
	}

	
	void glZombies::onResize(Int width, Int height)
	{
		glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	}


	void glZombies::onTerminate()
	{
		luaBackground.detach();
	}


	void glZombies::loadShaders()
	{
		Uint shaders[2];
		shaders[0] = Shader::loadShader("standard.vert", GL_VERTEX_SHADER);
		shaders[1] = Shader::loadShader("standard.frag", GL_FRAGMENT_SHADER);

		mProgram = Shader::linkFromShaders(shaders, 2);
	}
};