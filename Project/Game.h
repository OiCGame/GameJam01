#pragma once
#include "SceneDefine.h"

class CGame : public MyApp::CScene
{
private:

	using super = MyApp::CScene;

public:

	explicit CGame(const CGame::InitData& data);

	virtual ~CGame(void) override;

	virtual void Update(void) override;

	virtual void Render(void) override;
};

