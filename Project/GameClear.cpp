#include "GameClear.h"
#include "GamePad.h"
#include "AssetDefine.h"
#include "AudioManager.h"

CGameClear::CGameClear(const CGameClear::InitData & data)
	: super(data)
{
	if (!CTextureAsset::Load(TextureKey::ClearBack, "Space_BG_02.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	}
	if (!CTextureAsset::Load(TextureKey::ClearName, "GameClear.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	}
	m_pTexture = TextureAsset(TextureKey::ClearBack);
	m_pNameTexture = TextureAsset(TextureKey::ClearName);
	CAudioManager::Singleton().Play(SoundStreamBufferKey::gameclear);
}

CGameClear::~CGameClear(void)
{
}

void CGameClear::Update(void)
{
	if (g_pPad->IsKeyPush(XInputButton::XINPUT_A))
	{
		CAudioManager::Singleton().Play(SoundBufferKey::ok_se);
		ChangeScene(SceneName::Title);
	}
}

void CGameClear::Render(void)
{
	if (auto r = m_pTexture.lock())
	{
		float ratio = g_pGraphics->GetTargetWidth() / (float)r->GetWidth();
		float w = (g_pGraphics->GetTargetWidth() - r->GetWidth() * ratio) * 0.5f;
		r->RenderScale(w, 0, ratio, 1.0f);
	}
	if (auto r = m_pNameTexture.lock())
	{
		r->Render(290, 200);
	}

}
