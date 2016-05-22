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

		bool load(String filepath);

		virtual void bindToLua() = 0;
		
		bool validArgPos(int pos) const;
		int argsOnStack() const;

		//argument access
		String getArgString(int pos) const;
		bool getArgBoolean(int pos) const;
		int getArgInteger(int pos) const;
		float getArgFloat(int pos) const;
		

		//global variable access
		String getGlobalString(String identifier) const;
		bool getGlobalBoolean(String identifier) const;
		int getGlobalInteger(String identifier) const;
		float getGlobalFloat(String identifier) const;
	};
};

#endif

