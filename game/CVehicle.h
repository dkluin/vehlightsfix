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
	unsigned int __fastcall GetLightFlags(CVehicle *self, int edx);
}

#endif //_GAME_CVEHICLE_H_
