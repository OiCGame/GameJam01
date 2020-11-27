#include "Title.h"

CTitle::CTitle(const CTitle::InitData & data)
	: super(data)
{
}

CTitle::~CTitle(void)
{
}

void CTitle::Update(void)
{
	if (g_pInput->IsKeyPush(MOFKEY_1))
	{
		ChangeScene(SceneName::Game);
	}
}

void CTitle::Render(void)
{
}
