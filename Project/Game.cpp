#include "Game.h"

#include "GamePad.h"
#include "Character.h"
#include "BulletManager.h"

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
	// Bulletの初期化
	CBulletManager::Singleton().Initialize();
}

CGame::~CGame(void)
{
	// Bulletの初期化
	CBulletManager::Singleton().Release();
}

void CGame::Update(void)
{
	if (g_pInput->IsKeyPush(MOFKEY_1))
	{
		ChangeScene(SceneName::Title);
	}
	gCharacter.Update();
	if (::g_pPad->IsKeyPush(XInputButton::XINPUT_A))
	{
		CBulletManager::Singleton().Fire(
			Mof::CVector2(200.0f, 200.0f),
			Mof::CVector2(5.0f, 0.0f),
			BulletTeamType::Player);
	} // if

	// Bulletの更新
	CBulletManager::Singleton().Update();
}

void CGame::Render(void)
{
	CBulletManager::Singleton().Render(Mof::CVector2());



	if (::g_pPad->IsKeyHold(XInputButton::XINPUT_A))
	{
		//auto rect = CRectangle(0.0f, 0.0f, 200.0f, 200.0f);
		//CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_BLACK);
	} // if
	gCharacter.Render(CVector2(0,0));
}
