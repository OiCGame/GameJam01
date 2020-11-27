#pragma once
#include "SceneDefine.h"

class CGameClear : public MyApp::CScene
{
private:

	using super = MyApp::CScene;

public:

	explicit CGameClear(const CGameClear::InitData& data);

	virtual ~CGameClear(void) override;

	virtual void Update(void) override;

	virtual void Render(void) override;
};

