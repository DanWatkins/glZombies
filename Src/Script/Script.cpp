//=======================================================================================================================|
// Created 2014.01.19 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Script.h"

namespace glz
{
	void Script::putGlobalOnStack(String identifier) const
	{
		lua_settop(mLuaState, 0);
		lua_getglobal(mLuaState, identifier.c_str());
	}

	Script::Script()
	{
		mLuaState = luaL_newstate();
		luaL_openlibs(mLuaState);
	}


	Script::Script(String filepath) : Script()
	{
		load(filepath);
	}


	bool Script::load(String filepath)
	{
		return luaL_dofile(mLuaState, filepath.c_str());
	}


	bool Script::validArgPos(int pos) const
	{
		return !(pos > lua_gettop(mLuaState));
	}


	int Script::argsOnStack() const
	{
		return lua_gettop(mLuaState);
	}


	String Script::getArgString(int pos) const
	{
		if (!validArgPos(pos) || !lua_isnumber(mLuaState, pos))
			return "";

		return lua_tostring(mLuaState, pos);
	}
	

	bool Script::getArgBoolean(int pos) const
	{
		if (!validArgPos(pos) || !lua_isboolean(mLuaState, pos))
			return false;

		return lua_toboolean(mLuaState, pos);
	}


	int Script::getArgInteger(int pos) const
	{
		return int(getArgFloat(pos));
	}


	float Script::getArgFloat(int pos) const
	{
		if (!validArgPos(pos) || !lua_isnumber(mLuaState, pos))
			return 0.0f;

		return static_cast<float>(lua_tonumber(mLuaState, pos));
	}


	String Script::getGlobalString(String identifier) const
	{
		putGlobalOnStack(identifier);

		if (lua_isstring(mLuaState, 1))
			return lua_tostring(mLuaState, 1);

		return "";
	}


	bool Script::getGlobalBoolean(String identifier) const
	{
		putGlobalOnStack(identifier);

		if (lua_isboolean(mLuaState, 1))
			return lua_toboolean(mLuaState, 1);

		return false;
	}


	int Script::getGlobalInteger(String identifier) const
	{
		putGlobalOnStack(identifier);

		if (lua_isnumber(mLuaState, 1))
			return int(lua_tonumber(mLuaState, 1));

		return 0;
	}


	float Script::getGlobalFloat(String identifier) const
	{
		putGlobalOnStack(identifier);

		if (lua_isnumber(mLuaState, 1))
			return float(lua_tonumber(mLuaState, 1));

		return 0.0f;
	}
};