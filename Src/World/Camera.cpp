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
			background.init(Vec2f(-(Float)mWorldPos.x, (Float)mWorldPos.y),
							Vec2f(Float(mWorld->mWidth - mWorldPos.x), Float(mWorldPos.y - mWorld->mHeight)));
			background.draw(mWorld->mWindow);

			ComponentList components = mWorld->mSpatialSystem->mComponents;
			ComponentList::iterator iter = components.begin();

			//draw every Entity that has something to draw
			while (iter != components.end())
			{
				Shared<Spatial> spatial = std::dynamic_pointer_cast<Spatial>(*iter);
				Float screenX = Float(spatial->getPos().x - mWorldPos.x);
				Float screenY = -Float(spatial->getPos().y - mWorldPos.y);

				Shared<Drawable> drawable = std::dynamic_pointer_cast<Drawable>(mWorld->mDrawableSystem->getComponentForEntity(spatial->getHost()));
				drawable->draw(screenX, screenY);

				++iter;
			}
		}
	};
};