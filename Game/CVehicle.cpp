#include "../StdInc.h"
#include "CVehicle.h"

namespace CVehicleVtbl
{
#define _CVehicle__Render						0x006D0E60
	auto Render = (void(__thiscall *const)(CVehicle *self))_CVehicle__Render;
#define _CVehicle__GetVehicleAppearance			0x006D1080
	auto GetVehicleAppearance = (eVehicleAppearance(__thiscall *const)(CVehicle *self))_CVehicle__GetVehicleAppearance;
#define _CVehicle__SetupRender					0x006D64F0
	auto SetupRender = (void(__thiscall *const)(CVehicle *self))_CVehicle__SetupRender;
#define _CVehicle__ResetAfterRender				0x006D64F0
	auto ResetAfterRender = (void(__thiscall *const)(CVehicle *self))_CVehicle__ResetAfterRender;
#define _CVehicle__DoHeadLightBeam				0x006E0E20
	auto DoHeadLightBeam = (void(__thiscall *const)(CVehicle *self, int iLightSide, CMatrix &matrix, unsigned char ucPutOnRight))_CVehicle__DoHeadLightBeam;
#define _CVehicle__DoHeadLightReflectionSingle	0x006E1440
	auto DoHeadLightReflectionSingle = (void(__thiscall *const)(CVehicle *self, CMatrix &matrix, unsigned char ucPutOnRight))_CVehicle__DoHeadLightReflectionSingle;
#define _CVehicle__DoTailLightEffect			0x006E1780
	auto DoTailLightEffect = (bool(__thiscall *const)(CVehicle *self, int iLightSide, CMatrix &matrix, unsigned char ucPutOnRight, unsigned char ucIsActive, unsigned int uiLightFlags, unsigned char ucIsntStopLightAnyMeans))_CVehicle__DoTailLightEffect;
#define _CVehicle__DoVehicleLights				0x006E1A60
	auto DoVehicleLights = (void(__thiscall *const)(CVehicle *self, CMatrix &matrix, unsigned int uiLightFlags))_CVehicle__DoVehicleLights;
};

void CVehicle::Render(void)
{
	CVehicleVtbl::Render(this);
}

eVehicleAppearance CVehicle::GetVehicleAppearance(void)
{
	return CVehicleVtbl::GetVehicleAppearance(this);
}

void CVehicle::SetupRender(void)
{
	CVehicleVtbl::SetupRender(this);
}

void CVehicle::ResetAfterRender(void)
{
	CVehicleVtbl::ResetAfterRender(this);
}

void CVehicle::DoHeadLightBeam(int iLightSide, CMatrix &matrix, unsigned char ucPutOnRight)
{
	CVehicleVtbl::DoHeadLightBeam(this, iLightSide, matrix, ucPutOnRight);
}

void CVehicle::DoHeadLightReflectionSingle(CMatrix &matrix, unsigned char ucPutOnRight)
{
	CVehicleVtbl::DoHeadLightReflectionSingle(this, matrix, ucPutOnRight);
}

bool CVehicle::DoTailLightEffect(int iLightSide, CMatrix &matrix, unsigned char ucPutOnRight, unsigned char ucIsActive, unsigned int uiLightFlags, unsigned char ucIsntStopLightAnyMeans)
{
	return CVehicleVtbl::DoTailLightEffect(this, iLightSide, matrix, ucPutOnRight, ucIsActive, uiLightFlags, ucIsntStopLightAnyMeans);
}

void CVehicle::DoVehicleLights(CMatrix &matrix, unsigned int uiLightFlags)
{
	CVehicleVtbl::DoVehicleLights(this, matrix, uiLightFlags);
}

unsigned int CVehicle::GetLightFlags(void)
{
	return CVehicleVtbl::GetLightFlags(this, 0);
}

unsigned int __fastcall CVehicleVtbl::GetLightFlags(CVehicle *self, int edx)
{
	eVehicleAppearance eAppearance = self->GetVehicleAppearance();

	if (eAppearance == VEHAPPEARANCE_AUTOMOBILE)
	{
		switch (self->m_physical.m_entity.m_eModel)
		{
		case MODEL_ARTICT1:			case MODEL_ARTICT2:
		case MODEL_PETROTR:			case MODEL_ARTICT3:
		case MODEL_ARTICT4:			case MODEL_ARTICT5:
			return LIGHT_FLAGS_HAS_LEFT_LIGHTS
				| LIGHT_FLAGS_UNUSED2
				| LIGHT_FLAGS_HAS_NO_HEADLIGHT;
		case MODEL_RCBANDIT:		case MODEL_RCTIGER:
		case MODEL_RCCAM:			case MODEL_BAGBOXA:
		case MODEL_BAGBOXB:			case MODEL_TUGSTAIR:
		case MODEL_FARMTR1:			case MODEL_UTILTR1:
		case MODEL_LCS_RCBANDIT:	case MODEL_LC_RCBANDIT:
		case MODEL_VC_RCBANDIT:
			break;
		case MODEL_QUAD:		case MODEL_KART:
		case MODEL_VCS_QUAD:	case MODEL_BW_KART:
			return LIGHT_FLAGS_HAS_UNBREAKABLE_LIGHTS;
		case MODEL_COMBINE:
			return LIGHT_FLAGS_HAS_NO_TAILLIGHT;
		default:
			return LIGHT_FLAGS_HAS_LEFT_LIGHTS
				| LIGHT_FLAGS_UNUSED2;
		}
	}

	return LIGHT_FLAGS_HAS_NO_HEADLIGHT
		| LIGHT_FLAGS_HAS_NO_TAILLIGHT;
}