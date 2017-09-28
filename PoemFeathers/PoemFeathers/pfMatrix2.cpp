#include "pfPrivatePCH.h"

namespace PoemFeathers
{
	pfMatrix2::pfMatrix2()
	{
		Identity();
	}


	pfMatrix2::pfMatrix2(const float src[4])
	{
		Set(src);
	}

	pfMatrix2::pfMatrix2(float m0, float m1, float m2, float m3)
	{
		Set(m0, m1, m2, m3);
	}

	pfMatrix2::~pfMatrix2()
	{
	}

	void pfMatrix2::Set(const float src[4])
	{
		m[0] = src[0];
		m[1] = src[1];
		m[2] = src[2];
		m[3] = src[3];
	}

	void pfMatrix2::Set(float m0, float m1, float m2, float m3)
	{
		m[0] = m0;
		m[1] = m1;
		m[2] = m2;
		m[3] = m3;
	}

	void pfMatrix2::SetRow(int index, const float row[2])
	{
		m[index] = row[0];
		m[index + 2] = row[1];
	}

	void pfMatrix2::SetRow(int index, const pfVector2& v)
	{
		m[index] = v.GetX();
		m[index + 2] = v.GetY();
	}

	void pfMatrix2::SetColumn(int index, const float colum[2])
	{
		m[index * 2] = colum[0];
		m[index * 2 + 1] = colum[1];
	}

	void pfMatrix2::SetColumn(int index, const pfVector2& v)
	{
		m[index * 2] = v.GetX();
		m[index * 2 + 1] = v.GetY();
	}

	const float* pfMatrix2::Get() const
	{
		return m;
	}

	float pfMatrix2::GetDeterminant()
	{
		return m[0] * m[3] - m[1] * m[2];
	}

	pfMatrix2& pfMatrix2::Identity()
	{
		m[0] = m[3] = 1.0f;
		m[1] = m[2] = 0.0f;
		return *this;
	}

	pfMatrix2& pfMatrix2::Transpose()
	{
		std::swap(m[1], m[2]);
		return *this;
	}

	pfMatrix2& pfMatrix2::Invert()
	{
		float determinant = GetDeterminant();
		if (fabs(determinant) <= EPSILON)
		{
			return Identity();
		}
		float tmp0 = m[0];
		float invDeterminant = 1.0f / determinant;
		m[0] = invDeterminant*m[3];
		m[1] = -invDeterminant*m[1];
		m[2] = -invDeterminant*m[2];
		m[3] = invDeterminant* tmp0;

		return *this;
	}

	pfMatrix2 pfMatrix2::operator+(const pfMatrix2& rhs) const
	{
		return pfMatrix2(m[0] + rhs[0], m[1] + rhs[1], m[2] + rhs[2], m[3] + rhs[3]);
	}

	float pfMatrix2::operator[](int index) const
	{
		return m[index];
	}

	float pfMatrix2::operator[](int index)
	{
		return m[index];
	}

	pfMatrix2 pfMatrix2::operator-(const pfMatrix2& rhs) const
	{
		return pfMatrix2(m[0] - rhs[0], m[1] - rhs[1], m[2] - rhs[2], m[3] - rhs[3]);
	}

	pfMatrix2& pfMatrix2::operator-=(const pfMatrix2& rhs)
	{
		m[0] = m[0] - rhs[0];
		m[1] = m[1] - rhs[1];
		m[2] = m[2] - rhs[2];
		m[3] = m[3] - rhs[3];
		return *this;

	}

	pfVector2 pfMatrix2::operator*(const pfVector2& rhs) const
	{
		return pfVector2(m[0] * rhs.GetX() + m[1] * rhs.GetY(), m[2] * rhs.GetX() + m[3] * rhs.GetY());
	}

	pfMatrix2 pfMatrix2::operator*(const pfMatrix2& rhs) const
	{
		return pfMatrix2(m[0] * rhs[0] + m[1] * rhs[2], m[0] * rhs[1] + m[1] * rhs[3],
			m[2] * rhs[0] + m[3] * rhs[2], m[2] * rhs[1] + m[3] * rhs[3]);
	}

	pfMatrix2& pfMatrix2::operator*=(const pfMatrix2& rhs)
	{
		*this = *this * rhs;
		return *this;
	}

	bool pfMatrix2::operator!=(const pfMatrix2& rhs) const
	{
		return (m[0] != rhs[0]) || (m[1] != rhs[1]) || (m[2] != rhs[2]) || (m[3] != rhs[3]);
	}

	bool pfMatrix2::operator==(const pfMatrix2& rhs) const
	{
		return (m[0] == rhs[0]) && (m[1] == rhs[1]) && (m[2] == rhs[2]) && (m[3] * rhs[3]);
	}

	pfMatrix2& pfMatrix2::operator+=(const pfMatrix2& rhs)
	{
		m[0] += rhs[0];
		m[1] += rhs[1];
		m[2] += rhs[2];
		m[3] += rhs[3];
		return *this;
	}
	pfMatrix2 operator-(const pfMatrix2& m)
	{
		return pfMatrix2(-m[0], -m[1], -m[2], -m[3]);
	}

	pfMatrix2 operator*(float scalar, const pfMatrix2& m)
	{
		return pfMatrix2(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar);
	}

	pfVector2 operator*(const pfVector2& vec, const pfMatrix2& m)
	{
		return pfVector2(m[0] * vec.GetX() + m[1] * vec.GetY(), m[2] * vec.GetX() + m[3] * vec.GetY());
	}

	std::ostream& operator<<(std::ostream& os, const pfMatrix2& m)
	{
		os << std::fixed << std::setprecision(5);
		os << "[" << std::setw(10) << m[0] << " " << std::setw(10) << m[1] << "]\n"
			<< "[" << std::setw(10) << m[2] << " " << std::setw(10) << m[3] << "]\n";
		os << std::resetiosflags(std::ios_base::fixed || std::ios_base::floatfield);
		return os;
	}

}


