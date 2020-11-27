#pragma once
#include "SceneDefine.h"

class CTitle : public MyApp::CScene
{
private:

	using super = MyApp::CScene;

public:

	explicit CTitle(const CTitle::InitData& data);

	virtual ~CTitle(void) override;

	virtual void Update(void) override;

	virtual void Render(void) override;
};

