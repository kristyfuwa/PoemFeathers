#include "pfPrivatePCH.h"

namespace PoemFeathers
{
	pfMatrix3::pfMatrix3()
	{
		Identity();
	}


	pfMatrix3::pfMatrix3(const float src[9])
	{
		Set(src);
	}

	pfMatrix3::pfMatrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
	{
		Set(m0, m1, m2, m3, m4, m5, m6, m7, m8);
	}

	pfMatrix3::~pfMatrix3()
	{
	}

	void pfMatrix3::Set(const float src[9])
	{
		m[0] = src[0];
		m[1] = src[1];
		m[2] = src[2];
		m[3] = src[3];
		m[4] = src[4];
		m[5] = src[5];
		m[6] = src[6];
		m[7] = src[7];
		m[8] = src[8];
	}

	void pfMatrix3::Set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
	{
		m[0] = m0;
		m[1] = m1;
		m[2] = m2;
		m[3] = m3;
		m[4] = m4;
		m[5] = m5;
		m[6] = m6;
		m[7] = m7;
		m[8] = m8;
	}

	void pfMatrix3::SetRow(int index, const float row[3])
	{
		m[index] = row[0];
		m[index + 3] = row[1];
		m[index + 6] = row[2];
	}

	void pfMatrix3::SetRow(int index, const pfVector3& vec)
	{
		m[index] = vec.GetX();
		m[index + 3] = vec.GetY();
		m[index + 6] = vec.GetZ();
	}

	void pfMatrix3::SetColumn(int index, const float column[3])
	{
		m[index * 3] = column[0];
		m[index * 3 + 1] = column[1];
		m[index * 3 + 2] = column[2];
	}

	void pfMatrix3::SetColumn(int index, const pfVector3& vec)
	{
		m[index * 3] = vec.GetX();
		m[index * 3 + 1] = vec.GetY();
		m[index * 3 + 2] = vec.GetZ();
	}

	const float* pfMatrix3::Get() const
	{
		return m;
	}

	float pfMatrix3::GetDeterminant()
	{
		return m[0] * (m[4] * m[8] - m[5] * m[7]) -
			m[1] * (m[3] * m[8] - m[5] * m[6]) +
			m[2] * (m[3] * m[7] - m[4] * m[6]);
	}

	pfMatrix3& pfMatrix3::Identity()
	{
		m[0] = m[4] = m[8] = 1.0f;
		m[1] = m[2] = m[3] = m[5] = m[6] = m[7] = 0.0f;
		return *this;
	}

	pfMatrix3& pfMatrix3::Transpose()
	{
		std::swap(m[1], m[3]);
		std::swap(m[2], m[6]);
		std::swap(m[5], m[7]);
		return *this;
	}

	pfMatrix3& pfMatrix3::Invert()
	{
		float determinant, invDeterminant;
		float tmp[9];
		tmp[0] = m[4] * m[8] - m[5] * m[7];
		tmp[1] = m[2] * m[7] - m[1] * m[8];
		tmp[2] = m[1] * m[5] - m[2] * m[4];
		tmp[3] = m[5] * m[6] - m[3] * m[8];
		tmp[4] = m[0] * m[8] - m[2] * m[6];
		tmp[5] = m[2] * m[3] - m[0] * m[5];
		tmp[6] = m[3] * m[7] - m[4] * m[6];
		tmp[7] = m[1] * m[6] - m[0] * m[7];
		tmp[8] = m[0] * m[4] - m[1] * m[3];
		determinant = m[0] * tmp[0] + m[1] * tmp[3] + m[2] * tmp[6];
		if (fabs(determinant <= EPSILON))
		{
			return Identity();
		}
		invDeterminant = 1.0f / determinant;
		m[0] = invDeterminant*tmp[0];
		m[1] = invDeterminant*tmp[1];
		m[2] = invDeterminant*tmp[2];
		m[3] = invDeterminant*tmp[3];
		m[4] = invDeterminant*tmp[4];
		m[5] = invDeterminant*tmp[5];
		m[6] = invDeterminant*tmp[6];
		m[7] = invDeterminant*tmp[7];
		m[8] = invDeterminant*tmp[8];

		return *this;
	}

	pfMatrix3 pfMatrix3::operator+(const pfMatrix3& rhs) const
	{
		return pfMatrix3(m[0] + rhs[0], m[1] + rhs[1], m[2] + rhs[2],
			m[3] + rhs[3], m[4] + rhs[4], m[5] + rhs[5],
			m[6] + rhs[6], m[7] + rhs[7], m[8] + rhs[8]);
	}

	float pfMatrix3::operator[](int index) const
	{
		return m[index];
	}

	float& pfMatrix3::operator[](int index)
	{
		return m[index];
	}

	pfMatrix3 pfMatrix3::operator-(const pfMatrix3& rhs) const
	{
		return pfMatrix3(m[0] - rhs[0], m[1] - rhs[1], m[2] - rhs[2],
			m[3] - rhs[3], m[4] - rhs[4], m[5] - rhs[5],
			m[6] - rhs[6], m[7] - rhs[7], m[8] - rhs[8]);
	}

