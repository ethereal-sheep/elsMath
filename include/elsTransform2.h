
#ifndef ELS_TRANSFORM2
#define ELS_TRANSFORM2

#include "elsHeader.h"
#include "elsMath.h"
#include "elsMatrix3.h"

namespace els
{
	template <typename T>
	class Transform2
	{
	public:
		template <typename S>
		static inline constexpr Matrix3<T> translate(S x, S y)
		{
			return Matrix3<T>{
				1, 0, static_cast<T>(x),
					0, 1, static_cast<T>(y),
					0, 0, 1
			};
		}
		template <typename S>
		static inline constexpr Matrix3<T> translate(const Vector2<S>& v)
		{
			return translate(v.x, v.y);
		}

		template <typename S>
		static inline constexpr Matrix3<T> rotate(S angle)
		{
			return Matrix3<T>{
				cos(static_cast<T>(angle)), -sin(static_cast<T>(angle)), 0,
					sin(static_cast<T>(angle)), cos(static_cast<T>(angle)), 0,
					0, 0, 1
			};
		}

		template <typename S>
		static inline constexpr Matrix3<T> scale(S x, S y)
		{
			return Matrix3<T>{
				static_cast<T>(x), 0, 0,
					0, static_cast<T>(y), 0,
					0, 0, 1
			};
		}
		template <typename S>
		static inline constexpr Matrix3<T> scale(S s)
		{
			return scale(s, s);
		}
		template <typename S>
		static inline constexpr Matrix3<T> scale(const Vector2<S>& v)
		{
			return scale(v.x, v.y);
		}
	};

	using t2f = Transform2<float>;
	using t2 = Transform2<defaultType>;

	template <typename T>
	constexpr Vector2<T>& transform(Vector2<T>& vec, const Matrix3<T>& trf)
	{
		vec = trf * vec;
		return vec;
	}
	template <typename T>
	constexpr Vector3<T>& transform(Vector3<T>& vec, const Matrix3<T>& trf)
	{
		vec = trf * vec;
		return vec;
	}

} // namespace els

#endif