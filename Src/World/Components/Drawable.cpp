//=======================================================================================================================|
// Created 2013.11.23 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Drawable.h"


namespace glz
{
	namespace world
	{
		Drawable::Drawable(String meshFilepath, OpenGLWindow *window)
		{
			mMesh.loadFromFile(meshFilepath);
			mWindow = window;
		}


		void Drawable::draw(float x, float y, float rotation)
		{
			mMesh.draw(mWindow, x, y, rotation);
		}


		void Drawable::draw(OpenGLWindow *window, float x, float y, float rotation)
		{
			mMesh.draw(window, x, y, rotation);
		}
	};
};