//=======================================================================================================================|
// Created 2013.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_AI_H
#define _glz_AI_H

#include "../Spatial.h"
#include "../Details.h"
#include "SteeringBehaviors.h"
#include "AIScript.h"

namespace glz
{
	namespace world
	{
		class AISystem;

		/**
		 * Represents an artificial intelligence component. It uses SteeringBehaviors to
		 * get the entity to do certain actions.
		 */
		class AI : public Component, DetailsUser, SpatialUser
		{
		private:
			SteeringBehaviors mSteeringBehaviors;
			AIScript mScript;
			sf::Clock mTimeDelta;

			void init() override;
			void update() override;

			int mTimesUpdated = 0;

		public:
			friend AISystem;
			friend AIScript;
			friend AIScriptRelay;
			friend SteeringBehaviors;

			AI(Details *details, Spatial *spatial);
		};

		class AIUser
		{
		protected:
			AI *mAI = nullptr;
		};
	};
};


#endif

