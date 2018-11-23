#ifndef _GAME_RENDERWARE_H_
#define _GAME_RENDERWARE_H_

#pragma pack(push, 1)

struct RwRGBA
{
	unsigned char r, g, b, a;
};

struct RwTexture
{
	char align_0[0x10];
	char name[32];
};

struct RwSurfaceProperties
{
	float ambient;
	float specular;
	float diffuse;
};

struct RpMaterial
{
	RwTexture *texture;
	RwRGBA color;
	char align_8[4];
	RwSurfaceProperties surfaceProps;
};

struct RpAtomic;
struct RpClump;

#pragma pack(pop)

#endif //_GAME_RENDERWARE_H_
