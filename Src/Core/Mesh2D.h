//=======================================================================================================================|
// Created 2013.11.17 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_MESH_2D_H
#define _glz_MESH_2D_H

#include "../Main.h"
#include "../Utility/Vec2.h"

#define UNBIND_PROGRAM_AFTER_DRAW 1

namespace glz
{
	typedef std::vector<Float> VertexData;
	typedef Int Error;

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
		// -Loads data from a M2 file and configures the vbo and vao states.
		//==================================================================|
		bool loadFromFile(String filepath);

		//==================================================================|
		// -Draws @mVertexData using the specified mode, vbo, and vao.
		// -Expects load from file to have been called.
		//==================================================================|
		void draw(GLuint &program);


	private:
		//==================================================================|
		// -Loads the actual data from a M2 file.
		//==================================================================|
		bool loadM2VertexDataFromFile(String filepath);
	};
};


#endif

