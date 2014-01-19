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
			std::vector<Float> colorData;

			Part()
			{
				vbo = vao = 0;
				drawMode = GL_TRIANGLES;
			}
			void configure();
		};

	private:
		std::vector<Part> mParts;
		Vec2<Float> mNdcPos;

		Bool loadComponentsFromGLZM2File(String filepath);

	protected:
		void clearParts() { mParts.clear(); }
		void addPart(Part part) { mParts.push_back(part); }

	public:
		void setNdcPos(const Vec2<Float> &ndcPos) { mNdcPos = ndcPos; }
		Vec2<Float> getNdcPos() { return mNdcPos; }

		Bool loadFromFile(String filepath);
		void draw(OpenGLWindow *window, Float rotation=0.0);
		void draw(OpenGLWindow *window, Float x, Float y, Float rotation=0.0);
	};
};


#endif

