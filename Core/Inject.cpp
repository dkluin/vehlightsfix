#include "../StdInc.h"
#include "Inject.h"
#include "../Imports/UG/Underground.hpp"

void __declspec(naked) HOOK_4C8308_CVehicleModelInfo__SetEditableMaterialsCB_Material(void)
{
#define _4C8311_CVehicleModelInfo__SetEditableMaterialsCB_Material	0x004C8311
	__asm
	{
		mov		esi, [edx]
		mov		[edi], esi
		lea		ebx, [edx]RwSurfaceProperties.specular
		mov		[edi+4], ebx
		mov		esi, [ebx]
		mov		[edi+8], esi
		lea		ebx, [edx]RwSurfaceProperties.diffuse
		mov		[edi+0Ch], ebx
		mov		esi, [ebx]
		mov		[edi+10h], esi
		add		edi, 14h
		mov		[ecx], edi
		mov		ebx, _4C8311_CVehicleModelInfo__SetEditableMaterialsCB_Material
		jmp		ebx
	}
#undef _4C8311_CVehicleModelInfo__SetEditableMaterialsCB_Material
}

#ifdef LOGGING_SYSTEM_ACTIVE
void __declspec(naked)HOOK_6D662B_CVehicle__SetupRender(void)
{
#define _6D6630_CVehicle__SetupRender	0x006D6630
	__asm
	{
		mov		eax, _CVehicleModelInfo__SetEditableMaterials
		call	eax
		movzx	ecx, ds:[_CWorld__ucPlayerInFocus]
		imul	ecx, SIZE CPlayerInfo
		mov		edx, _CWorld__aPlayers[ecx]
		test	edx, edx
		jz		not_player_vehicle
		mov		eax, [edx]CPed.m_pVehicle
		cmp		eax, esi
		jne		not_player_vehicle
		call	PrintEditableMaterialsInfo
not_player_vehicle:
		mov		ecx, _6D6630_CVehicle__SetupRender
		jmp		ecx
	}
#undef _6D6630_CVehicle__SetupRender
}
#endif //LOGGING_SYSTEM_ACTIVE

static CVehicle* HOOK_6E153D_CVehicle__DoHeadLightReflectionSingle_Vehicle;

void __declspec(naked) HOOK_6E153D_CVehicle__DoHeadLightReflectionSingle(void)
{
#define _6E154C_CVehicle__DoHeadLightReflectionSingle	0x006E154C
#define _6E1544_CVehicle__DoHeadLightReflectionSingle	0x006E1544

	_asm mov HOOK_6E153D_CVehicle__DoHeadLightReflectionSingle_Vehicle, ecx;
	_asm pushad;

	if (HOOK_6E153D_CVehicle__DoHeadLightReflectionSingle_Vehicle->m_physical.m_entity.m_eModel == MODEL_QUAD
		|| HOOK_6E153D_CVehicle__DoHeadLightReflectionSingle_Vehicle->m_physical.m_entity.m_eModel == MODEL_VCS_QUAD
		|| HOOK_6E153D_CVehicle__DoHeadLightReflectionSingle_Vehicle->m_physical.m_entity.m_eModel == MODEL_KART
		|| HOOK_6E153D_CVehicle__DoHeadLightReflectionSingle_Vehicle->m_physical.m_entity.m_eModel == MODEL_BW_KART)
	{
		_asm popad;
		_asm mov edx, _6E1544_CVehicle__DoHeadLightReflectionSingle;
		_asm jmp edx;
	}

	_asm popad;
	_asm mov edx, _6E154C_CVehicle__DoHeadLightReflectionSingle;
	_asm jmp edx;
#undef _6E1544_CVehicle__DoHeadLightReflectionSingle
#undef _6E1542_CVehicle__DoHeadLightReflectionSingle
}

