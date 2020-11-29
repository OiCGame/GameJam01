#include "GameOver.h"

CGameOver::CGameOver(const CGameOver::InitData & data)
	: super(data)
{
}

CGameOver::~CGameOver(void)
{
}

void CGameOver::Update(void)
{
	if (g_pInput->IsKeyPush(MOFKEY_1)) {
		ChangeScene(SceneName::Title);
	} // if
}

void CGameOver::Render(void)
{
	::CGraphicsUtilities::RenderString(550.0f, 500.0, "GameOver");
}
