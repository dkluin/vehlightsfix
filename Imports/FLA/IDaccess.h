#pragma once
#include "Main.h"
#include "ValueExtension.h"

#include <stdint.h>

// Function pointers
struct tIDaccessFuncs
{
public:
	// Tells if DFF/TXD 32-bit IDs are enabled.
	bool (F92_LA_CONVENTION* AreDifficultIDsExtended)();

	int32_t (F92_LA_CONVENTION* GetExtendedIDfrom16bitBefore)(const void* basicPtr);
	void (F92_LA_CONVENTION* SetExtendedIDfrom16bitBefore)(void* basicPtr, int32_t ID);

	/////////////////////////////
	int32_t (F92_LA_CONVENTION* GetExtendedIDfrom8bitBefore)(const void* basicPtr);
	void (F92_LA_CONVENTION* SetExtendedIDfrom8bitBefore)(void* basicPtr, int32_t ID);
};


class IDaccess
{
public:
	// pointers of functions
	static tIDaccessFuncs funcs;

	// actual functions
	// Tells if DFF/TXD 32-bit IDs are enabled.
	static bool AreDifficultIDsExtended();

	// Returns extended ID for the pointer, where an ID of 16-bit size was available before.
	static int32_t GetExtendedIDfrom16bitBefore(const void* basicPtr);

	// Sets extended ID for the pointer, where an ID of 16-bit size was available before.
	static void SetExtendedIDfrom16bitBefore(void* basicPtr, int32_t ID);

	// Compares only a significiant part, uses for patches such as "cmp ax, 520" or so.
	// Where only 16-bit would be used before, but now it may be 32-bit
	static int32_t CompareIDonlySignificiantPart(int32_t a, uint16_t b);

	////////////////////////////////////

	// Returns extended ID for the pointer, where an ID of 8-bit size was available before.
	static int32_t GetExtendedIDfrom8bitBefore(const void* basicPtr);

	// Returns extended ID for the pointer, where an ID of 8-bit size was available before.
	static void SetExtendedIDfrom8bitBefore(void* basicPtr, int32_t ID);

	// Initializes
	static void Init();
};

// Declare CFileID
typedef CValueExtensionNum<uint16_t, int32_t, IDaccess::GetExtendedIDfrom16bitBefore, IDaccess::SetExtendedIDfrom16bitBefore> CFileID;
typedef CValueExtensionNum<uint8_t, int32_t, IDaccess::GetExtendedIDfrom8bitBefore, IDaccess::SetExtendedIDfrom8bitBefore> uint8_replacement;