void __declspec(naked) HOOK_6E18D6_CVehicle__DoTailLightEffect(void)
{
#define _6E18E0_CVehicle__DoTailLightEffect	0x006E18E0
#define _6E1A48_CVehicle__DoTailLightEffect	0x006E1A48
	__asm
	{
		mov		eax, [esi]CVehicle.m_pTrailer
		test	eax, eax
		jnz		not_braking
		fldz
		fcomp	[esi]CVehicle.m_fBrakePedal
		fnstsw	ax
		test	ah, 5
		jp		not_braking
		test	[esi]CVehicle.m_aVehicleFlags, VEHICLE_FLAGS0_IS_BRAKING
		jne		not_braking
		mov		ecx, [esi]CVehicle.m_pCab
		test	ecx, ecx
		jnz		has_cab_linked
		mov		ecx, esi
has_cab_linked:
		mov		edx, [ecx]CVehicle.m_pDriver
		test	edx, edx
		jz		not_braking
		mov		byte ptr [esp+34h+18h], 0
		jmp		light_active
not_braking:
		mov		cl, [esp+34h+18h]
		test	cl, cl
		jz		light_inactive
light_active:
		fldz
		fld		[esp+34h+4]
		fcompp
		mov		eax, _6E18E0_CVehicle__DoTailLightEffect
		jmp		eax
light_inactive:
		mov		eax, _6E1A48_CVehicle__DoTailLightEffect
		jmp		eax
	}
#undef _6E1A48_CVehicle__DoTailLightEffect
#undef _6E18E0_CVehicle__DoTailLightEffect
}

void __declspec(naked) HOOK_6E198E_CVehicle__DoTailLightEffect(void)
{
#define _6E19B4_CVehicle__DoTailLightEffect	0x006E19B4
#define _6E19D0_CVehicle__DoTailLightEffect	0x006E19D0
	__asm
	{
		mov		al, [esp+34h+18h]
		test	al, al
		jnz		not_breaking
		mov		ecx, _6E19B4_CVehicle__DoTailLightEffect
		jmp		ecx
not_breaking:
		mov		ecx, _6E19D0_CVehicle__DoTailLightEffect
		jmp		ecx
	}
#undef _6E19D0_CVehicle__DoTailLightEffect
#undef _6E19B4_CVehicle__DoTailLightEffect
}

void __declspec(naked) HOOK_6E2870_CVehicle__DoVehicleLights(void)
{
#define _6E287A_CVehicle__DoVehicleLights	0x006E287A
#define _6E28EF_CVehicle__DoVehicleLights	0x006E28EF
	__asm
	{
		mov		eax, [esi]CVehicle.m_pTrailer
		test	eax, eax
		jnz		no_brake_light
		mov		ecx, [esi]CVehicle.m_pCab
		test	ecx, ecx
		jnz		has_cab_linked
		mov		ecx, esi
has_cab_linked:
		mov		edx, [ecx]CVehicle.m_pDriver
		test	edx, edx
		jz		no_brake_light
		mov		eax, _6E287A_CVehicle__DoVehicleLights
		jmp		eax
no_brake_light:
		mov		ecx, _6E28EF_CVehicle__DoVehicleLights
		jmp		ecx
	}
#undef _6E28EF_CVehicle__DoVehicleLights
#undef _6E287A_CVehicle__DoVehicleLights
}

static CTrain* HOOK_6F5582_CTrain__PreRender_Train;

void __declspec(naked) HOOK_6F5582_CTrain__PreRender(void)
{
#define _6F558A_CTrain__PreRender	0x006F558A
#define _6F5599_CTrain__PreRender	0x006F5599

	_asm mov HOOK_6F5582_CTrain__PreRender_Train, esi;
	_asm pushad;

	if (HOOK_6F5582_CTrain__PreRender_Train->m_vehicle.m_physical.m_entity.m_eModel == MODEL_TRAM)
	{
		_asm popad;
		_asm mov edx, _6F558A_CTrain__PreRender;
		_asm jmp edx;
	}
	else if (HOOK_6F5582_CTrain__PreRender_Train->m_vehicle.m_physical.m_entity.m_eModel == MODEL_STREAK
		|| HOOK_6F5582_CTrain__PreRender_Train->m_vehicle.m_physical.m_entity.m_eModel == MODEL_LC_TRAINF
		|| HOOK_6F5582_CTrain__PreRender_Train->m_vehicle.m_physical.m_entity.m_eModel == MODEL_CC_TRAINF
		|| HOOK_6F5582_CTrain__PreRender_Train->m_aTrainFlags[0] & TRAIN_FLAGS0_IS_TAIL_CARRIAGE)
	{
		_asm popad;
		_asm mov edx, _6F5599_CTrain__PreRender;
		_asm jmp edx;
	}

	_asm popad;
	_asm mov edx, _6F558A_CTrain__PreRender;
	_asm jmp edx;

#undef _6F5599_CTrain__PreRender
#undef _6F558A_CTrain__PreRender
}

