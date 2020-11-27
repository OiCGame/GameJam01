#pragma once
#include "SceneDefine.h"

class CGameOver : public MyApp::CScene
{
private:

	using super = MyApp::CScene;

public:

	explicit CGameOver(const CGameOver::InitData& data);

	virtual ~CGameOver(void) override;

	virtual void Update(void) override;

	virtual void Render(void) override;
};

