#pragma once
namespace PoemFeathers
{
	class pfCore_API pfVector3
	{
	public:
		pfVector3();
		pfVector3(float x, float y, float z);
		~pfVector3();

		float		GetX() const;
		float		GetY() const;
		float		GetZ() const;
		void		Set(float x, float y, float z);
		float		Length() const;
		float		Distance(const pfVector3& vec) const;
		pfVector3&	Normalize();
		float		Dot(const pfVector3& vec) const;
		pfVector3	Cross(const pfVector3& vec) const;
		bool		Equal(const pfVector3& vec, float e) const;

		pfVector3	operator-()	const;
		pfVector3	operator+(const pfVector3& rhs)  const;
		pfVector3	operator-(const pfVector3& rhs)	const;
		pfVector3&	operator+=(const pfVector3& rhs);
		pfVector3&	operator-=(const pfVector3& rhs);
		pfVector3	operator*(const float scale)	const;
		pfVector3	operator*(const pfVector3& rhs)	const;
		pfVector3&	operator*=(const float scale);
		pfVector3&	operator*=(const pfVector3& rhs);
		pfVector3	operator/(const float scale)	const;
		pfVector3&	operator/=(const float scale);
		bool		operator==(const pfVector3& rhs) const;
		bool		operator!=(const pfVector3& rhs)	const;
		bool		operator<(const pfVector3& rhs)	const;
		float		operator[](int index)	const;
		float&		operator[](int index);

		friend pfVector3 operator*(const float a, const pfVector3 vec);
		friend std::ostream& operator<<(std::ostream& os, const pfVector3& vec);

	private:
		float		m_fx;
		float		m_fy;
		float		m_fz;
	};
}


