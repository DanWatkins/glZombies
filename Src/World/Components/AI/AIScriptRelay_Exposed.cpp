//=======================================================================================================================|
// Created 2014.02.09 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AIScriptRelay.h"
#include "AIScript.h"
#include "AI.h"
#include "../../Systems/AISystem.h"

namespace glz
{
	namespace world
	{
		AI *AIScriptRelay::nearestEntity()
		{
			AI *current = mCurrentScript->mAI;
			AISystem *system = (AISystem*)current->getSystem();
			return system->findNearestAi(current->mSpatial->getPos());
		}


		AI *AIScriptRelay::nearestEntity(String type)
		{
			AI *current = mCurrentScript->mAI;
			AISystem *system = (AISystem*)current->getSystem();
			return system->findNearestAi(current->mSpatial->getPos(), type);
		}



		Int AIScriptRelay::cpp_seek(lua_State *lua)
		{
			Vec2d pos;
			RequestPriority priority = mPriorityNormal;
			Int n = lua_gettop(lua);

			if (n >= 2)
			{
				pos.x = mCurrentScript->getArgFloat(1);
				pos.y = mCurrentScript->getArgFloat(2);
			}
			else
				return 0;

			if (n == 3)
				priority = (RequestPriority)mCurrentScript->getArgInteger(3);

			mCurrentScript->mSteeringBehaviors->seek(pos, priority);

			return 0;
		}


		Int AIScriptRelay::cpp_flee(lua_State *lua)
		{
			Vec2d pos;
			RequestPriority priority = mPriorityNormal;
			Int n = lua_gettop(lua);

			if (n >= 2)
			{
				pos.x = mCurrentScript->getArgFloat(1);
				pos.y = mCurrentScript->getArgFloat(2);
			}
			else
				return 0;

			if (n == 3)
				priority = (RequestPriority)mCurrentScript->getArgInteger(3);

			mCurrentScript->mSteeringBehaviors->flee(pos, priority);

			return 0;
		}

		
		Int AIScriptRelay::cpp_arrive(lua_State *lua)
		{
			Vec2d pos;
			RequestPriority priority = mPriorityNormal;
			Int n = lua_gettop(lua);

			if (n >= 2)
			{
				pos.x = mCurrentScript->getArgFloat(1);
				pos.y = mCurrentScript->getArgFloat(2);
			}
			else
				return 0;

			if (n == 3)
				priority = (RequestPriority)mCurrentScript->getArgInteger(3);


			mCurrentScript->mSteeringBehaviors->arrive(pos, priority);

			return 0;
		}


		Int AIScriptRelay::cpp_pursuit(lua_State *lua)
		{
			Int id;
			RequestPriority priority = mPriorityNormal;
			Int n = lua_gettop(lua);

			if (n >= 1)
				id = mCurrentScript->getArgInteger(1);
			else
				return 0;

			if (n == 2)
				priority = (RequestPriority)mCurrentScript->getArgInteger(2);

			AI *ai = mCurrentScript->getRecentAiReference(id);

			if (ai)
				mCurrentScript->mSteeringBehaviors->pursuit(ai, priority);

			return 0;
		}


		Int AIScriptRelay::cpp_wander(lua_State *lua)
		{
			mCurrentScript->mSteeringBehaviors->wander((RequestPriority)mCurrentScript->getArgInteger(1));
			return 0;
		}


		Int AIScriptRelay::cpp_nearestEntityPos(lua_State *lua)
		{
			String arg = mCurrentScript->getArgString(1);

			if (arg != "")
				return cpp_nearestEntityPos(lua, arg);

			AI *nearest = nearestEntity();

			if (nearest)
			{
				Vec2d pos = nearest->mSpatial->getPos();
				lua_pushnumber(lua, pos.x);
				lua_pushnumber(lua, pos.y);

				return 2;
			}

			return 0;
		}


		Int AIScriptRelay::cpp_nearestEntityPos(lua_State *lua, String type)
		{
			AI *nearest = nearestEntity(type);

			if (nearest)
			{
				Vec2d pos = nearest->mSpatial->getPos();
				lua_pushnumber(lua, pos.x);
				lua_pushnumber(lua, pos.y);

				return 2;
			}

			return 0;
		}


		Int AIScriptRelay::cpp_nearestEntityId(lua_State *lua)
		{
			String arg = mCurrentScript->getArgString(1);

			if (arg != "")
				return cpp_nearestEntityId(lua, arg);

			AI *nearest = nearestEntity();

			if (nearest)
			{
				mCurrentScript->addRecentAiReference(nearest);
				lua_pushnumber(lua, nearest->getHost());

				return 1;
			}

			return 0;
		}


		Int AIScriptRelay::cpp_nearestEntityId(lua_State *lua, String type)
		{
			AI *nearest = nearestEntity(type);

			if (nearest)
			{
				mCurrentScript->addRecentAiReference(nearest);
				lua_pushnumber(lua, nearest->getHost());

				return 1;
			}

			return 0;
		}


		Int AIScriptRelay::cpp_leastDenseSector(lua_State *lua)
		{
			Int n = lua_gettop(lua);

			if (n != 2)
			{
				std::cout << "LuaCpp: Wrong arguments for leastDenseSector" << std::endl;
				lua_pushnumber(lua, 0);
				lua_pushnumber(lua, 0);

				return 2;
			}

			std::vector<String> typeMask;
			typeMask.push_back(mCurrentScript->getArgString(1));
			Int sectors = mCurrentScript->getArgInteger(2);

			return cpp_leastDenseSector(lua, typeMask, sectors);
		}


		Int AIScriptRelay::cpp_leastDenseSector(lua_State *lua, std::vector<String> typeMask, Int sectors)
		{
			Vec2d pos = ((AISystem*)mCurrentScript->mAI->getSystem())->findLeastDenseSector( mCurrentScript->mAI, typeMask, sectors);
			lua_pushnumber(lua, pos.x);
			lua_pushnumber(lua, pos.y);
			
			return 2;
		}
	};
};