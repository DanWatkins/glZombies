//=======================================================================================================================|
// Created 2013.11.17 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_MESH_2D_H
#define _glz_MESH_2D_H

#include "../Core/Core.h"

#define UNBIND_PROGRAM_AFTER_DRAW 1

namespace glz
{
	typedef std::vector<Float> VertexData;
	const Int gValuesPerPoint = 2;

	class Mesh2D
	{
	protected:
		struct Part
		{
		public:
			Uint vbo, vao;
			GLenum drawMode;
			std::vector<Float> vertexData;

			void configure();
		};


	private:
		std::vector<Part> mParts;
		Vec2<Float> mNdcPos;					//position in NDC-space
		Float mRotation;						//rotation value in radians

		Bool loadComponentsFromGLZM2File(String filepath);

	protected:
		void clearParts() { mParts.clear(); }
		void addPart(Part part) { mParts.push_back(part); }

	public:
		Mesh2D();

		//accessor and mutators
		void setNdcPos(const Vec2<Float> &ndcPos) { mNdcPos = ndcPos; }
		Vec2<Float> getNdcPos() { return mNdcPos; }

		void setRotation(Float angleInRadians) { mRotation = angleInRadians; }
		void addRotation(Float angleInRadians) { mRotation += angleInRadians; }
		Float getRotation() { return mRotation; }

		Bool loadFromFile(String filepath);
		void draw(OpenGLWindow *window);
	};
};


#endif

