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

			//draw every Entity that has something to draw
			for (Uint n=0; n<mWorld->mEntities.size(); n++)
			{
				Entity *entity = mWorld->mEntities[n].get();
				Float screenX = Float(entity->getWorldPos().x - mWorldPos.x);
				Float screenY = -Float(entity->getWorldPos().y - mWorldPos.y);

				//draw every component that is a Drawable
				for (Uint m=0; m<entity->mComponents.size(); m++)
				{
					Component *component = entity->mComponents[m].get();
					
					if (Drawable *drawable = dynamic_cast<Drawable*>(component))
						drawable->draw(screenX, screenY);
				}
			}
		}
	};
};