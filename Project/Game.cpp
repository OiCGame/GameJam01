#include "Game.h"

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


CStage g_Stage;


bool CGame::LoadAsset(void) {
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
    if (!CTextureAsset::Load(TextureKey::Enemy02, "spaceShips_002.png")) {
        MOF_PRINTLOG("failed to load texture");
    }
    if (!CTextureAsset::Load(TextureKey::Enemy03, "spaceShips_003.png")) {
        MOF_PRINTLOG("failed to load texture");
    }
    if (!CTextureAsset::Load(TextureKey::Muscle, "Muscle.png")) {
        MOF_PRINTLOG("failed to load texture");
    }
    // Bulletのテクスチャを用意する
    if (!CTextureAsset::Load(TextureKey::Bullet_01, "Tomato.png")) {
        MOF_PRINTLOG("failed to load texture");
        return false;
    } // if
    if (!CTextureAsset::Load(TextureKey::Bullet_02, "Onion.png")) {
        MOF_PRINTLOG("failed to load texture");
        return false;
    } // if
    if (!CTextureAsset::Load(TextureKey::Bullet_03, "Meet.png")) {
        MOF_PRINTLOG("failed to load texture");
        return false;
    } // if

    if (!CTextureAsset::Load(TextureKey::Bullet_03, "Meet.png")) {
        MOF_PRINTLOG("failed to load texture");
        return false;
    } // if


    if (!CSoundBufferAsset::Load(SoundBufferKey::Sound0, "shot1.mp3")) {
        MOF_PRINTLOG("failed to load sound");
        return false;
    } // if
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
    : super(data) {
    bool loaded = this->LoadAsset();

    this->InitCharas();

    // Stageの初期化
    g_Stage.Initialize();
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

    if (g_pInput->IsKeyPush(MOFKEY_SPACE)) {
        CAudioManager::Singleton().Play(SoundBufferKey::Sound0);
    } // if

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

    ::CGraphicsUtilities::RenderString(20, 20, "FPS = %d", ::CUtilities::GetFPS());
}