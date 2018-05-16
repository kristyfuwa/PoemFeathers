#pragma once
namespace PoemFeathers
{
	pfCore_API void Split(std::vector<std::string> &v, std::string s, std::string delimitor);

	pfCore_API bool SameSide(pfVector3 A, pfVector3 B, pfVector3 C, pfVector3 P);

	pfCore_API bool PointInTriangle(pfVector3 A, pfVector3 B, pfVector3 C, pfVector3 P);

	pfCore_API int SameNumber(pfVector2 beginPoint, pfVector2 endPoint, pfVector2 point);

	pfCore_API bool PointInTriangleOnScreen(pfVector2 A, pfVector2 B, pfVector2 C, pfVector2 P);
}
