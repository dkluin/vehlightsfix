/*
* Copyright (C) 2014-2017  fastman92 <fastman92@gmail.com>, website: http://fastman92.com
* Licensed under the MIT License, see LICENSE at top level directory.
*
*/
#include "../../StdInc.h"
#include "FileInfoMemberAccess.h"

// pointers to functions
tFileInfoMemberAccessFuncs FileInfoMemberAccess::funcs;

// Initializes
void FileInfoMemberAccess::Init()
{
	tGenericLibraryModule* phModule = &CFastman92limitAdjuster::hModule;
	SET_FUNCTION_ADDRESS(GetFileInfoPrevFileID);
	SET_FUNCTION_ADDRESS(GetFileInfoNextFileID);
	SET_FUNCTION_ADDRESS(GetFileInfoNextOnCDfileID);
	SET_FUNCTION_ADDRESS(SetFileInfoPrevFileID);
	SET_FUNCTION_ADDRESS(SetFileInfoNextFileID);
	SET_FUNCTION_ADDRESS(SetFileInfoNextOnCDfileID);
}

// actual functions
// Returns model info, prev file ID
int32_t FileInfoMemberAccess::GetFileInfoPrevFileID(int32_t fileID)
{
	if (funcs.GetFileInfoPrevFileID)
		return funcs.GetFileInfoPrevFileID(fileID);
	else
	{
		return UNDEFINED_FILE_ID_INT32;

		/* FASTMAN92_CODE_STUB
		 you have to implement this code yourself.

		 Sample code:
		 */
	#if 0
		MAKE_VAR_GAME_VERSION();

		auto CStreaming__ms_aInfoForModel = g_LimitAdjuster.m_fileIDlimits.CStreaming__ms_aInfoForModel;

		int32_t result = -1;

		MAKE_DEAD_IF();
	#ifdef IS_PLATFORM_WIN_X86
		else if (gameVersion == GAME_VERSION_GTA_III_1_0_WIN_X86)
			result = CStreaming__ms_aInfoForModel.gta_iii[fileID].usPrev - CStreaming__ms_aInfoForModel.gta_iii;
		else if (gameVersion == GAME_VERSION_GTA_VC_1_0_WIN_X86)
			result = CStreaming__ms_aInfoForModel.gta_vc[fileID].usPrev - CStreaming__ms_aInfoForModel.gta_vc;
		else if (CGameVersion::Is_GTA_SA_1_0_PC(gameVersion))
			result = CStreaming__ms_aInfoForModel.gta_sa[fileID].usPrev;
		else if (gameVersion == GAME_VERSION_BULLY_SE_1_2_WIN_X86)
			result = CStreaming__ms_aInfoForModel.bully_se[fileID].usPrev;
		#endif

			return result == 0xFFFF ? -1 : result;
	#endif
	}
}

// Returns model info, next file ID
int32_t FileInfoMemberAccess::GetFileInfoNextFileID(int32_t fileID)
{
	if (funcs.GetFileInfoNextFileID)
		return funcs.GetFileInfoNextFileID(fileID);
	else
	{
		return UNDEFINED_FILE_ID_INT32;

		/* FASTMAN92_CODE_STUB
		you have to implement this code yourself.

		Sample code:
		*/
	#if 0
		MAKE_VAR_GAME_VERSION();

		auto CStreaming__ms_aInfoForModel = g_LimitAdjuster.m_fileIDlimits.CStreaming__ms_aInfoForModel;

		int32_t result = -1;

		MAKE_DEAD_IF();
	#ifdef IS_PLATFORM_WIN_X86
		else if (gameVersion == GAME_VERSION_GTA_III_1_0_WIN_X86)
			result = CStreaming__ms_aInfoForModel.gta_iii[fileID].usNext - CStreaming__ms_aInfoForModel.gta_iii;
		else if (gameVersion == GAME_VERSION_GTA_VC_1_0_WIN_X86)
			result = CStreaming__ms_aInfoForModel.gta_vc[fileID].usNext - CStreaming__ms_aInfoForModel.gta_vc;
		else if (CGameVersion::Is_GTA_SA_1_0_PC(gameVersion))
			result = CStreaming__ms_aInfoForModel.gta_sa[fileID].usNext;
		else if (gameVersion == GAME_VERSION_BULLY_SE_1_2_WIN_X86)
			result = CStreaming__ms_aInfoForModel.bully_se[fileID].usNext;
		#endif

			return result == 0xFFFF ? -1 : result;
		#endif
	}
}

// Returns model info, next on CD file ID
int32_t FileInfoMemberAccess::GetFileInfoNextOnCDfileID(int32_t fileID)
{
	if (funcs.GetFileInfoNextOnCDfileID)
		return funcs.GetFileInfoNextOnCDfileID(fileID);
	else
	{
		return UNDEFINED_FILE_ID_INT32;

		/* FASTMAN92_CODE_STUB
		you have to implement this code yourself.

		Sample code:
		*/
	#if 0
		MAKE_VAR_GAME_VERSION();

		auto CStreaming__ms_aInfoForModel = g_LimitAdjuster.m_fileIDlimits.CStreaming__ms_aInfoForModel;

		int32_t result = -1;

		MAKE_DEAD_IF();
	#ifdef IS_PLATFORM_WIN_X86
		else if (gameVersion == GAME_VERSION_GTA_III_1_0_WIN_X86)
			result = CStreaming__ms_aInfoForModel.gta_iii[fileID].usNextOnCd;
		else if (gameVersion == GAME_VERSION_GTA_VC_1_0_WIN_X86)
			result = CStreaming__ms_aInfoForModel.gta_vc[fileID].usNextOnCd;
		else if (CGameVersion::Is_GTA_SA_1_0_PC(gameVersion))
			result = CStreaming__ms_aInfoForModel.gta_sa[fileID].usNextOnCd;
		else if (gameVersion == GAME_VERSION_BULLY_SE_1_2_WIN_X86)
			result = CStreaming__ms_aInfoForModel.bully_se[fileID].usNextOnCd;
		#endif

			return result == 0xFFFF ? -1 : result;
		#endif
	}
}

