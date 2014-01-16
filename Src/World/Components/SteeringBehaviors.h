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
		enum class SteeringBehavior
		{
			Seek			= 001,
			Evade			= 002
		};


		struct SteeringBehaviorRequest
		{
			SteeringBehavior behavior;
			Vec2d force;
		};

		typedef std::list<SteeringBehaviorRequest> SteeringBehaviorList;


		/**
		 * Combines various steering behaviors to provide a net steering force.
		 * Calls to various behaviors such as Seek() cause a SteeringBehavior
		 * request to be added to a list of requests. Then ComputeSteeringForce()
		 * goes through the list and combines all the requests to provide a net
		 * steering force. The list of requests should be cleared at the start
		 * of the overall system's update cycle.
		 */
		class SteeringBehaviors
		{
		private:
			Spatial *mSpatial;
			SteeringBehaviorList mSteeringBehaviorList;
			Vec2d mSteeringForce;

		public:
			SteeringBehaviors(Spatial *spatial);

			Vec2d ComputeSteeringForce();

			void Seek(Vec2d pos);
		};
	};
};

#endif

