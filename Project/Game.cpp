#include "Game.h"

#include "AssetDefine.h"
#include "Bullet.h"
#include "GamePad.h"

CBullet gBullet;

CGame::CGame(const CGame::InitData & data)
	: super(data)
{
	SetCurrentDirectory("../Resource");


	if (!CTextureAsset::Load(TextureKey::Bullet_01, "FOOD.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	} // if
	gBullet.SetTexture(CTextureAsset::GetAsset(TextureKey::Bullet_01));
	puts("");
}

CGame::~CGame(void)
{
}

void CGame::Update(void)
{
	if (g_pInput->IsKeyPush(MOFKEY_1))
	{
		ChangeScene(SceneName::Title);
	}
}

void CGame::Render(void)
{
	if (::g_pPad->IsKeyHold(Mof::XInputButton::XINPUT_A))
	{
		auto rect = Mof::CRectangle(0.0f, 0.0f, 200.0f, 200.0f);
		::CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_BLACK);
	} // if
}
