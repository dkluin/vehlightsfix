#include "../StdInc.h"

#ifndef _HOOK_H_
#define _HOOK_H_

namespace Hook
{
	#define MAX_NOP_SIZE	9
	#define NOP_TABLE_SIZE	(MAX_NOP_SIZE * MAX_NOP_SIZE)

	typedef CONST BYTE OPCODE;

	namespace Opcodes
	{
		extern OPCODE NOP		[ ][MAX_NOP_SIZE] =		// No-operation.
		{
			{ 0x90 },
			{ 0x66, 0x90 },
			{ 0x0F, 0x1F },
			{ 0x0F, 0x1F, 0x40 },
			{ 0x0F, 0x1F, 0x44 },
			{ 0x66, 0x0F, 0x1F, 0x44 },
			{ 0x0F, 0x1F, 0x80 },
			{ 0x0F, 0x1F, 0x84 },
			{ 0x66, 0x0F, 0x1F, 0x84 }
		};
		extern OPCODE JO_OFF32	[6] = { 0x0F, 0x80 };	// Jump (near) if overflow.
		extern OPCODE JNO_OFF32	[6] = { 0x0F, 0x81 };	// Jump (near) if not overflow.
		extern OPCODE JB_OFF32	[6] = { 0x0F, 0x82 };	// Jump (near) if below.
		extern OPCODE JNAE_OFF32[6] = { 0x0F, 0x82 };	// Jump (near) if not above or equal.
		extern OPCODE JC_OFF32	[6] = { 0x0F, 0x82 };	// Jump (near) if carry.
		extern OPCODE JNB_OFF32	[6] = { 0x0F, 0x83 };	// Jump (near) if not below.
		extern OPCODE JAE_OFF32	[6] = { 0x0F, 0x83 };	// Jump (near) if above or equal.
		extern OPCODE JNC_OFF32	[6] = { 0x0F, 0x83 };	// Jump (near) if not carry.
		extern OPCODE JE_OFF32	[6] = { 0x0F, 0x84 };	// Jump (near) if equal.
		extern OPCODE JZ_OFF32	[6] = { 0x0F, 0x84 };	// Jump (near) if zero.
		extern OPCODE JNE_OFF32	[6] = { 0x0F, 0x85 };	// Jump (near) if not equal.
		extern OPCODE JNZ_OFF32	[6] = { 0x0F, 0x85 };	// Jump (near) if not zero.
		extern OPCODE JBE_OFF32	[6] = { 0x0F, 0x86 };	// Jump (near) if below or equal.
		extern OPCODE JNA_OFF32	[6] = { 0x0F, 0x86 };	// Jump (near) if not above.
		extern OPCODE JA_OFF32	[6] = { 0x0F, 0x87 };	// Jump (near) if above.
		extern OPCODE JNBE_OFF32[6] = { 0x0F, 0x87 };	// Jump (near) if not below or equal.
		extern OPCODE JS_OFF32	[6] = { 0x0F, 0x88 };	// Jump (near) if sign.
		extern OPCODE JNS_OFF32	[6] = { 0x0F, 0x89 };	// Jump (near) if not sign.
		extern OPCODE JP_OFF32	[6] = { 0x0F, 0x8A };	// Jump (near) if parity.
		extern OPCODE JPE_OFF32	[6] = { 0x0F, 0x8A };	// Jump (near) if parity even.
		extern OPCODE JNP_OFF32	[6] = { 0x0F, 0x8B };	// Jump (near) if not parity.
		extern OPCODE JPO_OFF32	[6] = { 0x0F, 0x8B };	// Jump (near) if parity odd.
		extern OPCODE JL_OFF32	[6] = { 0x0F, 0x8C };	// Jump (near) if less.
		extern OPCODE JNGE_OFF32[6] = { 0x0F, 0x8C };	// Jump (near) if not greater or equal.
		extern OPCODE JGE_OFF32	[6] = { 0x0F, 0x8D };	// Jump (near) if greater or equal.
		extern OPCODE JNL_OFF32	[6] = { 0x0F, 0x8D };	// Jump (near) if not less.
		extern OPCODE JLE_OFF32	[6] = { 0x0F, 0x8E };	// Jump (near) if less or equal.
		extern OPCODE JNG_OFF32	[6] = { 0x0F, 0x8E };	// Jump (near) if not greater.
		extern OPCODE JG_OFF32	[6] = { 0x0F, 0x8F };	// Jump (near) if greater.
		extern OPCODE JNLE_OFF32[6] = { 0x0F, 0x8F };	// Jump (near) if not less or equal.
		extern OPCODE JO_OFF8	[2] = { 0x70 };			// Jump (short) if overflow.
		extern OPCODE JNO_OFF8	[2] = { 0x71 };			// Jump (short) if not overflow.
		extern OPCODE JB_OFF8	[2] = { 0x72 };			// Jump (short) if below.
		extern OPCODE JNAE_OFF8	[2] = { 0x72 };			// Jump (short) if not above or equal.
		extern OPCODE JC_OFF8	[2] = { 0x72 };			// Jump (short) if carry.
		extern OPCODE JNB_OFF8	[2] = { 0x73 };			// Jump (short) if not below.
		extern OPCODE JAE_OFF8	[2] = { 0x73 };			// Jump (short) if above or equal.
		extern OPCODE JNC_OFF8	[2] = { 0x73 };			// Jump (short) if not carry.
		extern OPCODE JE_OFF8	[2] = { 0x74 };			// Jump (short) if equal.
		extern OPCODE JZ_OFF8	[2] = { 0x74 };			// Jump (short) if zero.
		extern OPCODE JNE_OFF8	[2] = { 0x75 };			// Jump (short) if not equal.
		extern OPCODE JNZ_OFF8	[2] = { 0x75 };			// Jump (short) if not zero.
		extern OPCODE JBE_OFF8	[2] = { 0x76 };			// Jump (short) if below or equal.
		extern OPCODE JNA_OFF8	[2] = { 0x76 };			// Jump (short) if not above.
		extern OPCODE JA_OFF8	[2] = { 0x77 };			// Jump (short) if above.
		extern OPCODE JNBE_OFF8	[2] = { 0x77 };			// Jump (short) if not below or equal.
		extern OPCODE JS_OFF8	[2] = { 0x78 };			// Jump (short) if sign.
		extern OPCODE JNS_OFF8	[2] = { 0x79 };			// Jump (short) if not sign.
		extern OPCODE JP_OFF8	[2] = { 0x7A };			// Jump (short) if parity.
		extern OPCODE JPE_OFF8	[2] = { 0x7A };			// Jump (short) if parity even.
		extern OPCODE JNP_OFF8	[2] = { 0x7B };			// Jump (short) if not parity.
		extern OPCODE JPO_OFF8	[2] = { 0x7B };			// Jump (short) if parity odd.
		extern OPCODE JL_OFF8	[2] = { 0x7C };			// Jump (short) if less.
		extern OPCODE JNGE_OFF8	[2] = { 0x7C };			// Jump (short) if not greater or equal.
		extern OPCODE JGE_OFF8	[2] = { 0x7D };			// Jump (short) if greater or equal.
		extern OPCODE JNL_OFF8	[2] = { 0x7D };			// Jump (short) if not less.
		extern OPCODE JLE_OFF8	[2] = { 0x7E };			// Jump (short) if less or equal.
		extern OPCODE JNG_OFF8	[2] = { 0x7E };			// Jump (short) if not greater.
		extern OPCODE JG_OFF8	[2] = { 0x7F };			// Jump (short) if greater.
		extern OPCODE JNLE_OFF8	[2] = { 0x7F };			// Jump (short) if not less or equal.
		extern OPCODE JCXZ_OFF8	[2] = { 0xE3 };			// Jump (short) if CX register is 0.
		extern OPCODE JECXZ_OFF8[2] = { 0xE3 };			// Jump (short) if ECX register is 0.
		extern OPCODE CALL_OFF32[5] = { 0xE8 };			// Call (near) subroutine.
		extern OPCODE JMP_OFF32	[5] = { 0xE9 };			// Jump (near) unconditionally.
		extern OPCODE JMP_OFF8	[2] = { 0xEB };			// Jump (short) unconditionally.
		extern OPCODE JMP_PTR32	[6] = { 0xFF, 0x25 };	// Jump indirectly.
	};

