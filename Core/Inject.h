#include "../StdInc.h"

#ifndef _INJECT_H_
#define _INJECT_H_

#include "Hook.h"
namespace Hook
{
	namespace Opcodes
	{
		CONST BYTE PUSH_EAX	[1] = { 0x50 };	// Push EAX register onto the stack.
	};
};

void HOOK_4C8308_CVehicleModelInfo__SetEditableMaterialsCB_Material(void);
#ifdef LOGGING_SYSTEM_ACTIVE
void __declspec(naked)HOOK_6D662B_CVehicle__SetupRender(void);
#endif //LOGGING_SYSTEM_ACTIVE
void HOOK_6E153D_CVehicle__DoHeadLightReflectionSingle(void);
void HOOK_6E18D6_CVehicle__DoTailLightEffect(void);
void HOOK_6E198E_CVehicle__DoTailLightEffect(void);
void HOOK_6E2870_CVehicle__DoVehicleLights(void);
void HOOK_6F5582_CTrain__PreRender(void);
void HOOK_6F8E06_CTrain__ProcessControl(void);

VOID WINAPI InstallAllHooks(void);

#endif //_INJECT_H_
