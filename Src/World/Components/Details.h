//=======================================================================================================================|
// Created 2014.01.05 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_DETAILS_H
#define _glz_DETAILS_H

#include "Component.h"

namespace glz
{
	namespace world
	{
		/**
		 * Holds detail informtion about a particular entity such as if it is alive,
		 * whay type it is, etc.
		 */
		class Details : public Component
		{
		private:
			String mDisplayName, mInternalName, mType;

			void update() override {}

		public:
			Details() {}
			Details(String name, String type);


			void setDisplayName(String displayName) { mDisplayName = displayName; }
			String getDisplayName() const { return mDisplayName; }
			String getInternalName() const { return mInternalName; }
			String getType() const { return mType; }
		};


		class DetailsUser
		{
		protected:
			Details *mDetails;
		};
	};
};


#endif

