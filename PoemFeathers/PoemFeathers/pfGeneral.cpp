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
		//判断两个点在某条线段的同一侧呢？可以通过叉积来实现，
		//连接PA，将PA和AB做叉积，再将CA和AB做叉积，
		//如果两个叉积的结果方向一致，那么两个点在同一测。
		//判断两个向量的是否同向可以用点积实现，如果点积大于0，
		//则两向量夹角是锐角，否则是钝角。
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