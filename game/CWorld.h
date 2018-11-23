#ifndef _GAME_CWORLD_H_
#define _GAME_CWORLD_H_

class CWorld
{

};

namespace CWorldVtbl
{
#define _CWorld__ucPlayerInFocus	0x00B7CD74
	auto ucPlayerInFocus	= (unsigned char *const)_CWorld__ucPlayerInFocus;
#define _CWorld__aPlayers			0x00B7CD98
	auto aPlayers			= (CPlayerInfo (*const)[2])_CWorld__aPlayers;
};

#endif //_GAME_CWORLD_H_
