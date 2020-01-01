/*
* Copyright (C) 2014-2017  fastman92 <fastman92@gmail.com>, website: http://fastman92.com
* Licensed under the MIT License, see LICENSE at top level directory.
*
*/
#include "../../StdInc.h"
#include "Main.h"

#include "FileInfoMemberAccess.h"
#include "IDaccess.h"

#ifdef IS_PLATFORM_ANDROID
#include <dlfcn.h>
#endif

// hModule
tGenericLibraryModule CFastman92limitAdjuster::hModule = { 0 };

// Initializes everything related to the FLA
void CFastman92limitAdjuster::Init()
{
	// Get library address
#ifdef IS_PLATFORM_WIN_X86
	hModule.windows = GetModuleHandleA("$fastman92limitAdjuster.asi");
#elif defined(IS_PLATFORM_WIN_X64)
	hModule.windows = GetModuleHandleA("$fastman92limitAdjusterX64.asi");
#elif defined(IS_PLATFORM_ANDROID)
	#define STRINGIFY(str) #str
	#define TOSTRING(x) STRINGIFY(x)
#define FLA_FILENAME "libplugin_fastman92limitAdjuster_" TOSTRING(SOLUTION_PLATFORM) ".so"

	hModule.linux_os = dlopen(FLA_FILENAME, 4);	// 4 - RTLD_NOLOAD
#endif

	//////////////////////////////
	FileInfoMemberAccess::Init();
	IDaccess::Init();
}