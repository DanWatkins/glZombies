//=======================================================================================================================|
// Created 2013.12.17 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "Camera.h"

namespace glz
{
	namespace world
	{
		void Camera::draw()
		{
			glz::Rectangle background;
			background.init(Vec2f(-mWorldPos.x, mWorldPos.y), Vec2f(mWorld->mWidth - mWorldPos.x, mWorldPos.y - mWorld->mHeight));
			background.draw(mWorld->mWindow);

			ComponentList components = mWorld->mSpatialSystem->mComponents;
			ComponentList::iterator iter = components.begin();

			//draw every Entity that has something to draw
			while (iter != components.end())
			{
				//Entity *entity = mWorld->mEntities[n].get();
				Shared<Spatial> spatial = std::dynamic_pointer_cast<Spatial>(*iter);
				Float screenX = Float(spatial->getPos().x - mWorldPos.x);
				Float screenY = -Float(spatial->getPos().y - mWorldPos.y);

				Shared<Drawable> drawable = mWorld->mDrawableSystem->getDrawableForEntity(spatial->getHost());
				drawable->draw(screenX, screenY);

				++iter;
			}
		}
	};
};