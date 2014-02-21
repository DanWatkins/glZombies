//=======================================================================================================================|
// Created 2014.02.09 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AIScriptRelay.h"
#include "AIScript.h"
#include "AI.h"

namespace glz
{
	namespace world
	{
		Vec2d cppArgLua_2d(lua_State *lua)
		{
			int n = lua_gettop(lua);

			if (n != 2)
			{
				return Vec2d();
			}

			if (!lua_isnumber(lua, 1)  ||  !lua_isnumber(lua, 2))
				return Vec2d();

			return Vec2d(lua_tonumber(lua, 1), lua_tonumber(lua, 2));
		}


		String cppArgLua_s(lua_State *lua)
		{
			int n = lua_gettop(lua);

			if (n != 1)
			{
				return "";
			}

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


		Int AIScriptRelay::cpp_nearestEntity(lua_State *lua)
		{
			String arg = cppArgLua_s(lua);

			if (arg != "")
				return cpp_nearestEntity(lua, arg);

			AI *nearest = mCurrentScript->mAI->findNearestAi();

			if (nearest)
			{
				Vec2d pos = nearest->mSpatial->getPos();
				lua_pushnumber(lua, pos.x);
				lua_pushnumber(lua, pos.y);

				return 2;
			}


			return 0;
		}


		Int AIScriptRelay::cpp_nearestEntity(lua_State *lua, String type)
		{
			AI *nearest = mCurrentScript->mAI->findNearestAi(type);

			if (nearest)
			{
				Vec2d pos = nearest->mSpatial->getPos();
				lua_pushnumber(lua, pos.x);
				lua_pushnumber(lua, pos.y);

				return 2;
			}


			return 0;
		}
	};
};