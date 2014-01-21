//=======================================================================================================================|
// Created 2014.01.19 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Script.h"

namespace glz
{
	void Script::putGlobalOnStack(String identifier)
	{
		lua_settop(mLuaState, 0);
		lua_getglobal(mLuaState, identifier.c_str());
	}

	Script::Script()
	{
		mLuaState = luaL_newstate();
		luaL_openlibs(mLuaState);
	}


	Script::Script(String filepath)
	{
		*this = Script();
		load(filepath);
	}


	Bool Script::load(String filepath)
	{
		return luaL_dofile(mLuaState, filepath.c_str());
	}


	Bool Script::isOpen()
	{
		return false;
	}


	void Script::execute()
	{
	}


	void Script::close()
	{
	}


	String Script::getGlobalString(String identifier)
	{
		putGlobalOnStack(identifier);

		if (lua_isstring(mLuaState, 1))
			return lua_tostring(mLuaState, 1);
	}


	Bool Script::getGlobalBoolean(String identifier)
	{
		putGlobalOnStack(identifier);

		if (lua_isboolean(mLuaState, 1))
			return lua_toboolean(mLuaState, 1);
	}


	Int Script::getGlobalInteger(String identifier)
	{
		putGlobalOnStack(identifier);

		if (lua_isnumber(mLuaState, 1))
			return (Int)lua_tonumber(mLuaState, 1);
	}

	Float Script::getGlobalFloat(String identifier)
	{
		putGlobalOnStack(identifier);

		if (lua_isnumber(mLuaState, 1))
			return lua_tonumber(mLuaState, 1);
	}
};