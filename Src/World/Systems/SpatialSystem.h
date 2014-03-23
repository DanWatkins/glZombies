//=======================================================================================================================|
// Created 2013.12.24 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_SPATIAL_SYSTEM_H
#define _glz_SPATIAL_SYSTEM_H

#include "System.h"
#include "../Components/Spatial.h"
#include "../EntityTemplate.h"

namespace glz
{
	namespace world
	{
		class AISystem;

		/**
		 * Represents a spatial system that manages the spatial positioning of bodies and applies
		 * simple physics to them.
		 */
		class SpatialSystem : public System
		{
		public:
			void createSpatial(Int entity, Vec2d pos, const EntityTemplate &entityTemplate);
			void update();
		};


		class SpatialSystemUser
		{
		protected:
			SpatialSystem *mSpatialSystem;
		};
	};
};


#endif

