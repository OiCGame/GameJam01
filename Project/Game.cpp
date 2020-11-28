#include "Game.h"

#include "GamePad.h"
#include "Character.h"
#include "BulletManager.h"
#include "Enemy.h"
#include "Player.h"
#include "Stage.h"

CStage g_Stage;

std::vector<std::shared_ptr<CCharacter>> _characters;

CGame::CGame(const CGame::InitData& data)
    : super(data) {
	//ステージテクスチャ読み込み
	if (!CTextureAsset::Load(TextureKey::Stage, "Stage1.png")) {
		MOF_PRINTLOG("failed to load texture");
	}
    // キャラクター作成
    if (!CTextureAsset::Load(TextureKey::Character, "Rockets.png")) {
        MOF_PRINTLOG("failed to load texture");
    }
    CharacterInitParam CIparm;
    CIparm.position = CVector2(500, 600);
    CIparm.texture = TextureAsset(TextureKey::Character);
    constexpr uint32_t enemy_count = 6;
    _characters.reserve(6);
    for (int i = 0; i < 6; i++) {
        auto temp = std::make_shared<CEnemy>();
        CIparm.position.x = ::CUtilities::Random(200, 700);
        CIparm.position.y = ::CUtilities::Random(200, 700);
        temp->Initialize(CIparm);
        _characters.push_back(temp);
    } // for
    auto player = std::make_shared<CPlayer>();
    player->Initialize(CIparm);
    _characters.push_back(player);

	// Stageの初期化
	g_Stage.Initialize();

    // Bulletの初期化
    CBulletManager::Singleton().Initialize();
}

CGame::~CGame(void) {
    // Bulletの初期化
    CBulletManager::Singleton().Release();
}

void CGame::Update(void) {
    if (g_pInput->IsKeyPush(MOFKEY_1)) {
        ChangeScene(SceneName::Title);
    }
    for (auto enemy : _characters) {
        enemy->Update();
    } // for

	g_Stage.Update();

    // Bulletの更新
    CBulletManager::Singleton().Update();
}

void CGame::Render(void) {
	g_Stage.Render();
    CBulletManager::Singleton().Render(Mof::CVector2());
 
    for (auto chara : _characters) {
        chara->Render(CVector2(0, 0));
    } // for

}
