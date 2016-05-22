//=======================================================================================================================|
// Created 2013.12.17 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_CAMERA_H
#define _glz_CAMERA_H

#include "World.h"


namespace glz
{
	namespace world
	{
		class World;

		/**
		 * Represents a camera that can visualize a portion of a World. The camera can either track
		 * a target entity or move around with its own world-space coordinates. It centers itself
		 * on the position.
		 */
		class Camera
		{
		private:
			Vec2d mWorldPos;
			World *mWorld;
			int mTarget = 0;

		public:
			explicit Camera(World *world) { mWorld = world; }

			void draw() const;
			void move(double x, double y) { mWorldPos.add(x, y); }

			void setWorldPos(Vec2d worldPos) { mWorldPos = worldPos; }
			Vec2d getWorldPos() const { return mWorldPos; }

			void setTarget(int target) { mTarget = target; }
			int getTarget() const
			{
				return mTarget;
			}
		};
	};
};

#endif

