//=======================================================================================================================|
// Created 2013.11.17 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_VEC2_H
#define _glz_VEC2_H

#include "..\Main.h"

namespace glz
{
	/**
	 * Represents a 2 component vector which is templated to support essentially every scalar type.
	 */
	template <class T>
	class Vec2
	{
	public:
		T x, y;

		Vec2() { set(0.0, 0.0); }
		Vec2(T x, T y) { set(x, y); }
		Vec2(T v) { set(v, v); }

		/**
		 * Moddification methods
		 */
		void set(T x, T y)
		{
			this->x = x;
			this->y = y;
		}

		void set(const Vec2<T> &vec)
		{
			x = vec.x;
			y = vec.y;
		}

		void clear()
		{
			x = T(0); y = T(0);
		}

		void add(T x, T y)
		{
			this->x += x;
			this->y += y;
		}

		void add(const Vec2<T> &vec)
		{
			x += vec.x;
			y += vec.y;
		}

		void truncate(Double max)
		{
			if (length() > max)
			{
				normalize();
				*this *= max;
			}
		}

		void reflect(const Vec2<T> norm)
		{
			*this += 2.0 * this->dot(norm) * norm.reverse();
		}

		void normalize()
		{
			Double lng = length();
			if (lng > 0.0)
			{
				x /= lng;
				y /= lng;
			}
		}


		/**
		 * Calculations
		 */
		Double distance(T x, T y)
		{
			return std::sqrt((this->x-x)*(this->x-x) + (this->y-y)*(this->y-y));
		}

		Double distance(const Vec2<T> &vec)
		{
			return distance(vec.x, vec.y);
		}

		Double distanceSq(T x, T y)
		{
			return (this->x-x)*(this->x-x) + (this->y-y)*(this->y-y);
		}

		Double distanceSq(const Vec2<T> &vec)
		{
			return distanceSq(vec.x, vec.y);
		}

		T dot(T x, T y)
		{
			return x*this->x + y*this->y;
		}

		T dot(const Vec2<T> &vec)
		{
			return dot(vec.x, vec.y);
		}

		Double angle(T x, T y)
		{
			return std::atan2((y-this->y), (x-this->x));
		}

		Double angle(const Vec2<T> &vec)
		{
			return angle(vec.x, vec.y);
		}

		Double length()
		{
			return std::sqrt(x*x + y*y);
		}

		Double lengthSq()
		{
			return length() * length();
		}

		Int sign(const Vec2<T> vec)
		{
			if (y*vec.x > x*vec.y)
				return -1;

			return 1;
		}

		Vec2<T> perp()
		{
			return Vec2<T>(-y, x);
		}

		Vec2<T> reverse()
		{
			return Vec2<T>(-x, y);
		}


		/**
		 * Operators
		 */
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

		const Vec2<T> operator+(const Vec2<T> &vec)
		{
			return Vec2<T>(x+vec.x, y+vec.y);
		}
		const Vec2<T> operator+(Double amount)
		{
			return Vec2<T>(x+amount, y+amount);
		}

		const Vec2<T> operator-(const Vec2<T> &vec)
		{
			return Vec2<T>(x-vec.x, y-vec.y);
		}
		const Vec2<T> operator-(Double amount)
		{
			return Vec2<T>(x-amount, y-amount);
		}

		const Vec2<T> operator*(const Vec2<T> &vec)
		{
			return Vec2<T>(x*vec.x, y*vec.y);
		}
		const Vec2<T> operator*(Double amount)
		{
			return Vec2<T>(x*amount, y*amount);
		}

		const Vec2<T> operator/(const Vec2<T> &vec)
		{
			return Vec2<T>(x/vec.x, y/vec.y);
		}
		const Vec2<T> operator/(Double amount)
		{
			return Vec2<T>(x/amount, y/amount);
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