	typedef VOID (WINAPI *MAKE_FUNC_T)(LPVOID lpAddress);
	typedef VOID (WINAPI *MAKE_FUNCEX_T)(LPVOID lpAddress, LPVOID lpDestination);

	inline DWORD WINAPI UnprotectMemory(LPVOID lpAddress, SIZE_T dwSize)
	{
		DWORD flOldProtect;
		VirtualProtect(lpAddress, dwSize, PAGE_EXECUTE_READWRITE, &flOldProtect);
		return flOldProtect;
	}

	inline VOID WINAPI ProtectMemory(LPVOID lpAddress, SIZE_T dwSize, DWORD flOldProtect)
	{
		VirtualProtect(lpAddress, dwSize, flOldProtect, NULL);
	}

	template<typename OFFSET_T> inline OFFSET_T WINAPI GetOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		return (OFFSET_T)((DWORD)lpDestination - ((DWORD)lpAddress + sizeof(OFFSET_T)));
	}

	inline CHAR WINAPI GetShortOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		return GetOffset<CHAR>(lpAddress, lpDestination);
	}

	inline LONG WINAPI GetNearOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		return GetOffset<LONG>(lpAddress, lpDestination);
	}

	inline VOID WINAPI MakeValue(LPVOID lpAddress, CONST BYTE aValue[], SIZE_T dwSize)
	{
		CopyMemory(lpAddress, aValue, dwSize);
	}

	template<typename VALUE_T> inline VOID WINAPI MakeValue(LPVOID lpAddress, VALUE_T tValue)
	{
		*(VALUE_T *)lpAddress = tValue;
	}

	inline VOID WINAPI MakeInstruction(LPVOID lpAddress, OPCODE aInstruction[], SIZE_T dwSize)
	{
		MakeValue(lpAddress, aInstruction, dwSize);
	}

	template<OPCODE aInstruction[], SIZE_T dwSize> inline VOID WINAPI MakeInstruction(LPVOID lpAddress)
	{
		MakeInstruction(lpAddress, aInstruction, dwSize);
	}

	inline VOID WINAPI MakePointer(LPVOID lpAddress, LPVOID lpPointer)
	{
		MakeValue<LPVOID>(lpAddress, lpPointer);
	}

	template<typename OFFSET_T> inline VOID WINAPI MakeOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeValue<OFFSET_T>(lpAddress, GetOffset<OFFSET_T>(lpAddress, lpDestination));
	}

	inline VOID WINAPI MakeShortOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeOffset<CHAR>(lpAddress, lpDestination);
	}

	inline VOID WINAPI MakeNearOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeOffset<LONG>(lpAddress, lpDestination);
	}

	inline VOID WINAPI MakeNOP(LPVOID lpAddress, SIZE_T dwSize)
	{
		while(dwSize > MAX_NOP_SIZE)
		{
			MakeInstruction(lpAddress, Opcodes::NOP[MAX_NOP_SIZE - 1], MAX_NOP_SIZE);
			dwSize -= MAX_NOP_SIZE;
		}

		MakeInstruction(lpAddress, Opcodes::NOP[dwSize - 1], dwSize);
	}

	template<OPCODE aInstruction[], SIZE_T dwSize, typename OFFSET_T> inline VOID WINAPI MakeBranch(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeInstruction<aInstruction, dwSize>(lpAddress);
		MakeOffset<OFFSET_T>((PBYTE)lpAddress + dwSize, lpDestination);
	}

	template<OPCODE aInstruction[]> inline VOID WINAPI MakeShortUnconditionalBranch(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeBranch<aInstruction, 1, CHAR>(lpAddress, lpDestination);
	}

	template<OPCODE aInstruction[]> inline VOID WINAPI MakeNearUnconditionalBranch(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeBranch<aInstruction, 1, LONG>(lpAddress, lpDestination);
	}

	template<OPCODE aInstruction[]> inline VOID WINAPI MakeIndirectBranch(LPVOID lpAddress, LPVOID lpVariable)
	{
		MakeBranch<aInstruction, 2, LPVOID>(lpAddress, lpVariable);
	}

	inline VOID WINAPI MakeNearCall(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeNearUnconditionalBranch<Opcodes::CALL_OFF32>(lpAddress, lpDestination);
	}

	inline VOID WINAPI MakeShortJump(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeShortUnconditionalBranch<Opcodes::JMP_OFF8>(lpAddress, lpDestination);
	}

	inline VOID WINAPI MakeNearJump(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeNearUnconditionalBranch<Opcodes::JMP_OFF32>(lpAddress, lpDestination);
	}

	inline VOID WINAPI MakeIndirectJump(LPVOID lpAddress, LPVOID lpVariable)
	{
		MakeIndirectBranch<Opcodes::JMP_PTR32>(lpAddress, lpVariable);
	}

	template<MAKE_FUNC_T tCallback, SIZE_T dwSize> VOID WINAPI InstallHook(LPVOID lpAddress)
	{
		DWORD flOldProtect = UnprotectMemory(lpAddress, dwSize);
		tCallback(lpAddress);
		ProtectMemory(lpAddress, dwSize, flOldProtect);
	}

	template<MAKE_FUNCEX_T tCallback, SIZE_T dwSize> VOID WINAPI InstallHook(LPVOID lpAddress, LPVOID lpDestination)
	{
		DWORD flOldProtect = UnprotectMemory(lpAddress, dwSize);
		tCallback(lpAddress, lpDestination);
		ProtectMemory(lpAddress, dwSize, flOldProtect);
	}

	VOID WINAPI InstallHookPointer(LPVOID lpAddress, LPVOID lpPointer)
	{
		InstallHook<MakePointer, 4>(lpAddress, lpPointer);
	}

	VOID WINAPI InstallHookShortOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHook<MakeShortOffset, 1>(lpAddress, lpDestination);
	}

	VOID WINAPI InstallHookNearOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHook<MakeNearOffset, 4>(lpAddress, lpDestination);
	}

	template<MAKE_FUNCEX_T tCallback> inline VOID WINAPI InstallHookShortUnconditionalBranch(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHook<tCallback, 2>(lpAddress, lpDestination);
	}

	template<MAKE_FUNCEX_T tCallback> inline VOID WINAPI InstallHookNearUnconditionalBranch(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHook<tCallback, 5>(lpAddress, lpDestination);
	}

	template<MAKE_FUNCEX_T tCallback> inline VOID WINAPI InstallHookIndirectBranch(LPVOID lpAddress, LPVOID lpVariable)
	{
		InstallHook<tCallback, 6>(lpAddress, lpVariable);
	}

	VOID WINAPI InstallHookNearCall(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHookNearUnconditionalBranch<MakeNearCall>(lpAddress, lpDestination);
	}

	VOID WINAPI InstallHookShortJump(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHookShortUnconditionalBranch<MakeShortJump>(lpAddress, lpDestination);
	}

	VOID WINAPI InstallHookNearJump(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHookNearUnconditionalBranch<MakeNearJump>(lpAddress, lpDestination);
	}

	VOID WINAPI InstallHookIndirectJump(LPVOID lpAddress, LPVOID lpVariable)
	{
		InstallHookIndirectBranch<MakeIndirectJump>(lpAddress, lpVariable);
	}

	VOID WINAPI WriteProtectedMemory(LPVOID lpAddress, CONST BYTE aValue[], SIZE_T dwSize)
	{
		DWORD flOldProtect = UnprotectMemory(lpAddress, dwSize);
		MakeValue(lpAddress, aValue, dwSize);
		ProtectMemory(lpAddress, dwSize, flOldProtect);
	}

	template<typename VALUE_T> VOID WINAPI WriteProtectedMemory(LPVOID lpAddress, VALUE_T tValue)
	{
		CONST SIZE_T dwSize = sizeof(VALUE_T);
		DWORD flOldProtect = UnprotectMemory(lpAddress, dwSize);
		MakeValue<VALUE_T>(lpAddress, tValue);
		ProtectMemory(lpAddress, dwSize, flOldProtect);
	}

	VOID WINAPI NopProtectedMemory(LPVOID lpAddress, SIZE_T dwSize)
	{
		DWORD flOldProtect = UnprotectMemory(lpAddress, dwSize);
		MakeNOP(lpAddress, dwSize);
		ProtectMemory(lpAddress, dwSize, flOldProtect);
	}

	VOID WINAPI SkipProtectedMemory(LPVOID lpAddress, LPVOID lpDestination)
	{
		SSIZE_T lSize = (DWORD)lpDestination - (DWORD)lpAddress;

		if(lSize > 0)
		{
			if(lSize < 10)
				return NopProtectedMemory(lpAddress, lSize);
			if(lSize < 128)
				return InstallHookShortJump(lpAddress, lpDestination);
		}
		else if(lSize >= -128)
			return InstallHookShortJump(lpAddress, lpDestination);

		InstallHookNearJump(lpAddress, lpDestination);
	}
};

#endif //_HOOK_H_
