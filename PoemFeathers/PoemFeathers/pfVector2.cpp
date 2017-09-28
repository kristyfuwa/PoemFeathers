#include "pfPrivatePCH.h"

namespace PoemFeathers
{
	pfVector2::pfVector2() :m_fx(0.0f), m_fy(0.0f)
	{
	}


	pfVector2::pfVector2(float x, float y):m_fx(x),m_fy(y)
	{
	}

	pfVector2::~pfVector2()
	{
	}


	float pfVector2::GetX() const
	{
		return this->m_fx;
	}


	float pfVector2::GetY() const
	{
		return this->m_fy;
	}


	void pfVector2::Set(float x, float y)
	{
		this->m_fx = x;
		this->m_fy = y;
	}

	float pfVector2::Length() const
	{
		return sqrtf(m_fx*m_fx + m_fy*m_fy);
	}

	float pfVector2::Distance(const pfVector2& vec) const
	{
		pfVector2 temp;
		temp.m_fx = m_fx - vec.m_fx;
		temp.m_fy = m_fy - vec.m_fy;
		return sqrtf(temp.m_fx*temp.m_fx + temp.m_fy*temp.m_fy);
	}

	pfVector2& pfVector2::Normalize()
	{
		float value = m_fx*m_fx + m_fy*m_fy;
		float Length = 1.0f / sqrtf(value);
		m_fx *= Length;
		m_fy *= Length;
		return *this;
	}

	float pfVector2::Dot(const pfVector2& vec) const
	{
		return m_fx*vec.m_fx + m_fy*vec.m_fy;
	}

	bool pfVector2::Equal(const pfVector2& vec, float e) const
	{
		return fabs(m_fx - vec.m_fx) < e && fabs(m_fy - vec.m_fy) < e;
	}

	pfVector2 pfVector2::operator-() const
	{
		return pfVector2(-m_fx, -m_fy);
	}

	pfVector2 pfVector2::operator+(const pfVector2& rhs) const
	{
		return pfVector2(m_fx + rhs.m_fx, m_fy + rhs.m_fy);
	}

	pfVector2 pfVector2::operator-(const pfVector2& rhs) const
	{
		return pfVector2(m_fx - rhs.m_fx, m_fy - rhs.m_fy);
	}

	pfVector2& pfVector2::operator-=(const pfVector2& rhs)
	{
		m_fx -= rhs.m_fx;
		m_fy -= rhs.m_fy;
		return *this;
	}

	pfVector2& pfVector2::operator+=(const pfVector2& rhs)
	{
		m_fx += rhs.m_fx;
		m_fy += rhs.m_fy;
		return *this;
	}

	float pfVector2::operator[](int index) const
	{
		return (&m_fx)[index];
	}

	float& pfVector2::operator[](int index)
	{
		return (&m_fx)[index];
	}

	pfVector2 pfVector2::operator*(const float scale) const
	{
		return pfVector2(m_fx*scale, m_fy*scale);
	}

	pfVector2 pfVector2::operator*(const pfVector2& rhs) const
	{
		return pfVector2(m_fx*rhs.m_fx, m_fy*rhs.m_fy);
	}

	pfVector2& pfVector2::operator*=(const float scale)
	{
		m_fx *= scale;
		m_fy *= scale;
		return *this;
	}

	pfVector2 pfVector2::operator/(const float scale) const
	{

		return pfVector2(m_fx / scale, m_fy / scale);
	}

	pfVector2& pfVector2::operator/=(const float scale)
	{
		m_fx /= scale;
		m_fy /= scale;
		return *this;
	}

	bool pfVector2::operator<(const pfVector2& rhs) const
	{
		if (m_fx < rhs.m_fx)
			return true;
		if (m_fx > rhs.m_fx)
			return false;
		if (m_fy > rhs.m_fy)
			return false;
		if (m_fy < rhs.m_fy)
			return true;
		return false;
	}

	bool pfVector2::operator!=(const pfVector2& rhs) const
	{
		return (m_fx != rhs.m_fx) || (m_fy != rhs.m_fy);
	}

	bool pfVector2::operator==(const pfVector2& rhs) const
	{
		return (m_fx == rhs.m_fx) && (m_fy == rhs.m_fy);
	}

	pfVector2 operator*(const float a, const pfVector2 vec)
	{
		return pfVector2(a*vec.m_fx, a*vec.m_fy);
	}

	std::ostream& operator<<(std::ostream& os, const pfVector2& vec)
	{
		os << "(" << vec.m_fx << "," << vec.m_fy << ")";
		return os;
	}
}


