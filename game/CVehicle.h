#ifndef _GAME_CVEHICLE_H_
#define _GAME_CVEHICLE_H_

#define VEHICLE_FLAGS0_IS_BRAKING	(1 << 5)

#define VEHICLE_FLAGS5_IS_REMOTE	(1 << 7)

#define LIGHT_FLAGS_HAS_LEFT_LIGHTS			(1 << 0)
#define LIGHT_FLAGS_UNUSED2					(1 << 1)
#define LIGHT_FLAGS_HAS_UNBREAKABLE_LIGHTS	(1 << 2)
#define LIGHT_FLAGS_HAS_NO_HEADLIGHT		(1 << 4)
#define LIGHT_FLAGS_HAS_NO_TAILLIGHT		(1 << 5)

#define LIGHT_STATE_HEADLIGHTS_ON	(1 << 0)
#define LIGHT_STATE_HEADLIGHTS2_ON	(1 << 1)
#define LIGHT_STATE_TAILLIGHTS_ON	(1 << 2)
#define LIGHT_STATE_TAILLIGHTS2_ON	(1 << 3)

#define LIGHT_SIDE_LEFT		0
#define LIGHT_SIDE_RIGHT	1

enum eVehicleClass : int
{
	VEHCLASS_AUTOMOBILE,
	VEHCLASS_MONSTERTRUCK,
	VEHCLASS_QUADBIKE,
	VEHCLASS_HELI,
	VEHCLASS_PLANE,
	VEHCLASS_BOAT,
	VEHCLASS_TRAIN,
	VEHCLASS_FAKEHELI,
	VEHCLASS_FAKEPLANE,
	VEHCLASS_BIKE,
	VEHCLASS_BMX,
	VEHCLASS_TRAILER
};

enum eVehicleAppearance : int
{
	VEHAPPEARANCE_UNDEFINED,
	VEHAPPEARANCE_AUTOMOBILE,
	VEHAPPEARANCE_BIKE,
	VEHAPPEARANCE_HELI,
	VEHAPPEARANCE_BOAT,
	VEHAPPEARANCE_PLANE
};

enum eLights : char
{
	LEFT_HEADLIGHT,
	RIGHT_HEADLIGHT,
	LEFT_TAILLIGHT,
	RIGHT_TAILLIGHT
};

class CMatrix;

#pragma pack(push, 1)

class CVehicle
{
public:
	CPhysical m_physical;
	char align_138[0x02F0];
	unsigned char m_aVehicleFlags[8];
	char align_430[0x30];
	CPed *m_pDriver;
	char align_464[0x3C];
	float m_fBrakePedal;
	char align_4A4[0x20];
	CVehicle *m_pCab;
	CVehicle *m_pTrailer;
	char align_4CC[0xB8];
	unsigned int uiLightState;
	char align_588[8];
	eVehicleClass m_eClass;
	eVehicleClass m_eSubClass;
	char align_598[8];

	void Render(void);
	eVehicleAppearance GetVehicleAppearance(void);
	void SetupRender(void);
	void ResetAfterRender(void);
	void DoHeadLightBeam(int iLightSide, CMatrix &matrix, unsigned char ucPutOnRight);
	void DoHeadLightReflectionSingle(CMatrix &matrix, unsigned char ucPutOnRight);
	bool DoTailLightEffect(int iLightSide, CMatrix &matrix, unsigned char ucPutOnRight, unsigned char ucIsActive, unsigned int uiLightFlags, unsigned char ucIsntStopLightAnyMeans);
	void DoVehicleLights(CMatrix &matrix, unsigned int uiLightFlags);
	unsigned int GetLightFlags(void);
};

#pragma pack(pop)

