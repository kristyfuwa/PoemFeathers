#include "pfPrivatePCH.h"
namespace PoemFeathers
{
	void Split(std::vector<std::string> &v, std::string s, std::string delimitor)
	{
		size_t pos = s.find_first_of(delimitor);
		size_t last_pos = 0;
		v.clear();
		while (pos != std::string::npos)
		{
			v.push_back(s.substr(last_pos, pos-last_pos));
			last_pos = pos + delimitor.size();
			pos = s.find_first_of(delimitor, last_pos);
		}
		if (pos < s.size())
			v.push_back(s.substr(last_pos));
	}


	//	  .Q
	//	 .
	//	.
	//A...........B
	// .		 .
	//  .	P   .
	//   .	   .
	//    .	  .
	//     . .
	//      C
	bool SameSide(pfVector3 A, pfVector3 B, pfVector3 C, pfVector3 P)
	{
		//�ж���������ĳ���߶ε�ͬһ���أ�����ͨ�������ʵ�֣�
		//����PA����PA��AB��������ٽ�CA��AB�������
		//�����������Ľ������һ�£���ô��������ͬһ�⡣
		//�ж������������Ƿ�ͬ������õ��ʵ�֣�����������0��
		//���������н�����ǣ������Ƕ۽ǡ�
		pfVector3 AB = B - A;
		pfVector3 AP = P - A;
		pfVector3 AC = C - A;

		pfVector3 v1 = AB.Cross(AP);
		pfVector3 v2 = AB.Cross(AC);

		return v1.Dot(v2) >= 0;
	}

	bool PointInTriangle(pfVector3 A, pfVector3 B, pfVector3 C, pfVector3 P)
	{
		return SameSide(A, B, C, P) &&
			SameSide(B, C, A, P) &&
			SameSide(C, A, B, P);
	}


	int SameNumber(pfVector2 beginPoint, pfVector2 endPoint, pfVector2 point)
	{
		//�ٶ��ߵ�ͷ�ǣ�X+dX, Y+dY����β�ǣ�X, Y��
		//������3���ߵķ��̣�E(x, y) = dY(x - X) - dX(y - Y)
			//չ��֮����dY*x + (-dX)*y + (dX*Y - dY*X) = 0
			//��Ax + By + C = 0
			//����A = dY, B = -dX, C = dX*Y - dY*X
		float A = endPoint.GetY() - beginPoint.GetY();
		float B = -(endPoint.GetX() - beginPoint.GetX());
		float C = -B*beginPoint.GetY() - A*beginPoint.GetX();
		return A*point.GetX() + B*point.GetY() + C;
	}

	bool PointInTriangleOnScreen(pfVector2 A, pfVector2 B, pfVector2 C, pfVector2 P)
	{
		return ((SameNumber(A, B, P) > 0) && (SameNumber(A, C, P) > 0) && (SameNumber(B, C, P) > 0)) ||
			((SameNumber(A, B, P) < 0) && (SameNumber(A, C, P) < 0) && (SameNumber(B, C, P) < 0)) || ((SameNumber(A, B, P) == 0 && SameNumber(A, C, P) == 0)) ||
			((SameNumber(A, B, P) == 0 && SameNumber(B, C, P) == 0)) || ((SameNumber(B, C, P) == 0 && SameNumber(A, C, P) == 0));
	}
}