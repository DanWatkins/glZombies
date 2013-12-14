//=======================================================================================================================|
// Created 2013.11.23 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "Drawable.h"


namespace glz
{
	namespace world
	{
		//==================================================================|
		Drawable::Drawable(String meshFilepath, OpenGLWindow *window)
		{
			mMesh.loadFromFile(meshFilepath);
			mWindow = window;
		}


		//==================================================================|
		void Drawable::update()
		{
			mMesh.setNdcPos(getHost()->getPos());
			mMesh.draw(mWindow);
		}


		//==================================================================|
		Component *Drawable::clone()
		{
			return new Drawable(*this);
		}
	};
};