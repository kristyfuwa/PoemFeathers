#pragma once
namespace PoemFeathers
{
	class pfCore_API pfVector4
	{
	public:
		pfVector4();
		pfVector4(float x, float y, float z, float w);
		~pfVector4();

		void			Set(float x, float y, float z, float w);
		float			Length() const;
		float			Distance(const pfVector4& vec)	const;
		pfVector4&		Normalize();
		float			Dot(const pfVector4& vec)	const;
		bool			Equal(const pfVector4& vec, float e)	const;

		pfVector4		operator-()	const;
		pfVector4		operator+(const pfVector4& rhs)	const;
		pfVector4		operator-(const pfVector4& rhs)	const;
		pfVector4		operator*(const pfVector4& rhs)	const;
		pfVector4		operator/(const float scale)	const;
		pfVector4&		operator+=(const pfVector4& rhs);
		pfVector4&		operator-=(const pfVector4& rhs);
		pfVector4&		operator*=(const float scale);
		pfVector4&		operator*=(const pfVector4& rhs);
		pfVector4&		operator/=(const float scale);

		bool			operator==(const pfVector4& rhs) const;
		bool			operator!=(const pfVector4& rhs)	const;
		bool			operator<(const pfVector4& rhs)	const;
		float			operator[](int index)	const;
		float&			operator[](int index);

		friend	pfVector4 operator*(const float a, const pfVector4 vec);
		friend std::ostream& operator<<(std::ostream& os, const pfVector4& vec);

	private:
		float			m_fx;
		float			m_fy;
		float			m_fz;
		float			m_fw;
	};
}


