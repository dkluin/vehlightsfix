#ifndef _GAME_CPED_H_
#define _GAME_CPED_H_

class CVehicle;

#pragma pack(push, 1)

class CPed
{
public:
	char align_0[0x058C];
	CVehicle *m_pVehicle;
};

#pragma pack(pop)

#endif //_GAME_CPED_H_
