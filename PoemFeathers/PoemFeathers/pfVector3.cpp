#include "pfPrivatePCH.h"

namespace PoemFeathers
{
	pfVector3::pfVector3() :m_fx(0.0f), m_fy(0.0f), m_fz(0.0f)
	{
	}


	pfVector3::pfVector3(float x, float y, float z) : m_fx(x), m_fy(y), m_fz(z)
	{

	}

	pfVector3::~pfVector3()
	{
	}


	float pfVector3::GetX() const
	{
		return m_fx;
	}


	float pfVector3::GetY() const
	{
		return m_fy;
	}


	float pfVector3::GetZ() const
	{
		return m_fz;
	}

	void pfVector3::Set(float x, float y, float z)
	{
		m_fx = x;
		m_fy = y;
		m_fz = z;
	}

	float pfVector3::Length() const
	{
		return sqrtf(m_fx*m_fx + m_fy*m_fy + m_fz*m_fz);
	}

	float pfVector3::Distance(const pfVector3& vec) const
	{
		return sqrtf((m_fx - vec.m_fx)*(m_fx - vec.m_fx) + (m_fy - vec.m_fy)*(m_fy - vec.m_fy) + (m_fz - vec.m_fz)*(m_fz - vec.m_fz));
	}

	pfVector3& pfVector3::Normalize()
	{
		float value = m_fx*m_fx + m_fy*m_fy + m_fz*m_fz;

		float length = 1.0f / sqrtf(value);

		m_fx *= length;
		m_fy *= length;
		m_fz *= length;
		return *this;
	}

	float pfVector3::Dot(const pfVector3& vec) const
	{
		return m_fx*vec.m_fx + m_fy*vec.m_fy + m_fz*vec.m_fz;
	}

	pfVector3 pfVector3::Cross(const pfVector3& vec) const
	{
		return pfVector3(m_fy*vec.m_fz - m_fz*vec.m_fy, m_fz*vec.m_fx - m_fx*vec.m_fz, m_fx*vec.m_fy - m_fy*vec.m_fx);
	}

	bool pfVector3::Equal(const pfVector3& vec, float e) const
	{
		return fabs(m_fx - vec.m_fx) < e && fabs(m_fy - vec.m_fy) < e && fabs(m_fz - vec.m_fz) < e;
	}

	pfVector3 pfVector3::operator-() const
	{
		return pfVector3(-m_fx, -m_fy, -m_fz);
	}

	pfVector3 pfVector3::operator-(const pfVector3& rhs) const
	{
		return pfVector3(m_fx - rhs.m_fx, m_fy - rhs.m_fy, m_fz - rhs.m_fz);
	}

	pfVector3& pfVector3::operator-=(const pfVector3& rhs)
	{
		m_fx -= rhs.m_fx;
		m_fy -= rhs.m_fy;
		m_fz -= rhs.m_fz;
		return *this;
	}

	bool pfVector3::operator<(const pfVector3& rhs) const
	{
		if (m_fx < rhs.m_fx)
			return true;
		if (m_fx > rhs.m_fx)
			return false;
		if (m_fy < rhs.m_fy)
			return true;
		if (m_fy > rhs.m_fy)
			return false;
		if (m_fz < rhs.m_fz)
			return true;
		if (m_fz > rhs.m_fz)
			return false;
		return false;
	}

	float pfVector3::operator[](int index) const
	{
		return (&m_fx)[index];
	}

	float& pfVector3::operator[](int index)
	{
		return (&m_fx)[index];
	}

	pfVector3 pfVector3::operator*(const float scale) const
	{
		return pfVector3(m_fx*scale, m_fy*scale, m_fz*scale);
	}

	pfVector3 pfVector3::operator*(const pfVector3& rhs) const
	{
		return pfVector3(m_fx*rhs.m_fx, m_fy*rhs.m_fy, m_fz*rhs.m_fz);
	}

	pfVector3& pfVector3::operator*=(const float scale)
	{
		m_fx *= scale;
		m_fy *= scale;
		m_fz *= scale;
		return *this;
	}

	pfVector3& pfVector3::operator*=(const pfVector3& rhs)
	{
		m_fx *= rhs.m_fx;
		m_fy *= rhs.m_fy;
		m_fz *= rhs.m_fz;
		return *this;
	}

	pfVector3 pfVector3::operator/(const float scale) const
	{
		return pfVector3(m_fx / scale, m_fy / scale, m_fz / scale);

	}

	pfVector3& pfVector3::operator/=(const float scale)
	{
		m_fx /= scale;
		m_fy /= scale;
		m_fz /= scale;
		return *this;
	}

	bool pfVector3::operator!=(const pfVector3& rhs) const
	{
		return (m_fx != rhs.m_fx) || (m_fy != rhs.m_fy) || (m_fz != rhs.m_fz);
	}

	bool pfVector3::operator==(const pfVector3& rhs) const
	{
		return (m_fx == rhs.m_fx) && (m_fy == rhs.m_fy) && (m_fz == rhs.m_fz);
	}

	pfVector3& pfVector3::operator+=(const pfVector3& rhs)
	{
		m_fx += rhs.m_fx;
		m_fy += rhs.m_fy;
		m_fz += rhs.m_fz;
		return *this;
	}

	pfVector3 pfVector3::operator+(const pfVector3& rhs) const
	{
		return pfVector3(m_fx + rhs.m_fx, m_fy + rhs.m_fy, m_fz + rhs.m_fz);
	}

	pfVector3 operator*(const float a, const pfVector3 vec)
	{
		return pfVector3(a*vec.m_fx, a*vec.m_fy, a*vec.m_fz);
	}

	std::ostream& operator<<(std::ostream& os, const pfVector3& vec)
	{
		os << "(" << vec.m_fx << "," << vec.m_fy << "," << vec.m_fz << ")";
		return os;
	}

}


