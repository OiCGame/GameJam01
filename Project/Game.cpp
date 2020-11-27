#include "Game.h"

#include "AssetDefine.h"
#include "Bullet.h"
#include "GamePad.h"
#include "Character.h"

CBullet gBullet;
CCharacter gCharacter;

CGame::CGame(const CGame::InitData & data)
	: super(data)
{
	if (!CTextureAsset::Load(TextureKey::Bullet_01, "FOOD.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	} // if
	gBullet.SetTexture(CTextureAsset::GetAsset(TextureKey::Bullet_01));
	puts("");

	if (!CTextureAsset::Load(TextureKey::Character, "Rockets.png"))
	{
		MOF_PRINTLOG("failed to load texture");
	}
	CharacterInitParam CIparm;
	CIparm.position = CVector2(500, 600);
	CIparm.texture = TextureAsset(TextureKey::Character);
	gCharacter.Initialize(CIparm);
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
	gCharacter.Update();
}

void CGame::Render(void)
{
	if (::g_pPad->IsKeyHold(Mof::XInputButton::XINPUT_A))
	{
		auto rect = Mof::CRectangle(0.0f, 0.0f, 200.0f, 200.0f);
		::CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_BLACK);
	} // if
	gCharacter.Render(CVector2(0,0));
}
