//=======================================================================================================================|
// Created 2013.12.17 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Camera.h"

namespace glz
{
	namespace world
	{
		void Camera::draw() const
		{
			//glz::Rectangle background;
			//background.init(Vec2f(-(float)mWorldPos.x, (float)mWorldPos.y),
			//				Vec2f(float(mWorld->mWidth - mWorldPos.x), float(mWorldPos.y - mWorld->mHeight)));
			//background.draw(mWorld->mWindow);

			ComponentList components = mWorld->mSpatialSystem->mComponents;
			ComponentList::iterator iter = components.begin();

			//draw every Entity that has something to draw
			while (iter != components.end())
			{
				Spatial *spatial = static_cast<Spatial*>(*iter);
				float screenX = float(spatial->getPos().x - mWorldPos.x);
				float screenY = -float(spatial->getPos().y - mWorldPos.y);

				Drawable *drawable = static_cast<Drawable*>(mWorld->mDrawableSystem->getComponentForEntity(spatial->getHost()));
				float rotation = static_cast<float>(spatial->getHeading().angle(Vec2d()));
				drawable->draw(screenX, screenY, rotation-(static_cast<float>(PI)/2.0f));

				++iter;
			}
		}
	};
};