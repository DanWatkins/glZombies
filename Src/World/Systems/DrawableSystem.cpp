//=======================================================================================================================|
// Created 2013.12.23 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "DrawableSystem.h"

namespace glz
{
	namespace world
	{
		DrawableSystem::DrawableSystem(OpenGLWindow *window)
		{
			mWindow = window;
		}


		void DrawableSystem::createDrawable(Int entity, String meshFilepath)
		{
			addComponent(entity, new Drawable(meshFilepath, mWindow));
		}
	};
};