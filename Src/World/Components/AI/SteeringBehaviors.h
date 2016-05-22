//=======================================================================================================================|
// Created 2014.01.04 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
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
		typedef Uint8 RequestPriority;

		//priorities
		const static Uint8 mPriorityMax = 0;
		const static Uint8 mPriorityHigh = 64;
		const static Uint8 mPriorityNormal = 128;
		const static Uint8 mPriorityLow = 192;
		const static Uint8 mPriorityMin = 255;


		/**
		* A request for a steering force
		*/
		struct Request
		{
			Vec2d force;
			RequestPriority priority;		//0-highest 255-lowest

			bool operator < (const Request &request) const
			{
				return priority < request.priority;
			}
		};


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
			typedef std::list<Request> BehaviorList;

		private:
			AI *mAi;
			Spatial *mSpatial;
			BehaviorList mSteeringBehaviorList;

			Vec2d mWanderTarget;  //saves the target position betwen frames

		public:
			SteeringBehaviors(AI *ai, Spatial *spatial);

			/**
			* 
			*/
			Bool accumulateForce(Vec2d &totalForce, Vec2d forceToAdd) const;

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
			void seek(Vec2d pos, RequestPriority priority=mPriorityNormal);

			/**
			* Creates a steering force that steers the agent directly away from the target position.
			*/
			void flee(Vec2d pos, RequestPriority priority = mPriorityNormal);

			/**
			* Creates a steering force that steers the agent directly toward the target position.
			* When close enough to the target position, this will generate a force to slow to a gentle
			* stop on the target position.
			*/
			void arrive(Vec2d pos, RequestPriority priority = mPriorityNormal);

			/**
			* Seeks to a leading position to the target. If the agent is ahead of the target, then it
			* just seeks to the target.
			*/
			void pursuit(AI *target, RequestPriority priority = mPriorityNormal);

			/**
			* Creates a steering force that makes the agent wander aimlessly.
			*/
			void wander(RequestPriority priority = mPriorityNormal);
		};
	};
};

#endif

