//=======================================================================================================================|
// Created 2013.11.23 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
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


		void Drawable::draw(Float x, Float y)
		{
			mMesh.setNdcPos(Vec2f(x,y));
			mMesh.draw(mWindow);
		}


		void Drawable::draw(Float x, Float y, OpenGLWindow *window)
		{
			mMesh.setNdcPos(Vec2f(x,y));
			mMesh.draw(window);
		}
	};
};