void __declspec(naked) HOOK_6F8E06_CTrain__ProcessControl(void)
{
#define _6F8E0C_CTrain__ProcessControl	0x006F8E0C
	__asm
	{
		mov		[edi]CTrain.m_aTrainFlags+1, al
		or		[edi]CTrain.m_aTrainFlags, TRAIN_FLAGS0_IS_HEAD_CARRIAGE | TRAIN_FLAGS0_IS_TAIL_CARRIAGE
		mov		eax, _6F8E0C_CTrain__ProcessControl
		jmp		eax
	}
#undef _6F8E0C_CTrain__ProcessControl
}

VOID WINAPI InstallAllHooks(void)
{
	CFastman92limitAdjuster::Init();

	// UG does not need this patch either. CVehicleModelInfo::SetEditableMaterialsCB is completely reversed in UG because of RGB/pearlescent colours which can be set in UG-MP.
	if(!GetModuleHandleA("SilentPatchSA.asi") || !GetModuleHandleA("Underground_Core.asi"))
		Hook::InstallHookNearJump((LPVOID)0x004C8308, HOOK_4C8308_CVehicleModelInfo__SetEditableMaterialsCB_Material);

	Hook::WriteProtectedMemory<short>((LPVOID)0x006A2EA1, MODEL_INTERNAL);
	Hook::SkipProtectedMemory((LPVOID)0x006A2EA5, (LPVOID)0x006A2EB1);
	Hook::InstallHookNearOffset((LPVOID)0x006A2EBE, CVehicleVtbl::GetLightFlags);
	Hook::WriteProtectedMemory<unsigned char>((LPVOID)0x006A2EC4, LIGHT_FLAGS_HAS_NO_HEADLIGHT | LIGHT_FLAGS_HAS_NO_TAILLIGHT);

	Hook::WriteProtectedMemory<short>((LPVOID)0x006ABC77, MODEL_INTERNAL);
	Hook::SkipProtectedMemory((LPVOID)0x006ABC7B, (LPVOID)0x006ABC87);
	Hook::InstallHookNearOffset((LPVOID)0x006ABC94, CVehicleVtbl::GetLightFlags);
	Hook::WriteProtectedMemory<unsigned char>((LPVOID)0x006ABC9A, LIGHT_FLAGS_HAS_NO_HEADLIGHT | LIGHT_FLAGS_HAS_NO_TAILLIGHT);
	Hook::WriteProtectedMemory((LPVOID)0x006ABC9D, Hook::Opcodes::PUSH_EAX, 1);
	Hook::SkipProtectedMemory((LPVOID)0x006ABC9E, (LPVOID)0x006ABCB3);

#ifdef LOGGING_SYSTEM_ACTIVE
	Hook::InstallHookNearJump((LPVOID)0x006D662B, HOOK_6D662B_CVehicle__SetupRender);
#endif //LOGGING_SYSTEM_ACTIVE

	Hook::InstallHookNearJump((LPVOID)0x006E153D, HOOK_6E153D_CVehicle__DoHeadLightReflectionSingle);

	Hook::InstallHookNearJump((LPVOID)0x006E18D6, HOOK_6E18D6_CVehicle__DoTailLightEffect);
	Hook::InstallHookNearOffset((LPVOID)0x006E18E7, (LPVOID)0x006E1A3D);
	Hook::InstallHookNearOffset((LPVOID)0x006E1912, (LPVOID)0x006E1A3D);
	Hook::NopProtectedMemory((LPVOID)0x006E1986, 2);
	Hook::InstallHookNearJump((LPVOID)0x006E198E, HOOK_6E198E_CVehicle__DoTailLightEffect);

	Hook::WriteProtectedMemory<char>((LPVOID)0x006E1D7C, LEFT_TAILLIGHT);
	Hook::InstallHookNearJump((LPVOID)0x006E2870, HOOK_6E2870_CVehicle__DoVehicleLights);

	Hook::InstallHookNearJump((LPVOID)0x006F5582, HOOK_6F5582_CTrain__PreRender);

	Hook::InstallHookNearJump((LPVOID)0x006F8E06, HOOK_6F8E06_CTrain__ProcessControl);
}
