#pragma once

#define pfPLATFORM_WIN 1

#if defined(_WINDOWS) || defined(_WIN32)
#define pfPLATFORM pfPLATFORM_WIN
#endif


#if pfPLATFORM == pfPLATFORM_WIN
#	define pfCore_API _declspec(dllexport)
#else
#	error "Unsupported pfCore_API"
#endif

#pragma warning(disable:4251)

//const
const float EPSILON = 0.00001f;


//Platform
#include "pfPlatform.h"


//Log
#include "pfLog.h"

//Math
#include "pfVector2.h"
#include "pfVector3.h"
#include "pfVector4.h"
#include "pfMatrix2.h"
#include "pfMatrix3.h"

//General
#include "pfGeneral.h"




