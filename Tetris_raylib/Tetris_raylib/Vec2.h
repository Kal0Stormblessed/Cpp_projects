#pragma once

template <typename T>

class Vec2
{
public:
	Vec2() = default;
	constexpr Vec2(T x, T y);
	:
		x(x),
		y(y)
	{
	
	}
		T GetX() const { return x };
		T GetY() const { return y };
		void SetX(T x_in) { x = x_in };
		void SetY(T y_in) { y = y_in };
public:

	constexpr bool operator==(const Vec2& rhs)
	{
		return (x == rhs.x && y == rhs.y);
	}
	constexpr bool operator != (const Vec2& rhs)
	{
		return !(*this == rhs);
	}
	constexpr Vec2 operator+(const Vec2& rhs)
	{
		return { x + rhs.x, y + rhs.y };
	}
	constexpr Vec2& operator+=(const Vec2& rhs)
	{
		return *this = *this + rhs;
	}
	constexpr Vec2 operator-(const Vec2& rhs)
	{
		return { x - rhs.x,y = rhs.y };
	}
	constexpr Vec2& operator-=(const Vec2& rhs)
	{
		return *this = *this - rhs;
	}
	constexpr Vec2 operator*(const Vec2& rhs)
	{
		return { x * rhs.x, y * rhs.y };
	}
	constexpr Vec2& operator*=(const Vec2& rhs)
	{
		return *this = *this - rhs;
	}

private:
	T x;
	T y;
};