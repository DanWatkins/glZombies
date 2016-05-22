//=======================================================================================================================|
// Created 2013.11.17 by Daniel L. Watkins
//
// Copyright (C) 2013-2016 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_MESH_2D_H
#define _glz_MESH_2D_H

#include "../Core/Core.h"

#define UNBIND_PROGRAM_AFTER_DRAW 1

namespace glz
{
	typedef std::vector<float> VertexData;
	const int gValuesPerPoint = 2;

	class Mesh2D
	{
	protected:
		struct Part
		{
		public:
			unsigned int vbo, vao;
			GLenum drawMode;
			std::vector<float> vertexData;
			std::vector<float> colorData;

			Part()
			{
				vbo = vao = 0;
				drawMode = GL_TRIANGLES;
			}
			void configure();
		};

	private:
		std::vector<Part> mParts;
		Vec2<float> mNdcPos;

		bool loadComponentsFromGLZM2File(String filepath);

	protected:
		void clearParts() { mParts.clear(); }
		void addPart(Part part) { mParts.push_back(part); }

	public:
		void setNdcPos(const Vec2<float> &ndcPos) { mNdcPos = ndcPos; }
		Vec2<float> getNdcPos() const { return mNdcPos; }

		bool loadFromFile(String filepath);
		void draw(OpenGLWindow *window, float rotation=0.0);
		void draw(OpenGLWindow *window, float x, float y, float rotation=0.0);
	};
};


#endif

