#pragma once
namespace PoemFeathers
{
	class pfCore_API pfMatrix2
	{
	public:
		pfMatrix2();
		pfMatrix2(const float src[4]);
		pfMatrix2(float m0, float m1, float m2, float m3);
		~pfMatrix2();


		void            Set(const float src[4]);
		void            Set(float m0, float m1, float m2, float m3);
		void            SetRow(int index, const float row[2]);
		void			SetRow(int index, const pfVector2& v);
		void			SetColumn(int index, const float colum[2]);
		void			SetColumn(int index, const pfVector2& v);

		const float*	Get()const;
		float			GetDeterminant();

		pfMatrix2&		Identity();
		pfMatrix2&		Transpose();
		pfMatrix2&		Invert();

		pfMatrix2		operator+(const pfMatrix2& rhs) const;
		pfMatrix2		operator-(const pfMatrix2& rhs) const;
		pfMatrix2&		operator+=(const pfMatrix2& rhs);
		pfMatrix2&		operator-=(const pfMatrix2& rhs);
		pfVector2		operator*(const pfVector2& rhs) const;
		pfMatrix2		operator*(const pfMatrix2& rhs) const;
		pfMatrix2&		operator*=(const pfMatrix2& rhs);
		bool			operator==(const pfMatrix2& rhs) const;
		bool			operator!=(const pfMatrix2& rhs) const;
		float			operator[](int index) const;
		float			operator[](int index);

		friend pfMatrix2 operator-(const pfMatrix2& m);
		friend pfMatrix2 operator*(float scalar, const pfMatrix2& m);
		friend pfVector2 operator*(const pfVector2& vec, const pfMatrix2& m);
		friend std::ostream& operator<<(std::ostream& os, const pfMatrix2& m);

	private:
		float m[4];
	};
}