namespace CVehicleVtbl
{
#define _CVehicle__Render						0x006D0E60
	auto Render							= (void (__thiscall *const)(CVehicle *self))_CVehicle__Render;
#define _CVehicle__GetVehicleAppearance			0x006D1080
	auto GetVehicleAppearance			= (eVehicleAppearance (__thiscall *const)(CVehicle *self))_CVehicle__GetVehicleAppearance;
#define _CVehicle__SetupRender					0x006D64F0
	auto SetupRender					= (void (__thiscall *const)(CVehicle *self))_CVehicle__SetupRender;
#define _CVehicle__ResetAfterRender				0x006D64F0
	auto ResetAfterRender				= (void (__thiscall *const)(CVehicle *self))_CVehicle__ResetAfterRender;
#define _CVehicle__DoHeadLightBeam				0x006E0E20
	auto DoHeadLightBeam				= (void (__thiscall *const)(CVehicle *self, int iLightSide, CMatrix &matrix, unsigned char ucPutOnRight))_CVehicle__DoHeadLightBeam;
#define _CVehicle__DoHeadLightReflectionSingle	0x006E1440
	auto DoHeadLightReflectionSingle	= (void (__thiscall *const)(CVehicle *self, CMatrix &matrix, unsigned char ucPutOnRight))_CVehicle__DoHeadLightReflectionSingle;
#define _CVehicle__DoTailLightEffect			0x006E1780
	auto DoTailLightEffect				= (bool (__thiscall *const)(CVehicle *self, int iLightSide, CMatrix &matrix, unsigned char ucPutOnRight, unsigned char ucIsActive, unsigned int uiLightFlags, unsigned char ucIsntStopLightAnyMeans))_CVehicle__DoTailLightEffect;
#define _CVehicle__DoVehicleLights				0x006E1A60
	auto DoVehicleLights				= (void (__thiscall *const)(CVehicle *self, CMatrix &matrix, unsigned int uiLightFlags))_CVehicle__DoVehicleLights;
};

inline void CVehicle::Render(void)
{
	CVehicleVtbl::Render(this);
}

inline eVehicleAppearance CVehicle::GetVehicleAppearance(void)
{
	return CVehicleVtbl::GetVehicleAppearance(this);
}

inline void CVehicle::SetupRender(void)
{
	CVehicleVtbl::SetupRender(this);
}

inline void CVehicle::ResetAfterRender(void)
{
	CVehicleVtbl::ResetAfterRender(this);
}

inline void CVehicle::DoHeadLightBeam(int iLightSide, CMatrix &matrix, unsigned char ucPutOnRight)
{
	CVehicleVtbl::DoHeadLightBeam(this, iLightSide, matrix, ucPutOnRight);
}

inline void CVehicle::DoHeadLightReflectionSingle(CMatrix &matrix, unsigned char ucPutOnRight)
{
	CVehicleVtbl::DoHeadLightReflectionSingle(this, matrix, ucPutOnRight);
}

inline bool CVehicle::DoTailLightEffect(int iLightSide, CMatrix &matrix, unsigned char ucPutOnRight, unsigned char ucIsActive, unsigned int uiLightFlags, unsigned char ucIsntStopLightAnyMeans)
{
	return CVehicleVtbl::DoTailLightEffect(this, iLightSide, matrix, ucPutOnRight, ucIsActive, uiLightFlags, ucIsntStopLightAnyMeans);
}

inline void CVehicle::DoVehicleLights(CMatrix &matrix, unsigned int uiLightFlags)
{
	CVehicleVtbl::DoVehicleLights(this, matrix, uiLightFlags);
}

namespace CVehicleVtbl
{
	unsigned int __fastcall GetLightFlags(CVehicle *self, int edx)
	{
		eVehicleAppearance eAppearance = self->GetVehicleAppearance();

		if(eAppearance == VEHAPPEARANCE_AUTOMOBILE)
		{
			switch(self->m_physical.m_entity.m_eModel)
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
};

inline unsigned int CVehicle::GetLightFlags(void)
{
	return CVehicleVtbl::GetLightFlags(this, 0);
}

#endif //_GAME_CVEHICLE_H_
