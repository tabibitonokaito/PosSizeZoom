#pragma once

namespace psz {
template <typename Integer>
class Zoom
{
public:
	static_assert(std::is_integral<Integer>::value,
		"Pos<T>: doesn't work with floating point numbers");

	Integer z;

	Zoom(Integer z = 100) // z = 100 as a default value
		:z(z) {}

	// same as object.z = _z
	void set(Integer _z)
	{
		z = _z;
	}

	// sum to zoom (negative values for substraction)
	void sumZoom(Integer _z) { z += _z; }
};
} // end namespace