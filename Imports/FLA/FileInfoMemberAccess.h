/*
* Copyright (C) 2014-2017  fastman92 <fastman92@gmail.com>, website: http://fastman92.com
* Licensed under the MIT License, see LICENSE at top level directory.
*
*/

#pragma once
#include "Main.h"

#include <stdint.h>

// Function pointers
struct tFileInfoMemberAccessFuncs
{
public:
	// Returns model info, prev file ID
	int32_t (F92_LA_CONVENTION *GetFileInfoPrevFileID)(int32_t fileID);

	// Returns model info, next file ID
	int32_t (F92_LA_CONVENTION *GetFileInfoNextFileID)(int32_t fileID);

	// Returns model info, next on CD file ID
	int32_t (F92_LA_CONVENTION *GetFileInfoNextOnCDfileID)(int32_t fileID);

	// Sets file info, Prev file ID 
	void (F92_LA_CONVENTION *SetFileInfoPrevFileID)(int32_t fileID, int32_t newValue);

	// Sets file info, Next file ID
	void (F92_LA_CONVENTION *SetFileInfoNextFileID)(int32_t fileID, int32_t newValue);

	// Sets file info, NextOnCd file ID
	void (F92_LA_CONVENTION *SetFileInfoNextOnCDfileID)(int32_t fileID, int32_t newValue);
};

class FileInfoMemberAccess
{
public:
	// pointers of functions
	static tFileInfoMemberAccessFuncs funcs;

	// actual functions
	// Returns model info, prev file ID
	int32_t GetFileInfoPrevFileID(int32_t fileID);

	// Returns model info, next file ID
	int32_t GetFileInfoNextFileID(int32_t fileID);

	// Returns model info, next on CD file ID
	int32_t GetFileInfoNextOnCDfileID(int32_t fileID);

	// Sets file info, Prev file ID 
	void SetFileInfoPrevFileID(int32_t fileID, int32_t newValue);

	// Sets file info, Next file ID
	void SetFileInfoNextFileID(int32_t fileID, int32_t newValue);

	// Sets file info, NextOnCd file ID
	void SetFileInfoNextOnCDfileID(int32_t fileID, int32_t newValue);

	// Initializes
	static void Init();
};