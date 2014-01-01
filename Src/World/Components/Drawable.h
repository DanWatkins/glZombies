//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_DRAWABLE_H
#define _glz_DRAWABLE_H

#include "Component.h"
#include "../../Render/Render.h"

namespace glz
{
	namespace world
	{
		/**
		 * Represents a Component to visualize something using a Mesh2D
		 */
		class Drawable : public Component
		{
		private:
			Mesh2D mMesh;
			OpenGLWindow *mWindow;

			Drawable() {}

		public:
			Drawable(String meshFilepath, OpenGLWindow *window);
			~Drawable() {}

			void update(Double timeDelta) {}

			void draw(Float x, Float y);
			void draw(Float x, Float y, OpenGLWindow *window);
		};
	};
};

#endif

