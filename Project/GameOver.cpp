#include "GameOver.h"
#include "GamePad.h"
#include "AssetDefine.h"
#include "AudioManager.h"

CGameOver::CGameOver(const CGameOver::InitData & data)
	: super(data)
{
	if (!CTextureAsset::Load(TextureKey::OverBack, "Space_BG_03.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	}
	if (!CTextureAsset::Load(TextureKey::OverName, "GameOver.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	}
	m_pTexture = TextureAsset(TextureKey::OverBack);
	m_pNameTexture = TextureAsset(TextureKey::OverName);
	CAudioManager::Singleton().Play(SoundStreamBufferKey::gameover);
}

CGameOver::~CGameOver(void)
{
}

void CGameOver::Update(void)
{
	if (g_pPad->IsKeyPush(XInputButton::XINPUT_A))
	{
		CAudioManager::Singleton().Play(SoundBufferKey::ok_se);
		ChangeScene(SceneName::Title);
	}
}

void CGameOver::Render(void)
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
