//=======================================================================================================================|
// Created 2013.12.17 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_CAMERA_H
#define _glz_CAMERA_H

#include "World.h"


namespace glz
{
	namespace world
	{
		class World;

		class Camera
		{
		private:
			Vec2d mWorldPos;
			World *mWorld;
			Int mTarget;

		public:
			Camera(World *world) { mWorld = world; }

			void draw();
			void move(Double x, Double y) { mWorldPos.add(x, y); }

			//accessor and mutator
			void setWorldPos(Vec2d worldPos) { mWorldPos = worldPos; }
			Vec2d getWorldPos() { return mWorldPos; }

			void setTarget(Int target) { mTarget = target; }
			Int getTarget() { return mTarget; }
		};
	};
};

#endif

