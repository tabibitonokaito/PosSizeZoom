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

	// allows to asign 0.5 instead of 50
	template <typename Floating>
	void setFloating(Floating fval)
	{
		static_assert(std::is_floating_point<Floating>::value,
			"void setFloating(F fval) -> F have to be a floating point type");

		Floating newValue = fval * static_cast<Floating>(100.0);
		z = static_cast<Integer>(newValue);
	}

	// get the floating version of z (60 -> 0.6)
	template <typename Floating>
	Floating getFloating()
	{
		static_assert(std::is_floating_point<Floating>::value,
			"F getFloating() -> F have to be a floating point type");

		return static_cast<Floating>(z) / static_cast<Floating>(100.0);
	}
};
} // end namespace