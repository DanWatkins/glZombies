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
		Drawable::Drawable(String meshFilepath, Uint meshProgram)
		{
			mMesh.loadFromFile(meshFilepath);
			mProgram = meshProgram;
		}


		//==================================================================|
		void Drawable::update()
		{
			mMesh.draw(mProgram);
		}


		//==================================================================|
		Component *Drawable::clone()
		{
			return new Drawable(*this);
		}
	};
};