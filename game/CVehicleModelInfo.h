#ifndef _GAME_CVEHICLEMODELINFO_H_
#define _GAME_CVEHICLEMODELINFO_H_

namespace CVehicleModelInfoVtbl
{
#define _CVehicleModelInfo__ms_pRemapTexture	0x00B4E47C
	auto ms_pRemapTexture		= (RwTexture **const)_CVehicleModelInfo__ms_pRemapTexture;
#define _CVehicleModelInfo__ms_pLightsTexture	0x00B4E68C
	auto ms_pLightsTexture		= (RwTexture **const)_CVehicleModelInfo__ms_pLightsTexture;
#define _CVehicleModelInfo__ms_pLightsOnTexture	0x00B4E690
	auto ms_pLightsOnTexture	= (RwTexture **const)_CVehicleModelInfo__ms_pLightsOnTexture;
};

#pragma pack(push, 1)

class CVehicleModelInfo
{
public:
	static RpMaterial *SetEditableMaterialsCB(RpMaterial *pMaterial, void *pData);
	static RpAtomic *SetEditableMaterialsCB(RpAtomic *pAtomic, void *pData);
	static void SetEditableMaterials(RpClump *pClump);
	static void ResetEditableMaterials(RpClump *pClump);
};

#pragma pack(pop)

namespace CVehicleModelInfoVtbl
{
#define _CVehicleModelInfo__SetEditableMaterialsCB_Material	0x004C8220
	auto SetEditableMaterialsCB_Material	= (RpMaterial *(__cdecl *const)(RpMaterial *pMaterial, void *pData))_CVehicleModelInfo__SetEditableMaterialsCB_Material;
#define _CVehicleModelInfo__SetEditableMaterialsCB_Atomic	0x004C83E0
	auto SetEditableMaterialsCB_Atomic		= (RpAtomic *(__cdecl *const)(RpAtomic *pAtomic, void *pData))_CVehicleModelInfo__SetEditableMaterialsCB_Atomic;
#define _CVehicleModelInfo__SetEditableMaterials			0x004C8430
	auto SetEditableMaterials				= (void (__cdecl *const)(RpClump *pClump))_CVehicleModelInfo__SetEditableMaterials;
#define _CVehicleModelInfo__ResetEditableMaterials			0x004C8460
	auto ResetEditableMaterials				= (void (__cdecl *const)(RpClump *pClump))_CVehicleModelInfo__ResetEditableMaterials;
};

inline RpMaterial *CVehicleModelInfo::SetEditableMaterialsCB(RpMaterial *pMaterial, void *pData)
{
	return CVehicleModelInfoVtbl::SetEditableMaterialsCB_Material(pMaterial, pData);
}

inline RpAtomic *CVehicleModelInfo::SetEditableMaterialsCB(RpAtomic *pAtomic, void *pData)
{
	return CVehicleModelInfoVtbl::SetEditableMaterialsCB_Atomic(pAtomic, pData);
}

inline void CVehicleModelInfo::SetEditableMaterials(RpClump *pClump)
{
	CVehicleModelInfoVtbl::SetEditableMaterials(pClump);
}

inline void CVehicleModelInfo::ResetEditableMaterials(RpClump *pClump)
{
	CVehicleModelInfoVtbl::ResetEditableMaterials(pClump);
}

#endif //_GAME_CVEHICLEMODELINFO_H_
