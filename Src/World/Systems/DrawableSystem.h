//=======================================================================================================================|
// Created 2013.12.23 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_DRAWABLE_SYSTEM_H
#define _glz_DRAWABLE_SYSTEM_H

#include "System.h"
#include "../Components/Drawable.h"


namespace glz
{
	namespace world
	{
		/**
		 * Represents a drawable system that manages Drawable components which can be drawn by
		 * a Camera instance.
		 */
		class DrawableSystem : public System
		{
		private:
			OpenGLWindow *mWindow;

		protected:
			DrawableSystem() {}


		public:
			friend Camera;
			DrawableSystem(OpenGLWindow *window);

			void createDrawable(Int entity, String meshFilepath);
			void update() {}
		};


		class DrawableSystemUser
		{
		protected:
			DrawableSystem *mDrawableSystem;
		};
	};
};

#endif

