#include "Game.h"

CGame::CGame(const CGame::InitData & data)
	: super(data)
{
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
}
