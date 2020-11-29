#pragma once
#include "SceneDefine.h"

#include "Stage.h"
#include "PotGimmick.h"

class CGame : public MyApp::CScene
{
private:
	//! ステージ
	CStage m_Stage;
	//! ギミック
	std::shared_ptr<CPotGimmick> m_pPotGimmick;
	//! エネミー初期情報
	std::vector < std::unique_ptr< EnemyInitParam >> m_EnemyStart;

	using super = MyApp::CScene;

	bool LoadAsset(void);
	bool InitCharas(void);
	void CreateEnemy(void);
public:

	explicit CGame(const CGame::InitData& data);

	virtual ~CGame(void) override;

	virtual void Update(void) override;

	virtual void Render(void) override;
};

