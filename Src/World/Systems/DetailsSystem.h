//=======================================================================================================================|
// Created 2014.01.05 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_DETAILS_SYSTEM_H
#define _glz_DETAILS_SYSTEM_H

#include "System.h"
#include "../Components/Details.h"
#include "../EntityTemplate.h"

namespace glz
{
	namespace world
	{
		class DetailsSystem : public System
		{
		private:

		public:
			void createDetail(Int entity, const EntityTemplate &et);
			void update(Double timeDelta) {}
		};
	};
};

#endif

