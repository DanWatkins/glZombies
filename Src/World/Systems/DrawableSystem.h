//=======================================================================================================================|
// Created 2013.12.23 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_DRAWABLE_SYSTEM_H
#define _glz_DRAWABLE_SYSTEM_H

#include "System.h"
#include "../Components/Drawable.h"


namespace glz
{
	namespace world
	{
		class DrawableSystem : public System
		{
		private:
			glz::OpenGLWindow *mWindow;  //TODO the glz:: should not be necessary

		protected:
			DrawableSystem() {}


		public:
			DrawableSystem(OpenGLWindow *window);
			void createDrawable(Int entity, String meshFilepath);

			Shared<Drawable> getDrawableForEntity(Int entity);
		};
	};
};

#endif

