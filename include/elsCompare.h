
#ifndef ELS_COMPARE
#define ELS_COMPARE
#include "elsMath.h"

namespace els
{
	template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
	inline constexpr bool is_zero(T val)
	{
		if constexpr (std::is_floating_point<T>::value)
			return (val * val) <= els::epsilon2<T>;
		else
			return val == 0;
	}
	template <typename Ty, typename Tx,
		typename = std::enable_if_t<
		std::is_arithmetic<Ty>::value &&
		std::is_arithmetic<Tx>::value >>
	inline constexpr bool is_equal(Ty y, Tx x)
	{
		return is_zero(y - x);
	}
	template <typename Ty, typename Tx,
		typename = std::enable_if_t<
		std::is_arithmetic<Ty>::value &&
		std::is_arithmetic<Tx>::value >>
	inline constexpr bool is_not_equal(Ty y, Tx x)
	{
		return !is_equal(y, x);
	}

	template <template <class> class TVec, typename T>
	inline constexpr bool is_zero(const TVec<T>& vec)
	{
		if constexpr (std::is_floating_point<T>::value)
			return vec.length2() <= els::epsilon2<T>;
		else
			return vec.length2() == 0;
	}
	template <template <class> class TVec, typename T>
	inline constexpr bool is_equal(const TVec<T>& lhs, const TVec<T>& rhs)
	{
		return is_zero(lhs - rhs);
	}
	template <template <class> class TVec, typename T>
	inline constexpr bool is_not_equal(const TVec<T>& lhs, const TVec<T>& rhs)
	{
		return !is_equal(lhs, rhs);
	}

	template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
	inline constexpr bool is_nan(T val)
	{
		if constexpr (std::is_floating_point<T>::value)
			return ::isnan(val);
		else
			return false;
	}
	template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
	inline constexpr bool is_inf(T val)
	{
		if constexpr (std::is_floating_point<T>::value)
			return ::isinf(val);
		else
			return false;
	}
	template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
	inline constexpr bool is_finite(T val)
	{
		if constexpr (std::is_floating_point<T>::value)
			return ::isfinite(val);
		else
			return true;
	}
	template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
	inline constexpr bool is_normal(T val)
	{
		if constexpr (std::is_floating_point<T>::value)
			return ::isnormal(val);
		else
			return true;
	}
	template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
	inline constexpr bool is_negative(T val)
	{
		return ::signbit(val);
	}
}

#endif