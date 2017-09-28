#pragma once
#if pfPLATFORM == pfPLATFORM_WIN
#	define WIN32_LEAN_AND_MEAN				// 从 Windows 头中排除极少使用的资料
#   include<windows.h>
#	include<tchar.h>

#endif

//#include <thread>
#if pfPLATFORM == pfPLATFORM_WIN
#	include<process.h>
#	include<objbase.h>
#endif

#include <ctime>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>

#if pfPLATFORM == pfPLATFORM_WIN
#	include<direct.h>
#	include<mmsystem.h>
#	include<io.h>
#endif

#include <memory.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>

//STL
#include <Algorithm>
#include <tuple>
#include <initializer_list>
#include <string>
#include <forward_list>
#include <array>
#include <list>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

#ifndef FALSE
#define FALSE	0
#endif // !FALSE

#ifndef TRUE
#define TRUE	1
#endif // !TRUE


namespace PoemFeathers
{

}