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
		class AI;


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
				Arrive			= 003,
				Pursuit			= 004
			};


			/**
			* A request for a steering behavior
			*/
			struct Request
			{
				Behavior behavior;
				Vec2d force;
			};

			typedef std::list<Request> BehaviorList;

		private:
			Spatial *mSpatial;
			BehaviorList mSteeringBehaviorList;


		public:
			SteeringBehaviors(Spatial *spatial);

			/**
			* Creates a net steering force from all of the current behavior requests.
			*/
			Vec2d computeSteeringForce();

			/**
			* Clears out the behavior requests.
			*/
			void clear();

			/**
			 * Creates a steering force that steers the agent directly toward the target position.
			 */
			void seek(Vec2d pos);

			/**
			* Creates a steering force that steers the agent directly away from the target position.
			*/
			void flee(Vec2d pos);

			/**
			* Creates a steering force that steers the agent directly toward the target position.
			* When close enough to the target position, this will generate a force to slow to a gentle
			* stop on the target position.
			*/
			void arrive(Vec2d pos);

			/**
			* Seeks to a leading position to the target. If the agent is ahead of the target, then it
			* just seeks to the target.
			*/
			void pursuit(AI *target);
		};
	};
};

#endif

