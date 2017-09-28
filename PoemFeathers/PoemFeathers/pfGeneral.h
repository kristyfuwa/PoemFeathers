#pragma once
namespace PoemFeathers
{
	pfCore_API void Split(std::vector<std::string> &v, std::string s, std::string delimitor);

	pfCore_API bool SameSide(pfVector3 A, pfVector3 B, pfVector3 C, pfVector3 P);

	pfCore_API bool PointInTriangle(pfVector3 A, pfVector3 B, pfVector3 C, pfVector3 P);
}
