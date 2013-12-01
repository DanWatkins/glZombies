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

	const Int gValuesPerPoint = 2;

	class Mesh2D
	{
	private:
		struct Part
		{
		public:
			Uint vbo, vao;
			GLenum drawMode;
			std::vector<Float> vertexData;
		};


	private:
		std::vector<Part> mParts;
		Vec2<Float> mNdcPos;					//position in NDC-space
		Float mRotation;						//rotation value in radians


	public:
		Mesh2D();

		//accessor and mutators
		void setNdcPos(const Vec2<Float> &ndcPos) { mNdcPos = ndcPos; }
		Vec2<Float> getNdcPos() { return mNdcPos; }

		void setRotation(Float angleInRadians) { mRotation = angleInRadians; }
		void addRotation(Float angleInRadians) { mRotation += angleInRadians; }
		Float getRotation() { return mRotation; }


		//==================================================================|
		// -Loads data from a M2 file and configures the vbo and vao states.
		//==================================================================|
		Bool loadFromFile(String filepath);

		//==================================================================|
		// -Draws @mVertexData using the specified mode, vbo, and vao.
		// -Expects load from file to have been called.
		//==================================================================|
		void draw(GLuint &program);


	private:
		//==================================================================|
		// -Loads the actual data from a M2 file.
		//==================================================================|
		Bool loadComponentsFromGLZM2File(String filepath);
	};
};


#endif

