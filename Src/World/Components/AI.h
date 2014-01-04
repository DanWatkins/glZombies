//=======================================================================================================================|
// Created 2013.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_AI_H
#define _glz_AI_H

#include "Spatial.h"
#include "SteeringBehaviors.h"

namespace glz
{
	namespace world
	{
		/**
		 * Represents an artificial intelligence component. It uses SteeringBehaviors to
		 * get the entity to do certain actions.
		 */
		class AI : public Component
		{
		private:
			SteeringBehaviors mSteeringBehaviors;

			void update(Double timeDelta);

		public:
			AI(Weak<Spatial> spatial);
		};
	};
};


#endif

