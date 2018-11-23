#ifndef _GAME_CTRAIN_H_
#define _GAME_CTRAIN_H_

#define TRAIN_FLAGS0_IS_HEAD_CARRIAGE	(1 << 3)
#define TRAIN_FLAGS0_IS_TAIL_CARRIAGE	(1 << 4)

#define TRAIN_FLAGS1_IS_DERAILED		(1 << 0)

#pragma pack(push, 1)

class CTrain
{
public:
	CVehicle m_vehicle;
	char align_5A0[0x18];
	unsigned char m_aTrainFlags[4];

	void PreRender(void);
	void Render(void);
	void ProcessControl(void);
};

#pragma pack(pop)

namespace CTrainVtbl
{
#define _CTrain__PreRender		0x006F5570
	auto PreRender		= (void (__thiscall *const)(CTrain *self))_CTrain__PreRender;
#define _CTrain__Render			0x006F55C0
	auto Render			= (void (__thiscall *const)(CTrain *self))_CTrain__Render;
#define _CTrain__ProcessControl	0x006F86A0
	auto ProcessControl	= (void (__thiscall *const)(CTrain *self))_CTrain__ProcessControl;
};

inline void CTrain::PreRender(void)
{
	CTrainVtbl::PreRender(this);
}

inline void CTrain::Render(void)
{
	CTrainVtbl::Render(this);
}

inline void CTrain::ProcessControl(void)
{
	CTrainVtbl::ProcessControl(this);
}

#endif //_GAME_CTRAIN_H_
