//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_DRAWABLE_H
#define _glz_DRAWABLE_H

#include "Component.h"
#include "../../Render/Render.h"

namespace glz
{
	namespace world
	{
		class Drawable : public Component
		{
		private:
			Mesh2D mMesh;
			OpenGLWindow *mWindow;

			Drawable() { }

		public:
			Drawable(String meshFilepath, OpenGLWindow *window);
			~Drawable() {}

			void update() {}
			void draw(Float x, Float y);
			Component *clone();
		};
	};
};

#endif

