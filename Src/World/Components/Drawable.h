//=======================================================================================================================|
// Created 2013.11.20 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_DRAWABLE_H
#define _glz_DRAWABLE_H

#include "../../Main.h"
#include "../Component.h"
#include "../../Core/Mesh2D.h"

namespace glz
{
	namespace world
	{
		class Drawable : public Component
		{
		private:
			Mesh2D mMesh;

		public:
			Drawable() {}
			~Drawable() {}
		};
	};
};

#endif