// Sets file info, Prev file ID 
void FileInfoMemberAccess::SetFileInfoPrevFileID(int32_t fileID, int32_t newValue)
{
	if (funcs.SetFileInfoPrevFileID)
		funcs.SetFileInfoPrevFileID(fileID, newValue);
	else
	{
		/* FASTMAN92_CODE_STUB
		you have to implement this code yourself.

		Sample code:
		*/
	#if 0
		MAKE_VAR_GAME_VERSION();

		auto CStreaming__ms_aInfoForModel = g_LimitAdjuster.m_fileIDlimits.CStreaming__ms_aInfoForModel;

		MAKE_DEAD_IF();
	#ifdef IS_PLATFORM_WIN_X86
		else if (gameVersion == GAME_VERSION_GTA_III_1_0_WIN_X86)
			CStreaming__ms_aInfoForModel.gta_iii[fileID].usPrev = CStreaming__ms_aInfoForModel.gta_iii + newValue;
		else if (gameVersion == GAME_VERSION_GTA_VC_1_0_WIN_X86)
			CStreaming__ms_aInfoForModel.gta_vc[fileID].usPrev = CStreaming__ms_aInfoForModel.gta_vc + newValue;
		else if (CGameVersion::Is_GTA_SA_1_0_PC(gameVersion))
			CStreaming__ms_aInfoForModel.gta_sa[fileID].usPrev = newValue;
		else if (gameVersion == GAME_VERSION_BULLY_SE_1_2_WIN_X86)
			CStreaming__ms_aInfoForModel.bully_se[fileID].usPrev = newValue;
		#endif
	#endif
	}
}

// Sets file info, Next file ID
void FileInfoMemberAccess::SetFileInfoNextFileID(int32_t fileID, int32_t newValue)
{
	if (funcs.SetFileInfoNextFileID)
		funcs.SetFileInfoNextFileID(fileID, newValue);
	else
	{
		/* FASTMAN92_CODE_STUB
		you have to implement this code yourself.

		Sample code:
		*/
	#if 0
		MAKE_VAR_GAME_VERSION();

		auto CStreaming__ms_aInfoForModel = g_LimitAdjuster.m_fileIDlimits.CStreaming__ms_aInfoForModel;

		MAKE_DEAD_IF();
	#ifdef IS_PLATFORM_WIN_X86
		else if (gameVersion == GAME_VERSION_GTA_III_1_0_WIN_X86)
			CStreaming__ms_aInfoForModel.gta_iii[fileID].usNext = CStreaming__ms_aInfoForModel.gta_iii + newValue;
		else if (gameVersion == GAME_VERSION_GTA_VC_1_0_WIN_X86)
			CStreaming__ms_aInfoForModel.gta_vc[fileID].usNext = CStreaming__ms_aInfoForModel.gta_vc + newValue;
		else if (CGameVersion::Is_GTA_SA_1_0_PC(gameVersion))
			CStreaming__ms_aInfoForModel.gta_sa[fileID].usNext = newValue;
		else if (gameVersion == GAME_VERSION_BULLY_SE_1_2_WIN_X86)
			CStreaming__ms_aInfoForModel.bully_se[fileID].usNext = newValue;
		#endif
	#endif
	}
}

// Sets file info, NextOnCd file ID
void FileInfoMemberAccess::SetFileInfoNextOnCDfileID(int32_t fileID, int32_t newValue)
{
	if (funcs.SetFileInfoNextOnCDfileID)
		funcs.SetFileInfoNextOnCDfileID(fileID, newValue);
	else
	{
		/* FASTMAN92_CODE_STUB
		you have to implement this code yourself.

		Sample code:
		*/
	#if 0
		MAKE_VAR_GAME_VERSION();

		auto CStreaming__ms_aInfoForModel = g_LimitAdjuster.m_fileIDlimits.CStreaming__ms_aInfoForModel;

		MAKE_DEAD_IF();
	#ifdef IS_PLATFORM_WIN_X86
		else if (gameVersion == GAME_VERSION_GTA_III_1_0_WIN_X86)
			CStreaming__ms_aInfoForModel.gta_iii[fileID].usNextOnCd = newValue;
		else if (gameVersion == GAME_VERSION_GTA_VC_1_0_WIN_X86)
			CStreaming__ms_aInfoForModel.gta_vc[fileID].usNextOnCd = newValue;
		else if (CGameVersion::Is_GTA_SA_1_0_PC(gameVersion))
			CStreaming__ms_aInfoForModel.gta_sa[fileID].usNextOnCd = newValue;
		else if (gameVersion == GAME_VERSION_BULLY_SE_1_2_WIN_X86)
			CStreaming__ms_aInfoForModel.bully_se[fileID].usNextOnCd = newValue;
		#endif
		#endif
	}
}