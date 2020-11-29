#pragma once
#include "SceneDefine.h"

class CGameClear : public MyApp::CScene
{
private:

	using super = MyApp::CScene;

	std::weak_ptr<CTexture> m_pTexture;
	std::weak_ptr<CTexture> m_pNameTexture;
public:

	explicit CGameClear(const CGameClear::InitData& data);

	virtual ~CGameClear(void) override;

	virtual void Update(void) override;

	virtual void Render(void) override;
};

