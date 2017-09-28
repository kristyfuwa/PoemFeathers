#include "pfPrivatePCH.h"

namespace PoemFeathers
{
	pfVector4::pfVector4() :m_fx(0.0f), m_fy(0.0f), m_fz(0.0f), m_fw(0.0f)
	{
	}


	pfVector4::pfVector4(float x, float y, float z, float w) : m_fx(x), m_fy(y), m_fz(z), m_fw(w)
	{

	}

	pfVector4::~pfVector4()
	{
	}

	void pfVector4::Set(float x, float y, float z, float w)
	{
		m_fx = x;
		m_fy = y;
		m_fz = z;
		m_fw = w;
	}

	float pfVector4::Length() const
	{
		return sqrtf(m_fx*m_fx + m_fy*m_fy + m_fz*m_fz + m_fw*m_fw);
	}

	float pfVector4::Distance(const pfVector4& vec) const
	{
		return sqrtf((vec.m_fx - m_fx)*(vec.m_fx - m_fx) + (vec.m_fy - m_fy)*(vec.m_fy - m_fy) + (vec.m_fz - m_fz)*(vec.m_fz - m_fz) + (vec.m_fw - m_fw)*(vec.m_fw - m_fw));
	}

	pfVector4& pfVector4::Normalize()
	{
		float value = (m_fx*m_fx + m_fy*m_fy + m_fz*m_fz + m_fw*m_fw);
		float length = 1.0f / sqrtf(value);

		m_fx *= length;
		m_fy *= length;
		m_fz *= length;
		m_fw *= length;

		return *this;

	}

	float pfVector4::Dot(const pfVector4& vec) const
	{
		return (m_fx*vec.m_fx + m_fy*vec.m_fy + m_fz*vec.m_fz + m_fw*vec.m_fw);
	}

	bool pfVector4::Equal(const pfVector4& vec, float e) const
	{
		return fabs(m_fx - vec.m_fx) < e && fabs(m_fy - vec.m_fy) < e &&
			fabs(m_fz - vec.m_fz) < e && fabs(m_fw - vec.m_fw);
	}

	pfVector4 pfVector4::operator-() const
	{
		return pfVector4(-m_fx, -m_fy, -m_fz, -m_fw);
	}

	pfVector4 pfVector4::operator-(const pfVector4& rhs) const
	{
		return pfVector4(m_fx - rhs.m_fx, m_fy - rhs.m_fy, m_fz - rhs.m_fz, m_fw - rhs.m_fw);
	}

	bool pfVector4::operator==(const pfVector4& rhs) const
	{
		return (m_fx == rhs.m_fx) && (m_fy == rhs.m_fy) &&
			(m_fz == rhs.m_fz) && (m_fw == rhs.m_fw);
	}

	bool pfVector4::operator!=(const pfVector4& rhs) const
	{
		return (m_fx != rhs.m_fx) || (m_fy != rhs.m_fy) ||
			(m_fz != rhs.m_fz) || (m_fw != rhs.m_fw);
	}

	bool pfVector4::operator<(const pfVector4& rhs) const
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
		if (m_fw < rhs.m_fw)
			return true;
		if (m_fw > rhs.m_fw)
			return false;
		return false;
	}

	float pfVector4::operator[](int index) const
	{
		return (&m_fx)[index];
	}

	float& pfVector4::operator[](int index)
	{
		return (&m_fx)[index];
	}

	pfVector4 pfVector4::operator*(const pfVector4& rhs) const
	{
		return pfVector4(m_fx*rhs.m_fx, m_fy*rhs.m_fy, m_fz*rhs.m_fz, m_fw*rhs.m_fw);
	}

	pfVector4 pfVector4::operator/(const float scale) const
	{
		return pfVector4(m_fx / scale, m_fy / scale, m_fz / scale, m_fw / scale);
	}

	pfVector4& pfVector4::operator/=(const float scale)
	{
		m_fx /= scale;
		m_fy /= scale;
		m_fz /= scale;
		m_fw /= scale;
		return *this;
	}

	pfVector4& pfVector4::operator*=(const pfVector4& rhs)
	{
		m_fx *= rhs.m_fx;
		m_fy *= rhs.m_fy;
		m_fz *= rhs.m_fz;
		m_fw *= rhs.m_fw;
		return *this;
	}

	pfVector4& pfVector4::operator*=(const float scale)
	{
		m_fx *= scale;
		m_fy *= scale;
		m_fz *= scale;
		m_fw *= scale;
		return *this;
	}

	pfVector4& pfVector4::operator-=(const pfVector4& rhs)
	{
		m_fx -= rhs.m_fx;
		m_fy -= rhs.m_fy;
		m_fz -= rhs.m_fz;
		m_fw -= rhs.m_fw;
		return *this;
	}

	pfVector4& pfVector4::operator+=(const pfVector4& rhs)
	{
		m_fx += rhs.m_fx;
		m_fy += rhs.m_fy;
		m_fz += rhs.m_fz;
		m_fw += rhs.m_fw;
		return *this;
	}

	pfVector4 pfVector4::operator+(const pfVector4& rhs) const
	{
		return pfVector4(m_fx + rhs.m_fx, m_fy + rhs.m_fy, m_fz + rhs.m_fz, m_fw + rhs.m_fw);
	}

	pfVector4 operator*(const float a, const pfVector4 vec)
	{
		return pfVector4(a*vec.m_fx, a*vec.m_fy, a*vec.m_fz, a*vec.m_fw);
	}

	std::ostream& operator<<(std::ostream& os, const pfVector4& vec)
	{
		os << "(" << vec.m_fx << "," << vec.m_fy << "," << vec.m_fz << "," << vec.m_fw << ")";
		return os;
	}
}

