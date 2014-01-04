//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "SteeringBehaviors.h"

namespace glz
{
	namespace world
	{
		SteeringBehaviors::SteeringBehaviors(Weak<Spatial> spatial)
		{
			mSpatial = spatial;
		}
	};
};