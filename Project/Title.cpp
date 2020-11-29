#include "Title.h"
#include "GamePad.h"
#include "AssetDefine.h"
#include "AudioManager.h"

CTitle::CTitle(const CTitle::InitData & data)
	: super(data)
{
	if (!CTextureAsset::Load(TextureKey::TitleBack, "TitleBack.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	}
	if (!CTextureAsset::Load(TextureKey::TitleName, "title.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	}
	m_pTexture = TextureAsset(TextureKey::TitleBack);
	m_pTitleNameTexture = TextureAsset(TextureKey::TitleName);
	m_Scroll = 0;

	CAudioManager::Singleton().Play(SoundStreamBufferKey::title);
}

CTitle::~CTitle(void)
{
}

void CTitle::Update(void)
{
	m_Scroll += SCROLL_SPEED;
	if (g_pPad->IsKeyPush(XInputButton::XINPUT_A))
	{
		CAudioManager::Singleton().Play(SoundBufferKey::ok_se);
		ChangeScene(SceneName::Game);
	}
}

void CTitle::Render(void)
{
	if (auto r = m_pTexture.lock())
	{
		int h = r->GetHeight();
		float ratio = g_pGraphics->GetTargetWidth() / (float)r->GetWidth();
		float w = (g_pGraphics->GetTargetWidth() - r->GetWidth() * ratio) * 0.5f;
		int sch = g_pGraphics->GetTargetHeight();
		for (float y = ((int)m_Scroll % h) - h; y < sch; y += h)
		{
			r->RenderScale(w, y, ratio, 1.0f);
		}
	}
	if (auto r = m_pTitleNameTexture.lock())
	{
		r->Render(460, 200);
	}
}
