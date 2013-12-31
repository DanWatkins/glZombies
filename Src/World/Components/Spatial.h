//=======================================================================================================================|
// Created 2013.12.24 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_SPATIAL_H
#define _glz_SPATIAL_H

#include "Component.h"

namespace glz
{
	namespace world
	{
		/**
		 * Represents a Component that keeps track of a spatial body.
		 */
		 class Spatial : public Component
		 {
		 private:
			 Vec2d mPos;

		 public:
			 Spatial(Vec2d pos) { mPos = pos; }
			 
			 void setPos(Vec2d pos) { mPos = pos; }
			 void addPos(Vec2d pos) { mPos += pos; }
			 Vec2d getPos() { return mPos; }
		 };
	};
};

#endif

