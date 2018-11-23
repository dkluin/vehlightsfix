#ifndef _GAME_COMMON_H_
#define _GAME_COMMON_H_

//#define LOGGING_SYSTEM_ACTIVE

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#pragma pack(push, 1)

struct EditableMaterialInfo
{
	void *m_pDataRef;
	void *m_pOldData;
};

#pragma pack(pop)

RwSurfaceProperties gLightOffSurfProps = { 0.5f, 0.0f, 1.0f };
#define _gLightSurfProps		0x008A645C
auto gLightSurfProps		= (RwSurfaceProperties *const)_gLightSurfProps;
#define _gaVehicleEditMatsInfo	0x00B4DBE8
auto gaVehicleEditMatsInfo	= (EditableMaterialInfo (*const)[256])_gaVehicleEditMatsInfo;

#ifdef LOGGING_SYSTEM_ACTIVE
void PrintEditableMaterialsInfo(void);
#endif //LOGGING_SYSTEM_ACTIVE

#ifdef LOGGING_SYSTEM_ACTIVE
void PrintEditableMaterialsInfo(void)
{
	FILE *pFile;
	EditableMaterialInfo *pEditMatInfo;
	void *pDataRef;
	RwRGBA oldColor;
	RpMaterial *pMaterial;
	RwTexture *pRemap, *pTexture, *pOldTexture;
	char *pTexName, *pOldTexName;
	float fOldAmbient, fOldSpecular, fOldDiffuse;

	if(pFile = fopen("editmats.log", "w"))
	{
		fputs("OnVehicleSetupRender\n", pFile);

		pEditMatInfo = &(*gaVehicleEditMatsInfo)[0];

		while(pDataRef = pEditMatInfo->m_pDataRef)
		{
			pRemap = *CVehicleModelInfoVtbl::ms_pRemapTexture;
			pTexture = *(RwTexture **)pDataRef;

			if(pRemap && pTexture == pRemap)
			{
				pTexName = pTexture->name;
				pOldTexture = (RwTexture *)pEditMatInfo->m_pOldData;
				pOldTexName = pOldTexture ? pOldTexture->name : nullptr;

				fprintf
				(
					pFile,
					"\n"
					"Texture:\t%s (old: %s)\n",
					pTexName, pOldTexName
				);
			}
			else
			{
				pMaterial = (RpMaterial *)((char *)pDataRef - 0x04);
				pTexture = pMaterial->texture;
				pTexName = pTexture ? pTexture->name : nullptr;
				oldColor = *(RwRGBA *)&pEditMatInfo->m_pOldData;

				if(pTexture == *CVehicleModelInfoVtbl::ms_pLightsOnTexture)
				{
					pOldTexture = (RwTexture *)(++pEditMatInfo)->m_pOldData;
					pOldTexName = pOldTexture ? pOldTexture->name : nullptr;
					fOldAmbient = *(float *)&(++pEditMatInfo)->m_pOldData;
					fOldSpecular = *(float *)&(++pEditMatInfo)->m_pOldData;
					fOldDiffuse = *(float *)&(++pEditMatInfo)->m_pOldData;

					fprintf
					(
						pFile,
						"\n"
						"Texture:\t%s (old: %s)\n"
						"Color:\t\t%08X (old: %08X)\n"
						"Ambient:\t%.3f (old: %.3f)\n"
						"Specular:\t%.3f (old: %.3f)\n"
						"Diffuse:\t%.3f (old: %.3f)\n",
						pTexName, pOldTexName,
						pMaterial->color, oldColor,
						pMaterial->surfaceProps.ambient, fOldAmbient,
						pMaterial->surfaceProps.specular, fOldSpecular,
						pMaterial->surfaceProps.diffuse, fOldDiffuse
					);
				}
				else if(pTexture == *CVehicleModelInfoVtbl::ms_pLightsTexture)
				{
					fprintf
					(
						pFile,
						"\n"
						"Texture:\t%s\n"
						"Color:\t\t%08X (old: %08X)\n"
						"Ambient:\t%.3f\n"
						"Specular:\t%.3f\n"
						"Diffuse:\t%.3f\n",
						pTexName,
						pMaterial->color, oldColor,
						pMaterial->surfaceProps.ambient,
						pMaterial->surfaceProps.specular,
						pMaterial->surfaceProps.diffuse
					);
				}
				else
				{
					fprintf
					(
						pFile,
						"\n"
						"Texture:\t%s\n"
						"Color:\t\t%08X (old: %08X)\n",
						pTexName,
						pMaterial->color, oldColor
					);
				}
			}

			pEditMatInfo++;
		}

		fclose(pFile);
	}
}
#endif //LOGGING_SYSTEM_ACTIVE

#endif //_GAME_COMMON_H_
