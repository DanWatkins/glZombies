//=======================================================================================================================|
// Created 2014.01.19 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_SCRIPT_H
#define _glz_SCRIPT_H

#include "../Main.h"

namespace glz
{
	class Script
	{
	protected:
		lua_State *mLuaState;

		void putGlobalOnStack(String identifier) const;

	public:
		Script();
		Script(String filepath);
		virtual ~Script() {}

		Bool load(String filepath);

		virtual void bindToLua() = 0;
		
		Bool validArgPos(Int pos) const;
		Int argsOnStack() const;

		//argument access
		String getArgString(Int pos) const;
		Bool getArgBoolean(Int pos) const;
		Int getArgInteger(Int pos) const;
		Float getArgFloat(Int pos) const;
		

		//global variable access
		String getGlobalString(String identifier) const;
		Bool getGlobalBoolean(String identifier) const;
		Int getGlobalInteger(String identifier) const;
		Float getGlobalFloat(String identifier) const;
	};
};

#endif

