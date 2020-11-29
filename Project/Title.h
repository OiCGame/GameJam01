#pragma once
#include "SceneDefine.h"

#define		SCROLL_SPEED		1

class CTitle : public MyApp::CScene
{
private:

	using super = MyApp::CScene;
	std::weak_ptr<CTexture> m_pTexture;
	std::weak_ptr<CTexture> m_pTitleNameTexture;
	float				 m_Scroll;
public:

	explicit CTitle(const CTitle::InitData& data);

	virtual ~CTitle(void) override;

	virtual void Update(void) override;

	virtual void Render(void) override;
};

