#pragma once
#include <limits>

namespace psz {

template <typename Integer>
struct Vec2
{
	static_assert(std::is_integral<Integer>::value,
		"Pos<T>: doesn't work with floating point numbers");

	Integer x, y; // directly access

	Vec2(Integer x = 0, Integer y = 0) // default values 0,0
		:x{ x }, y{ y } {}
	virtual ~Vec2() {}
	Vec2(const Vec2<Integer>& _b) = default;
	Vec2& operator=(const Vec2<Integer>& _b) = default;

	// set x and y at once
	void set(Integer _x, Integer _y)
	{
		x = _x;
		y = _y;
	}

	// add to x (negative for substraction)
	void sumX(Integer _x) { x += _x; }
	// add to y (negative for substraction)
	void sumY(Integer _y) { y += _y; }
};
} // end namespace