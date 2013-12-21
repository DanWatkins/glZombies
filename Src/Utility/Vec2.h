//=======================================================================================================================|
// Created 2013.11.17 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#ifndef _glz_VEC2_H
#define _glz_VEC2_H

#include "..\Main.h"

namespace glz
{
	template <class T>
	class Vec2
	{
	public:
		T x, y;

	public:
		Vec2() { set(0.0, 0.0); }
		Vec2(T x, T y) { set(x, y); }

		void set(T x, T y) { this->x = x; this->y = y; }
		void set(const Vec2<T> &vec) { x = vec.x; y = vec.y; }

		void add(T x, T y) { this->x += x; this->y += y; }
		void add(const Vec2<T> &vec) { x += vec.x; y += vec.y; }

		Double distance(T x, T y) { return std::sqrt((this->x-x)*(this->x-x) + (this->y-y)*(this->y-y)); }
		Double distance(const Vec2<T> &vec) { distance(vec.x, vec.y); }

		T dot(T x, T y) { return x*this->x + y*this->y; }
		T dot(const Vec2<T> &vec) { return dot(vec.x, vec.y); }

		Double angle(T x, T y) { return std::atan2((y-this->y), (x-this->x)); }
		Double angle(const Vec2<T> &vec) { return angle(vec.x, vec.y); }


	};


	typedef Vec2<Int> Vec2i;
	typedef Vec2<Float> Vec2f;
	typedef Vec2<Double> Vec2d;
};

#endif

