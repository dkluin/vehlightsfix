/*
* Copyright (C) 2014-2017  fastman92 <fastman92@gmail.com>, website: http://fastman92.com
* Licensed under the MIT License, see LICENSE at top level directory.
*
*/

#pragma once

#define F92_LA_CONVENTION

#define UNDEFINED_FILE_ID_INT32 -1
#define UNKNOWN_MODEL_ID_MINUS_2 -2
#define MAX_FILE_ID_UINT16 0xFFFD
#define MAX_FILE_ID_INT32 0x7FFFFFFF

#include "Library.h"

#if !defined(STRINGIFY) || defined(TOSTRING)
#define STRINGIFY(str) #str
#define TOSTRING(x) STRINGIFY(x)
#endif

#define SET_FUNCTION_ADDRESS(functionName) if(phModule)*(void**)&funcs.functionName = Library::GetSymbolAddress(phModule, TOSTRING(functionName)); else funcs.functionName = 0;

class CFastman92limitAdjuster
{
public:
	// hModule
	static tGenericLibraryModule hModule;

	// Initializes everything related to the FLA
	static void Init();
};