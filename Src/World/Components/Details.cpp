//=======================================================================================================================|
// Created 2014.01.05 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Details.h"

namespace glz
{
	namespace world
	{
		Details::Details(String name, String type)
		{
			mDisplayName = name;
			mInternalName = name;
			mType = type;
		}
	};
};