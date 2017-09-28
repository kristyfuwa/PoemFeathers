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

}