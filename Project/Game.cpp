﻿#include "Game.h"

#include "GamePad.h"
#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Stage.h"
#include "UICanvas.h"
#include "CollisionManager.h"
#include "EffectManager.h"
#include "BulletManager.h"
#include "CharacterManager.h"
#include "Stage1.h"

CStage g_Stage;


bool CGame::LoadAsset(void) {

	const char* animFimeName[] = 
	{
		"Effect/barrier.anim",
		"explosion.anim",
	};

	const char* texFileName[] = 
	{
		"Rocket.png",
		"spaceShips_001.png",
		"spaceShips_002.png",
		"spaceShips_003.png",
		"Muscle.png",
		"Tomato.png",
		"Onion.png",
		"Meet.png",
		 AnimationAsset(AnimationKey::Effect_Barrier)->GetTextureFileName().c_str(),
		 AnimationAsset(AnimationKey::Effect_Explosion)->GetTextureFileName().c_str(),
		"Stage1.png",
	};

	for (int i = 0; i < static_cast<int>(AnimationKey::Count); i++)
	{
		if (!CAnimationAsset::Load(static_cast<AnimationKey>(i), animFimeName[i]))
		{
			MOF_PRINTLOG("failed to load animation");
		}
	}

	for (int i = 0; i < static_cast<int>(TextureKey::Count); i++)
	{
		if (!CTextureAsset::Load(static_cast<TextureKey>(i), texFileName[i]))
		{
			MOF_PRINTLOG("failed to load texture");
		}
	}

    return true;
}

CGame::CGame(const CGame::InitData& data)
    : super(data) 
{
    bool loaded = this->LoadAsset();

    CharacterInitParam CIparm;
    CIparm.position = CVector2(500, 600);
    CIparm.texture = TextureAsset(TextureKey::Character);
    auto player = std::make_shared<CPlayer>();
    player->Initialize(CIparm);
    CCollisionManager::Singleton().Register(player,CollisionLayer::Player);

    constexpr uint32_t enemy_count = 10;
    //g_pCharacters.reserve(enemy_count);
    for (int i = 0; i < enemy_count; i++) {
        auto enemy = std::make_shared<CEnemy>();
		CIparm.position = Mof::CVector2(g_Stg1EnemyStart.PosX[i],
										-g_Stg1EnemyStart.Scroll[i]);
        CIparm.texture = TextureAsset(TextureKey::Enemy01);
        enemy->Initialize(CIparm);
        enemy->SetTarget(player);
        CCharacterManager::Singleton().AddCharacter(enemy);
        CCollisionManager::Singleton().Register(enemy, CollisionLayer::Enemy);
    } // for

    // Stageの初期化
    g_Stage.Initialize();
    CCharacterManager::Singleton().AddCharacter(player);
    // Bulletの初期化
    CBulletManager::Singleton().Initialize();
    // Effectの初期化
    CEffectManager::Singleton().Initialize();
}

CGame::~CGame(void) {
    // 解放処理
    CCharacterManager::Singleton().Release();
    CBulletManager::Singleton().Release();
    CUICanvas::Singleton().Release();
}

void CGame::Update(void) {
    // シーンの遷移
    if (g_pInput->IsKeyPush(MOFKEY_1)) {
        ChangeScene(SceneName::Title);
    }
    // Stageの更新
    g_Stage.Update();
    // Characterの更新
    CCharacterManager::Singleton().Update();
    // Bulletの更新
    CBulletManager::Singleton().Update();
    // Effectの更新
    CEffectManager::Singleton().Update();
    // 衝突判定
    CCollisionManager::Singleton().Update();
}

void CGame::Render(void) {
    g_Stage.Render();
    CBulletManager::Singleton().Render(Mof::CVector2());
    CCharacterManager::Singleton().Render(Mof::CVector2());
    CEffectManager::Singleton().Render();
    CUICanvas::Singleton().Render();

    ::CGraphicsUtilities::RenderString(20, 20,"FPS = %d", ::CUtilities::GetFPS());
}