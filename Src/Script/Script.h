//=======================================================================================================================|
// Created 2014.01.19 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_SCRIPT_H
#define _glz_SCRIPT_H

#include "../Main.h"

namespace glz
{
	class Script
	{
	private:
		lua_State *mLuaState;

	public:
		Script();
		Script(String filepath);

		Bool load(String filepath);
		Bool isOpen();
		void execute();
		void close();
	};
};

#endif

