#pragma once
#include "SceneDefine.h"

#include "Stage.h"
#include "PotGimmick.h"


class CGame : public MyApp::CScene
{
private:
	//! �X�e�[�W
	CStage m_Stage;
	//! �M�~�b�N
	std::shared_ptr<CPotGimmick> m_pPotGimmick;

	using super = MyApp::CScene;

	bool LoadAsset(void);
	bool InitCharas(void);
public:

	explicit CGame(const CGame::InitData& data);

	virtual ~CGame(void) override;

	virtual void Update(void) override;

	virtual void Render(void) override;
};

