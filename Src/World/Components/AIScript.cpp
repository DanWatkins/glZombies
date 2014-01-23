//=======================================================================================================================|
// Created 2014.01.21 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "AIScript.h"

namespace glz
{
	namespace world
	{
		AIScript *AIScriptRelay::mCurrentScript = NULL;

		/**
		 * _EntityScriptRelay stuff
		 */
		AIScriptRelay& AIScriptRelay::instance()
		{
			static AIScriptRelay instance;
			return instance;
		}


		void AIScriptRelay::lock(AIScript *script)
		{
			if (!isLocked())
				mCurrentScript = script;
		}


		void AIScriptRelay::unlock(AIScript *script)
		{
			if (mCurrentScript == script)
				mCurrentScript = NULL;
		}


		void AIScriptRelay::bindToLua(AIScript *script)
		{
			lua_register(script->mLuaState, "setEntityName", setEntityName);
		}

		
		void AIScriptRelay::script_update()
		{
			lua_getglobal(mCurrentScript->mLuaState, "update");

			if (!lua_isfunction(mCurrentScript->mLuaState, -1))
			{
				std::cout << "No function \"update\" defined in script" << std::endl;
				return;
			}

			lua_call(mCurrentScript->mLuaState, 0, 0);
		}


		String AIScriptRelay::getTopString(lua_State *lua)
		{
			int n = lua_gettop(lua);

			if (n != 1)
			{
				std::cout << "LuaCpp : Wrong number of arguments" << std::endl;
				return "";
			}

			if (!lua_isstring(lua, 1))
			{
				std::cout << "LuaCpp : Invalid argument" << std::endl;
				return "";
			}

			return lua_tostring(lua, 1);
		}



		/**
		 * EntityScript stuff
		 */

		AIScript::AIScript(String filepath) : Script(filepath)
		{
		}

		AIScript::~AIScript()
		{
			AIScriptRelay::instance().unlock(this);
		}


		void AIScript::bindToLua()
		{
			AIScriptRelay::instance().bindToLua(this);
			AIScriptRelay::instance().lock(this);
		}


		void AIScript::script_update()
		{
			if (!AIScriptRelay::instance().isLocked())
			{
				AIScriptRelay::instance().lock(this);
				AIScriptRelay::instance().script_update();
				AIScriptRelay::instance().unlock(this);
			}
		}
	};
};