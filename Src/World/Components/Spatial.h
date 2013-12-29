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
		 class Spatial : public Component
		 {
		 private:
			 Vec2d mPos;		//position in world space
			 //Rect mBody;		//bounds (may not need mPos, idk)

		 public:
			 Spatial(Vec2d pos) { mPos = pos; }
			 
			 
			 void setPos(Vec2d pos) { mPos = pos; }
			 void addPos(Vec2d pos) { mPos += pos; }
			 Vec2d getPos() { return mPos; }

			 
		 };
	};
};

#endif

