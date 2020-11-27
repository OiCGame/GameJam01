#include "Game.h"

#include "GamePad.h"


#include "BulletManager.h"


CGame::CGame(const CGame::InitData & data)
	: super(data)
{
	// Bullet‚Ì‰Šú‰»
	CBulletManager::Singleton().Initialize();
}

CGame::~CGame(void)
{
	// Bullet‚Ì‰Šú‰»
	CBulletManager::Singleton().Release();
}

void CGame::Update(void)
{
	if (g_pInput->IsKeyPush(MOFKEY_1))
	{
		ChangeScene(SceneName::Title);
	}
	if (::g_pPad->IsKeyPush(XInputButton::XINPUT_A))
	{
		CBulletManager::Singleton().Fire(
			Mof::CVector2(200.0f, 200.0f),
			Mof::CVector2(5.0f, 0.0f),
			BulletTeamType::Player);
	} // if

	// Bullet‚ÌXV
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
}
