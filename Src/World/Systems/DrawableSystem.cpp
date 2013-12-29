//=======================================================================================================================|
// Created 2013.12.23 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
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
			addComponent(entity, Shared<Drawable>(new Drawable(meshFilepath, mWindow)));
		}


		Shared<Drawable> DrawableSystem::getDrawableForEntity(Int entity)
		{
			return std::dynamic_pointer_cast<Drawable>(getComponentForEntity(entity));
		}
	};
};