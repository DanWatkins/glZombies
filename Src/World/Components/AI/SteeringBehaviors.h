//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_STEERING_BEHAVIORS_H
#define _glz_STEERING_BEHAVIORS_H

#include "../Spatial.h"

namespace glz
{
	namespace world
	{
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
			enum class Behavior
			{
				Seek			= 001,
				Flee			= 002,
				Arrive			= 003
			};

			struct Request
			{
				Behavior behavior;
				Vec2d force;
			};

			typedef std::list<Request> BehaviorList;

		private:
			Spatial *mSpatial;
			BehaviorList mSteeringBehaviorList;
			Vec2d mSteeringForce;

		public:
			SteeringBehaviors(Spatial *spatial);

			Vec2d computeSteeringForce();
			void clear();

			/**
			 * Generates a steering behavior request that 
			 */
			void seek(Vec2d pos);
			void flee(Vec2d pos);
			void arrive(Vec2d pos);
		};
	};
};

#endif

