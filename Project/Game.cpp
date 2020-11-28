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
#include "AudioManager.h"


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
    "pot.png",
    "HP.png",
    "HPFrame.png",
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

bool CGame::InitCharas(void) {
    CharacterInitParam CIparm;
    CIparm.position = CVector2(500, 600);
    CIparm.texture = TextureAsset(TextureKey::Character);
    auto player = std::make_shared<CPlayer>();
    player->Initialize(CIparm);
    CCollisionManager::Singleton().Register(player, CollisionLayer::Player);

    rapidjson::Document document;
    LoadJsonDocument("stage1.json", document);
    const auto& info = document["stage"];
    _ASSERT_EXPR(info.IsArray(),
                 L"stage type is not array");
    for (int i = 0; i < info.Size(); i++) {
        if (!info[i].HasMember("posX") || !info[i]["posX"].IsFloat() ||
            !info[i].HasMember("scroll") || !info[i]["scroll"].IsFloat() ||
            !info[i].HasMember("type") || !info[i]["type"].IsInt()) {
            break;
        } // if
        // 値の設定
        float posX = info[i]["posX"].GetFloat();
        float scroll = info[i]["scroll"].GetFloat();
        int type = info[i]["type"].GetInt();

        auto enemy = std::make_shared<CEnemy>();
        enemy->AddObserver(m_pPotGimmick);
        CIparm.position = Mof::CVector2(posX,
                                        -scroll);
        CIparm.texture = TextureAsset(TextureKey::Enemy01);
        enemy->Initialize(CIparm);
        enemy->SetTarget(player);
        CCharacterManager::Singleton().AddCharacter(enemy);
        CCollisionManager::Singleton().Register(enemy, CollisionLayer::Enemy);
    } // if


    CCharacterManager::Singleton().AddCharacter(player);
    return true;
}

CGame::CGame(const CGame::InitData& data)
    : super(data),
    m_Stage(),
    m_pPotGimmick(std::make_shared<CPotGimmick>()) {
    bool loaded = this->LoadAsset();
    CAudioManager::Singleton().Load();
    this->InitCharas();
    // Stageの初期化
    m_Stage.Initialize();
    m_pPotGimmick->Initialize();
    // Bulletの初期化
    CBulletManager::Singleton().Initialize();
    // Effectの初期化
    CEffectManager::Singleton().Initialize();
}

CGame::~CGame(void) {
    // 解放処理
    CAudioManager::Singleton().Release();
    CCharacterManager::Singleton().Release();
    CBulletManager::Singleton().Release();
    CUICanvas::Singleton().Release();
}

void CGame::Update(void) {
    // シーンの遷移
    if (g_pInput->IsKeyPush(MOFKEY_1)) {
        ChangeScene(SceneName::Title);
    }

    if (g_pInput->IsKeyPush(MOFKEY_SPACE)) {
        CAudioManager::Singleton().Play(SoundStreamBufferKey::Bgm0);
//        CAudioManager::Singleton().Play(SoundBufferKey::Sound0);
    } // if

    // Stageの更新
    m_Stage.Update();
    m_pPotGimmick->Update();
    // Characterの更新
    CCharacterManager::Singleton().Update();
    // Bulletの更新
    CBulletManager::Singleton().Update();
    // Effectの更新
    CEffectManager::Singleton().Update();
    // 衝突判定
    CCollisionManager::Singleton().Update();
    // ストリーム更新
    CAudioManager::Singleton().Update();
}

void CGame::Render(void) {
    m_Stage.Render();
    m_pPotGimmick->Render();
    CBulletManager::Singleton().Render(Mof::CVector2());
    CCharacterManager::Singleton().Render(Mof::CVector2());
    CEffectManager::Singleton().Render();
    CUICanvas::Singleton().Render();

    ::CGraphicsUtilities::RenderString(20, 20, "FPS = %d", ::CUtilities::GetFPS());
}