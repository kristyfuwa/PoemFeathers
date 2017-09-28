#pragma once

namespace PoemFeathers
{
	class pfCore_API pfVector2
	{
	public:
		pfVector2();
		pfVector2(float x, float y);
		~pfVector2();

		float		GetX()const;
		float		GetY()const;
		void		Set(float x, float y);
		float		Length() const;

		float		Distance(const pfVector2& vec) const;
		pfVector2&	Normalize();
		float		Dot(const pfVector2& vec) const;
		bool		Equal(const pfVector2& vec, float e) const;

		//operators
		pfVector2 operator-() const;
		pfVector2 operator+(const pfVector2& rhs) const;//const 不改变成员变量值，常成员函数；
		pfVector2 operator-(const pfVector2& rhs) const;
		pfVector2& operator+=(const pfVector2& rhs);//返回引用的主要目的是实现连级运算
		pfVector2& operator-=(const pfVector2& rhs);
		pfVector2 operator*(const float scale) const;
		pfVector2 operator*(const pfVector2& rhs) const;
		pfVector2& operator*=(const float scale);
		pfVector2 operator/(const float scale) const;
		pfVector2& operator/=(const float scale);
		bool	operator==(const pfVector2& rhs) const;
		bool	operator!=(const pfVector2& rhs) const;
		bool	operator<(const pfVector2& rhs) const;
		float   operator[](int index) const;
		float&	operator[](int index);

		friend pfVector2 operator*(const float a, const pfVector2 vec);
		friend std::ostream& operator<<(std::ostream& os, const pfVector2& vec);

	private:
		float				m_fx;
		float				m_fy;
	};
}


