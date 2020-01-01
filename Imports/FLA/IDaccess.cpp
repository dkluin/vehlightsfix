/*
* Copyright (C) 2014-2017  fastman92 <fastman92@gmail.com>, website: http://fastman92.com
* Licensed under the MIT License, see LICENSE at top level directory.
*
*/
#include "../../StdInc.h"
#include "IDaccess.h"

// pointers of functions
tIDaccessFuncs IDaccess::funcs;

// Initializes
void IDaccess::Init()
{
	tGenericLibraryModule* phModule = &CFastman92limitAdjuster::hModule;

	SET_FUNCTION_ADDRESS(AreDifficultIDsExtended);
	SET_FUNCTION_ADDRESS(GetExtendedIDfrom16bitBefore);
	SET_FUNCTION_ADDRESS(SetExtendedIDfrom16bitBefore);

	SET_FUNCTION_ADDRESS(GetExtendedIDfrom8bitBefore);
	SET_FUNCTION_ADDRESS(SetExtendedIDfrom8bitBefore);
}

int32_t IDaccess::GetExtendedIDfrom16bitBefore(const void* basicPtr)
{
	if (funcs.GetExtendedIDfrom16bitBefore)
		return funcs.GetExtendedIDfrom16bitBefore(basicPtr);
	else
	{
		uint16_t uID = *(uint16_t*)basicPtr;

		if (uID > MAX_FILE_ID_UINT16)	// is it negative ID?
			return *(int16_t*)basicPtr;
		else
			return uID;
	}
}

void IDaccess::SetExtendedIDfrom16bitBefore(void* basicPtr, int32_t ID)
{
	if (funcs.SetExtendedIDfrom16bitBefore)
		funcs.SetExtendedIDfrom16bitBefore(basicPtr, ID);
	else
		*(uint16_t*)basicPtr = ID;
}

// Returns extended ID for the pointer, where an ID of 8-bit size was available before.
int32_t IDaccess::GetExtendedIDfrom8bitBefore(const void* basicPtr)
{
	if (funcs.GetExtendedIDfrom8bitBefore)
		return funcs.GetExtendedIDfrom8bitBefore(basicPtr);
	else
	{
		uint8_t uID = *(uint8_t*)basicPtr;

		if (uID == 0xFF)	// is it unset ID?
			return -1;
		else
			return uID;
	}
}

// Returns extended ID for the pointer, where an ID of 8-bit size was available before.
void IDaccess::SetExtendedIDfrom8bitBefore(void* basicPtr, int32_t ID)
{
	if (funcs.SetExtendedIDfrom8bitBefore)
		funcs.SetExtendedIDfrom8bitBefore(basicPtr, ID);
	else
		*(uint8_t*)basicPtr = ID;
}