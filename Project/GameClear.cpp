#include "GameClear.h"
#include "AssetDefine.h"

CGameClear::CGameClear(const CGameClear::InitData & data)
	: super(data)
{
	if (!CTextureAsset::Load(TextureKey::ClearBack, "ClearBack.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	}
	if (!CTextureAsset::Load(TextureKey::ClearName, "GameClear.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	}
	m_pTexture = TextureAsset(TextureKey::ClearBack);
	m_pNameTexture = TextureAsset(TextureKey::ClearName);
}

CGameClear::~CGameClear(void)
{
}

void CGameClear::Update(void)
{
}

void CGameClear::Render(void)
{
	if (auto r = m_pTexture.lock())
	{
		r->Render(0, 0);
	}
	if (auto r = m_pNameTexture.lock())
	{
		r->Render(460, 200);
	}
}
