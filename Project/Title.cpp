#include "Title.h"
#include "GamePad.h"
#include "AssetDefine.h"
#include "AudioManager.h"
#include "UICanvas.h"

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

	CUICanvas::Singleton().GetFont().SetSize(50);
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

	CFont& font = CUICanvas::Singleton().GetFont();

	CRectangle fontRect;
	font.CalculateStringRect(0, 0, "ボタンでスタート！", fontRect);

	CCircle buttonCircle(0, 0, 32);

	float rw = (buttonCircle.r + fontRect.GetWidth());

	buttonCircle.Position = Vector2((g_pGraphics->GetTargetWidth() - rw) * 0.5f, g_pGraphics->GetTargetHeight() * 0.6f);
	Vector2 renderPos(buttonCircle.x, buttonCircle.y);
	renderPos.x += buttonCircle.r;
	renderPos.y -= buttonCircle.r * 0.6f;
	CGraphicsUtilities::RenderFillCircle(buttonCircle, MOF_COLOR_BLACK);
	buttonCircle.r -= 3;
	CGraphicsUtilities::RenderFillCircle(buttonCircle, MOF_COLOR_GREEN);
	font.CalculateStringRect(0, 0, "A", fontRect);
    font.RenderString(buttonCircle.x - fontRect.GetWidth() * 0.5f, renderPos.y, MOF_COLOR_BLACK, "A");
    font.RenderString(renderPos.x, renderPos.y, MOF_COLOR_WHITE, "ボタンでスタート！");

	buttonCircle.y += fontRect.GetHeight() + 30;
	renderPos = Vector2(buttonCircle.x, buttonCircle.y);
	renderPos.x += buttonCircle.r;
	renderPos.y -= buttonCircle.r * 0.6f;
	CGraphicsUtilities::RenderFillCircle(buttonCircle, MOF_COLOR_BLACK);
	buttonCircle.r -= 3;
	CGraphicsUtilities::RenderFillCircle(buttonCircle, MOF_COLOR_CWHITE);
	CGraphicsUtilities::RenderFillTriangle(
		Vector2(buttonCircle.x + 10, buttonCircle.y - 10),
		Vector2(buttonCircle.x + 10, buttonCircle.y + 10),
		Vector2(buttonCircle.x - 10, buttonCircle.y     ), MOF_COLOR_BLACK, MOF_COLOR_BLACK, MOF_COLOR_BLACK
	);
	font.RenderString(renderPos.x, renderPos.y, MOF_COLOR_WHITE, "ボタンで終了！");
}
