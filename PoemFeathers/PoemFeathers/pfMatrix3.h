#pragma once
namespace PoemFeathers
{
	class pfCore_API pfMatrix3
	{
	public:
		pfMatrix3();
		pfMatrix3(const float src[9]);
		pfMatrix3(float m0, float m1, float m2,
			float m3, float m4, float m5,
			float m6, float m7, float m8);
		~pfMatrix3();

		void Set(const float src[9]);
		void Set(float m0, float m1, float m2,
			float m3, float m4, float m5,
			float m6, float m7, float m8);
		void SetRow(int index, const float row[3]);
		void SetRow(int index, const pfVector3& vec);
		void SetColumn(int index, const float column[3]);
		void SetColumn(int index, const pfVector3& vec);

		const float* Get() const;
		float GetDeterminant();

		pfMatrix3& Identity();
		pfMatrix3& Transpose();
		pfMatrix3& Invert();

		pfMatrix3 operator+(const pfMatrix3& rhs) const;
		pfMatrix3 operator-(const pfMatrix3& rhs) const;
		pfMatrix3& operator+=(const pfMatrix3& rhs);
		pfMatrix3& operator-=(const pfMatrix3& rhs);
		pfVector3  operator*(const pfVector3& rhs) const;
		pfMatrix3 operator*(const pfMatrix3& rhs) const;
		pfMatrix3& operator*=(const pfMatrix3& rhs);

		bool	operator==(const pfMatrix3& rhs) const;
		bool	operator!=(const pfMatrix3& rhs) const;
		float   operator[](int index) const;
		float&  operator[](int index);

		friend pfMatrix3 operator-(const pfMatrix3& m);
		friend pfMatrix3 operator*(float scale, const pfMatrix3& m);
		friend pfVector3 operator*(const pfVector3& vec, const pfMatrix3& m);
		friend std::ostream& operator<<(std::ostream& os, const pfMatrix3& m);
	private:
		float m[9];
	};
}


