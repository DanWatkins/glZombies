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



		Double cppArgLua_1d(lua_State *lua)
		{
			Int n = lua_gettop(lua);

			if (n != 1)
				return 0.0;

			if (!lua_isnumber(lua, 1))
				return 0.0;

			return lua_tonumber(lua, 1);
		}


		Vec2d cppArgLua_2d(lua_State *lua)
		{
			Int n = lua_gettop(lua);

			if (n != 2)
				return Vec2d();

			if (!lua_isnumber(lua, 1)  ||  !lua_isnumber(lua, 2))
				return Vec2d();

			return Vec2d(lua_tonumber(lua, 1), lua_tonumber(lua, 2));
		}


		String cppArgLua_s(lua_State *lua)
		{
			Int n = lua_gettop(lua);

			if (n != 1)
				return "";

			if (!lua_isstring(lua, 1))
				return "";

			return lua_tostring(lua, 1);
		}


		Int AIScriptRelay::cpp_seek(lua_State *lua)
		{
			mCurrentScript->mSteeringBehaviors->seek(cppArgLua_2d(lua)); 
			return 0;
		}


		Int AIScriptRelay::cpp_flee(lua_State *lua)
		{
			mCurrentScript->mSteeringBehaviors->flee(cppArgLua_2d(lua)); 
			return 0;
		}


		Int AIScriptRelay::cpp_arrive(lua_State *lua)
		{
			mCurrentScript->mSteeringBehaviors->arrive(cppArgLua_2d(lua)); 
			return 0;
		}


		Int AIScriptRelay::cpp_pursuit(lua_State *lua)
		{
			AI *ai = mCurrentScript->getRecentAiReference((Int)cppArgLua_1d(lua));

			if (ai)
				mCurrentScript->mSteeringBehaviors->pursuit(ai);

			return 0;
		}


		Int AIScriptRelay::cpp_wander(lua_State *lua)
		{
			mCurrentScript->mSteeringBehaviors->wander();

			return 0;
		}


		Int AIScriptRelay::cpp_nearestEntityPos(lua_State *lua)
		{
			String arg = cppArgLua_s(lua);

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
			String arg = cppArgLua_s(lua);

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

			if (n != 2  ||  !lua_isstring(lua, 1)  ||  !lua_isnumber(lua, 2))
			{
				std::cout << "LuaCpp: Wrong arguments for leastDenseSector" << std::endl;
				lua_pushnumber(lua, 0);
				lua_pushnumber(lua, 0);

				return 2;
			}

			std::vector<String> typeMask;
			typeMask.push_back(lua_tostring(lua, 1));
			Int sectors = (Int)lua_tonumber(lua, 2);


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