#pragma once
#include "psz_zoom.h"
#include "psz_vec2.h"
#include <stdexcept>

namespace psz {

	// returns the max value of Integer in T<Integer> class
	template <template<class> class T, typename Integer>
	Integer maxValue(const T<Integer>&)
	{
		return Integer{ std::numeric_limits<Integer>::max() };
	}

	// returns the min value of Integer in T<Integer> class
	template <template<class> class T, typename Integer>
	Integer minValue(const T<Integer>&)
	{
		return Integer{ std::numeric_limits<Integer>::min() };
	}

	// clamps v to [min,max]
	// (throws std::logic_error if min > max)
	template <typename Integer>
	void setClamp(Integer& v, Integer min, Integer max)
	{
		if (min > max)
		{
			throw std::logic_error("min > max using psz::setClamp(..)");
		}

		if (v < min)
		{
			v = min;
		}
		else if (v > max)
		{
			v = max;
		}
	}

	// clamps z.z to [min,max]
	// (throws std::logic_error if min > max)
	template <typename Integer>
	void setClamp(Zoom<Integer>& z, Integer min, Integer max)
	{
		setClamp(z.z, min, max);
	}

	// clamps both v.x and v.y to [min,max]
	// (throws std::logic_error if minXY > maxXY)
	template <typename Integer>
	void setClamp(Vec2<Integer>& v, Integer minXY, Integer maxXY)
	{
		setClamp(v.x, minXY, maxXY);
		setClamp(v.y, minXY, maxXY);
	}

	// check if v is in range [min,max]
	// returns -1, 0 or 1
	// (throws std::logic_error if min > max)
	template <typename Integer>
	int inRange(Integer v, Integer min, Integer max)
	{
		if (min > max)
		{
			throw std::logic_error("min > max using psz::inRange(..)");
		}

		if (v < min)
		{
			return -1;
		}
		if (v > max)
		{
			return 1;
		}
		return 0;
	}

	// check if z.z is in range [min,max]
	// returns -1, 0 or 1
	// (throws std::logic_error if min > max)
	template <typename Integer>
	int inRange(const Zoom<Integer>& z, Integer min, Integer max)
	{
		return inRange(z.z, min, max);
	}

	// check if both v.x and v.y are in range [min,max]
	// use generic version directly on v.x or v.y
	// if you need more details
	// returns bool
	// (throws std::logic_error if minXY > maxXY)
	template <typename Integer>
	bool inRange(const Vec2<Integer>& v, Integer minXY, Integer maxXY)
	{
		if (!inRange(v.x, minXY, maxXY))
		{
			return false;
		}

		return inRange(v.y, minXY, maxXY);
	}

} // end namespace