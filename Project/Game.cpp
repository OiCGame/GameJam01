﻿#include "Game.h"

#include "GamePad.h"
#include "Character.h"
#include "BulletManager.h"
#include "CharacterManager.h"
#include "Enemy.h"
#include "Player.h"
#include "Stage.h"
#include "UICanvas.h"


CStage g_Stage;


CGame::CGame(const CGame::InitData& data)
    : super(data) 
{
    //ステージテクスチャ読み込み
    if (!CTextureAsset::Load(TextureKey::Stage, "Stage1.png")) {
        MOF_PRINTLOG("failed to load texture");
    }
    // キャラクター作成
    if (!CTextureAsset::Load(TextureKey::Character, "Rocket.png")) {
        MOF_PRINTLOG("failed to load texture");
    }
    if (!CTextureAsset::Load(TextureKey::Enemy01, "spaceShips_001.png")) {
        MOF_PRINTLOG("failed to load texture");
    }
    if (!CTextureAsset::Load(TextureKey::Muscle, "Muscle.png")) {
        MOF_PRINTLOG("failed to load texture");
    }
    CharacterInitParam CIparm;
    CIparm.position = CVector2(500, 600);
    CIparm.texture = TextureAsset(TextureKey::Character);
    auto player = std::make_shared<CPlayer>();
    player->Initialize(CIparm);

    constexpr uint32_t enemy_count = 1;
    //g_pCharacters.reserve(enemy_count);
    for (int i = 0; i < enemy_count; i++) {
        auto temp = std::make_shared<CEnemy>();
        CIparm.position = Mof::CVector2(::CUtilities::Random(200, 700),
                                        ::CUtilities::Random(200, 700));
        CIparm.texture = TextureAsset(TextureKey::Enemy01);
        temp->Initialize(CIparm);
        temp->SetTarget(player);
//        g_pCharacters.push_back(temp);
        CCharacterManager::Singleton().AddCharacter(temp);
    } // for

    // Stageの初期化
    g_Stage.Initialize();
    CCharacterManager::Singleton().AddCharacter(player);
//    g_pCharacters.push_back();

    // Bulletの初期化
    CBulletManager::Singleton().Initialize();
}

CGame::~CGame(void) {
    // 解放処理
    CCharacterManager::Singleton().Release();
    CBulletManager::Singleton().Release();
    CUICanvas::Singleton().Release();
}

void CGame::Update(void) {
    if (g_pInput->IsKeyPush(MOFKEY_1)) {
        ChangeScene(SceneName::Title);
    }

    g_Stage.Update();

    CCharacterManager::Singleton().Update();
    

    // Bulletの更新
    CBulletManager::Singleton().Update();
}

void CGame::Render(void) {
    g_Stage.Render();
    CBulletManager::Singleton().Render(Mof::CVector2());
    CCharacterManager::Singleton().Render(Mof::CVector2());

    CUICanvas::Singleton().Render();
}
