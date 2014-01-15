//=======================================================================================================================|
// Created 2014.01.05 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
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

			void update(Double timeDelta) {}

		public:
			Details() {}
			Details(String name, String type);


			void setDisplayName(String displayName) { mDisplayName = displayName; }
			String getDisplayName() { return mDisplayName; }
			String getInternalName() { return mInternalName; }
			String getType() { return mType; }
		};


		class DetailsUser
		{
		protected:
			Details *mDetails;
		};
	};
};


#endif

