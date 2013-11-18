//=======================================================================================================================|
// Created 2013.11.17 by Daniel L. Watkins
//
// Copyright (C) 2013 Daniel L. Watkins
//=======================================================================================================================|

#include "..\Main.h"

namespace glz
{
	template <class T>
	class Vec2
	{
	public:
		T x, y;


		#define OVERLOAD(type, name, body) \
			type name(T x, T y) { body } \
			template <class C> \
			type name(const Vec2<C> &vec2) { name(vec2.x, vec2.y); } \

		Vec2() { set(0.0, 0.0); }

		OVERLOAD(, Vec2, this->x = x; this->y = y;)
		OVERLOAD(void, set, this->x = x; this->y = y;)
		OVERLOAD(void, add, this->x += x; this->y += y;)
		OVERLOAD(Double, distanct, return std::sqrt((this->x-x)*(this->x-x) + (this->y-y)*(this->y-y));)
		OVERLOAD(T, dot, return x*this->x + y*this->y;)
		OVERLOAD(Double, angle, return std::atan2((y-this->y), (x-this->x));)

		#undef OVERLOAD
	};
};