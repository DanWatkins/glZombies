//=======================================================================================================================|
// Created 2013.11.17 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_MESH_2D_H
#define _glz_MESH_2D_H

#include "..\Main.h"
#include "Vec2.h"

#define UNBIND_PROGRAM_AFTER_DRAW 1

namespace glz
{
	class Mesh2D
	{
	private:
		GLuint mVbo, mVao;
		GLenum mDrawMode;
		std::vector<Float> mVertexData;

		Vec2<Float> mNdcPos;					//position in NDC-space


	public:
		Mesh2D();

		void setDrawMode(GLenum drawMode) { mDrawMode = drawMode; }
		GLenum getDrawMode() { return mDrawMode; }

		void setNdcPos(const Vec2<Float> &ndcPos) { mNdcPos = ndcPos; }
		Vec2<Float> getNdcPos() { return mNdcPos; }

		//==================================================================|
		// -
		//==================================================================|
		void load();

		//==================================================================|
		// -
		//==================================================================|
		void draw(GLuint &program);


	private:
		//==================================================================|
		// -
		//==================================================================|
		void generateVertexData();
	};
};


#endif