	pfMatrix3& pfMatrix3::operator-=(const pfMatrix3& rhs)
	{
		m[0] -= rhs[0];
		m[1] -= rhs[1];
		m[2] -= rhs[2];
		m[3] -= rhs[3];
		m[4] -= rhs[4];
		m[5] -= rhs[5];
		m[6] -= rhs[6];
		m[7] -= rhs[7];
		m[8] -= rhs[8];
		return *this;
	}

	pfVector3 pfMatrix3::operator*(const pfVector3& rhs) const
	{
		return pfVector3(m[0] * rhs.GetX() + m[1] * rhs.GetY() + m[2] * rhs.GetZ(),
			m[3] * rhs.GetX() + m[4] * rhs.GetY() + m[5] * rhs.GetZ(),
			m[6] * rhs.GetX() + m[7] * rhs.GetY() + m[8] * rhs.GetZ());
	}

	pfMatrix3 pfMatrix3::operator*(const pfMatrix3& rhs) const
	{
		return pfMatrix3(m[0] * rhs[0] + m[1] * rhs[3] + m[2] * rhs[6], m[0] * rhs[1] + m[1] * rhs[4] + m[2] * rhs[7], m[0] * rhs[2] + m[1] * rhs[5] + m[2] * rhs[8],
			m[3] * rhs[0] + m[4] * rhs[3] + m[5] * rhs[6], m[3] * rhs[1] + m[4] * rhs[4] + m[5] * rhs[7], m[3] * rhs[2] + m[4] * rhs[5] + m[5] * rhs[8],
			m[6] * rhs[0] + m[7] * rhs[3] + m[8] * rhs[6], m[6] * rhs[1] + m[7] * rhs[4] + m[8] * rhs[7], m[6] * rhs[2] + m[7] * rhs[5] + m[8] * rhs[8]);
	}

	pfMatrix3& pfMatrix3::operator*=(const pfMatrix3& rhs)
	{
		*this = *this * rhs;
		return *this;
		
	}

	bool pfMatrix3::operator!=(const pfMatrix3& rhs) const
	{
		return m[0] != rhs[0] || m[1] != rhs[1] || m[2] != rhs[2] ||
			m[3] != rhs[3] || m[4] != rhs[4] || m[5] != rhs[5] ||
			m[6] != rhs[6] || m[7] != rhs[7] || m[8] != rhs[8];
	}

	bool pfMatrix3::operator==(const pfMatrix3& rhs) const
	{
		return m[0] == rhs[0] && m[1] == rhs[1] && m[2] == rhs[2] &&
			m[3] == rhs[3] && m[4] == rhs[4] && m[5] == rhs[5] &&
			m[6] == rhs[6] && m[7] == rhs[7] && m[8] == rhs[8];
	}

	pfMatrix3& pfMatrix3::operator+=(const pfMatrix3& rhs)
	{
		m[0] += rhs[0];
		m[1] += rhs[1];
		m[2] += rhs[2];
		m[3] += rhs[3];
		m[4] += rhs[4];
		m[5] += rhs[5];
		m[6] += rhs[6];
		m[7] += rhs[7];
		m[8] += rhs[8];
		return *this;
	}



	pfMatrix3 operator-(const pfMatrix3& rhs)
	{
		return pfMatrix3(- rhs[0],- rhs[1],- rhs[2],
						 - rhs[3],- rhs[4],- rhs[5],
						 - rhs[6],- rhs[7],- rhs[8]);
	}

	pfMatrix3 operator*(float scale, const pfMatrix3& m)
	{
		return pfMatrix3(scale*m[0], scale*m[1], scale*m[2],
			scale*m[3], scale*m[4], scale*m[5],
			scale*m[6], scale*m[7], scale*m[8]);
	}

	pfVector3 operator*(const pfVector3& vec, const pfMatrix3& m)
	{
		return pfVector3(vec.GetX() * m[0] + vec.GetY() * m[3] + vec.GetZ() * m[6],
			vec.GetX() * m[1] + vec.GetY() * m[4] + vec.GetZ() * m[7],
			vec.GetX() * m[2] + vec.GetY() * m[5] + vec.GetZ() * m[8]);
	}

	std::ostream& operator<<(std::ostream& os, const pfMatrix3& m)
	{
		os << std::fixed << std::setprecision(5);
		os << "[" << std::setw(10) << m[0] << " " << std::setw(10) << m[1] << " " << std::setw(10) << m[2] << "]\n"
			<< "[" << std::setw(10) << m[3] << " " << std::setw(10) << m[4] << " " << std::setw(10) << m[5] << "]\n"
			<< "[" << std::setw(10) << m[6] << " " << std::setw(10) << m[7] << " " << std::setw(10) << m[8] << "]\n";
		os << std::resetiosflags(std::ios_base::fixed || std::ios_base::floatfield);
		return os;
	}

}
