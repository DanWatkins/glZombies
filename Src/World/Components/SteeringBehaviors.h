//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_STEERING_BEHAVIORS_H
#define _glz_STEERING_BEHAVIORS_H

#include "Spatial.h"

namespace glz
{
	namespace world
	{
		class SteeringBehaviors
		{
		private:
			Weak<Spatial> mSpatial;


		public:
			SteeringBehaviors(Weak<Spatial> spatial);

		};
	};
};

#endif

