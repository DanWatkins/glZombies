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
	/**
	 * Represents a 2 component vector which is templated to support essentially every scalar type.
	 */
	template <typename T>
	class Vec2
	{
	public:
		T x, y;

	public:
		Vec2() { set(0.0, 0.0); }
		Vec2(T x, T y) { set(x, y); }

		//moddifiers
		void set(T x, T y) { this->x = x; this->y = y; }
		void set(const Vec2<T> &vec) { x = vec.x; y = vec.y; }

		void add(T x, T y) { this->x += x; this->y += y; }
		void add(const Vec2<T> &vec) { x += vec.x; y += vec.y; }

		void normalize() { Double length = length(); if (length > 0.0) {x /= length; y /= length;} }
		void truncate(Double max) { if (length() > max) { normalize(); *this *= max; } }
		void reflect(const Vec2<T> norm) { *this += 2.0 * this->dot(norm) * norm.reverse(); }

		//calculations
		Double distance(T x, T y) { return std::sqrt((this->x-x)*(this->x-x) + (this->y-y)*(this->y-y)); }
		Double distance(const Vec2<T> &vec) { distance(vec.x, vec.y); }

		Double distanceSq(T x, T y) { return (this->x-x)*(this->x-x) + (this->y-y)*(this->y-y) }
		Double distanceSq(const Vec2<T> &vec) { return distanceSq(vec.x, vec.y); }

		T dot(T x, T y) { return x*this->x + y*this->y; }
		T dot(const Vec2<T> &vec) { return dot(vec.x, vec.y); }

		Double angle(T x, T y) { return std::atan2((y-this->y), (x-this->x)); }
		Double angle(const Vec2<T> &vec) { return angle(vec.x, vec.y); }

		Double length() { return std::sqrt(x*x + y*y); }
		Double lengthSq() { return length() * length(); }

		enum {Clockwise = 1, AntiClockwise = -1};
		int sign(const Vec2<T> vec)
		{
			if (y*v2.x > x*v2.y)
				return AntiClockwise;

			return Clockwise;
		}

		Vec2<T> perp() { return Vec2<T>(-y, x); }
		Vec2<T> reverse() { return Vec2<T>(-x, y); }


		//operators
		const Vec2<T> &operator+=(const Vec2<T> &vec)
		{
			x += vec.x;
			y += vec.y;

			return *this;
		}

		const Vec2<T> &operator-=(const Vec2<T> &vec)
		{
			x -= vec.x;
			y -= vec.y;

			return *this;
		}

		const Vec2<T> &operator*=(const Vec2<T> &vec)
		{
			x *= vec.x;
			y *= vec.y;

			return *this;
		}

		const Vec2<T> &operator/=(const Vec2<T> &vec)
		{
			x /= vec.x;
			y /= vec.y;

			return *this;
		}

		Bool operator==(const Vec2<T> &vec)
		{
			return isEqual(x, vec.x) && isEqual(y, vec.y);
		}


		Bool operator!=(const Vec2<T> &vec)
		{
			return x != vec.x || y != vec.y;
		}

	};


	typedef Vec2<Int> Vec2i;
	typedef Vec2<Float> Vec2f;
	typedef Vec2<Double> Vec2d;
};

#endif

