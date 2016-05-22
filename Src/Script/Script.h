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

		void putGlobalOnStack(String identifier);

	public:
		Script();
		Script(String filepath);
		virtual ~Script() {}

		Bool load(String filepath);
		Bool isOpen();
		void execute();
		void close();

		virtual void bindToLua() = 0;
		
		Bool validArgPos(Int pos);
		Int argsOnStack();

		//argument access
		String getArgString(Int pos);
		Bool getArgBoolean(Int pos);
		Int getArgInteger(Int pos);
		Float getArgFloat(Int pos);
		

		//global variable access
		String getGlobalString(String identifier);
		Bool getGlobalBoolean(String identifier);
		Int getGlobalInteger(String identifier);
		Float getGlobalFloat(String identifier);
	};
};

#endif

