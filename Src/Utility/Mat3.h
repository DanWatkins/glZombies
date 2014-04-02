//=======================================================================================================================|
// Created 2013.12.31 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_MAT3_H
#define _glz_MAT3_H

#include "Vec2.h"

namespace glz
{
	/**
	 * Represents a 3x3 matrix
	 */
	template <typename T>
	class Mat3
	{
	private:
		T _11, _12, _13;
		T _21, _22, _23;
		T _31, _32, _33;

	public:
		Mat3()
		{
			identity();
		}


		void identity()
		{
			_11 = T(1); _12 = T(0); _13 = T(0);
			_21 = T(0); _22 = T(1); _23 = T(0);
			_31 = T(0); _32 = T(0); _33 = T(1);
		}


		void multiply(Mat3<T> &matrix)
		{
			_11 = (_11*matrix._11) + (_12*matrix._21) + (_13*matrix._31);
			_12 = (_11*matrix._12) + (_12*matrix._22) + (_13*matrix._32);
			_13 = (_11*matrix._13) + (_12*matrix._23) + (_13*matrix._33);

			_21 = (_21*matrix._11) + (_22*matrix._21) + (_23*matrix._31);
			_22 = (_21*matrix._12) + (_22*matrix._22) + (_23*matrix._32);
			_23 = (_21*matrix._13) + (_22*matrix._23) + (_23*matrix._33);

			_31 = (_31*matrix._11) + (_32*matrix._21) + (_33*matrix._31);
			_32 = (_31*matrix._12) + (_32*matrix._22) + (_33*matrix._32);
			_33 = (_31*matrix._13) + (_32*matrix._23) + (_33*matrix._33);
		}


		void translate(T x, T y)
		{
			Mat3 mat;
			mat.identity();
			mat._31 = x; mat._32 = y;

			multiply(mat);
		}


		void scale(T x, T y)
		{
			Mat3 mat;
			mat.identity();
			mat._11 = x; mat._22 = y;

			multiply(mat);
		}


		void rotate(T rotation)
		{
			Mat3 mat;

			Double rotationSin = sin(rotation);
			Double rotationCos = cos(rotation);

			mat._11 = rotationCos; mat._12 = rotationSin; mat._13 = T(0);
			mat._21 = -rotationSin; mat._22 = rotationCos; mat._23 = T(0);
			mat._31 = T(0); mat._32 = T(0); mat._33 = T(1);

			multiply(mat);
		}


		void rotate(const Vec2d &head, const Vec2d &side)
		{
			Mat3 mat;

			mat._11 = head.x; mat._12 = head.y; mat._13 = T(0);
			mat._21 = side.x; mat._22 = side.y; mat._23 = T(0);
			mat._31 = T(0); mat._32 = T(0); mat._33 = T(1);

			multiply(mat);
		}


		void transformVec2d(Vec2d &point)
		{
			point.x = (_11*point.x) + (_21*point.y) + _31;
			point.y = (_12*point.x) + (_22*point.y) + _32;
		}
	};

	typedef Mat3<Float> Mat3f;
	typedef Mat3<Double> Mat3d;
};


#endif

