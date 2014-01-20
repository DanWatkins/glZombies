//=======================================================================================================================|
// Created 2014.01.19 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Script.h"

namespace glz
{
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
};