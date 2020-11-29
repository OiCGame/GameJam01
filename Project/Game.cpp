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
#include "WeaponItemManager.h"
#include "GamePad.h"


bool CGame::LoadAsset(void) {
	const char* animFimeName[] = 
	{
		"Effect/barrier.anim",
		"explosion.anim",
		"explosion2.anim",
	};

	for (int i = 0; i < static_cast<int>(AnimationKey::Count); i++)
	{
		if (!CAnimationAsset::Load(static_cast<AnimationKey>(i), animFimeName[i]))
		{
			MOF_PRINTLOG("failed to load animation");
		}
	}



	const std::string texFileName[] = 
	{
		"Rocket.png",
		"spaceShips_001.png",
		"spaceShips_002.png",
		"spaceShips_003.png",
		"Muscle.png",
		"Tomato.png",
		"Onion.png",
		"Meet.png",
		 AnimationAsset(AnimationKey::Effect_Barrier)->GetTextureFileName(),
		 AnimationAsset(AnimationKey::Effect_Explosion)->GetTextureFileName(),
		 AnimationAsset(AnimationKey::Effect_Explosion2)->GetTextureFileName(),
		"Space_BG_01.png",
		"pot.png",
		"HP_Bar.png",
		"HP_Frame.png",
		"Pot_Bar.png",
		"Pot_Frame.png",
        "item1.png",
        "item2.png",
        "item3.png",
	};

	for (int i = 0; i < static_cast<int>(TextureKey::Count); i++)
	{
		if (!CTextureAsset::Load(static_cast<TextureKey>(i), texFileName[i].c_str()))
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

        auto start = std::make_unique< EnemyInitParam >();
        start->x= posX;
        start->scroll= scroll;
        start->type= type;
        m_EnemyStart.push_back(std::move( start ));

        auto enemy = std::make_shared<CEnemy>();
        enemy->AddObserver(m_pPotGimmick);
        CIparm.position = Mof::CVector2(posX,
                                        -scroll);
        CIparm.texture = TextureAsset(TextureKey::Enemy01);
		CIparm.type = type;
        enemy->Initialize(CIparm);
        enemy->SetTarget(player);
        CCharacterManager::Singleton().AddCharacter(enemy);
        CCollisionManager::Singleton().Register(enemy, CollisionLayer::Enemy);
    } // if


    CCharacterManager::Singleton().AddCharacter(player);
    return true;
}

void CGame::CreateEnemy(void) {
    CharacterInitParam CIparm;
    CIparm.texture = TextureAsset(TextureKey::Character);
    auto player = std::dynamic_pointer_cast<CPlayer>(CCharacterManager::Singleton().GetPlayer());
    /*
    for (auto& data : m_EnemyStart) {
        if (data->scroll < m_Stage.GetScroll()) {
            auto enemy = std::make_shared<CEnemy>();
            enemy->AddObserver(m_pPotGimmick);
            CIparm.position = Mof::CVector2(data->x,
                                            -data->scroll);
            CIparm.texture = TextureAsset(TextureKey::Enemy01);
            CIparm.type = data->type;
            enemy->Initialize(CIparm);
            enemy->SetTarget(player);
            CCharacterManager::Singleton().AddCharacter(enemy);
            CCollisionManager::Singleton().Register(enemy, CollisionLayer::Enemy);
            break;
        } // if
    } // for
    */
    /*
    auto it = std::find_if(m_EnemyStart.begin(), m_EnemyStart.end(),
                           [&](const EnemyInitParam& param) {
        return param.scroll < m_Stage.GetScroll();
    });
    if (it != m_EnemyStart.end()) {
        auto enemy = std::make_shared<CEnemy>();
        enemy->AddObserver(m_pPotGimmick);
        CIparm.position = Mof::CVector2(it->,
                                        -it->scroll);
        CIparm.texture = TextureAsset(TextureKey::Enemy01);
        CIparm.type = it->type;
        enemy->Initialize(CIparm);
        enemy->SetTarget(player);
        CCharacterManager::Singleton().AddCharacter(enemy);
        CCollisionManager::Singleton().Register(enemy, CollisionLayer::Enemy);

        m_EnemyStart.erase(std::remove_if(
            m_EnemyStart.begin(),
            m_EnemyStart.end(),
            [&](EnemyInitParam& param) {
            return param.scroll < m_Stage.GetScroll();
        }), m_EnemyStart.end());
    } // if
    */
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

	CAudioManager::Singleton().Play(SoundStreamBufferKey::Bgm0);
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
    } // if
    if (11700 < m_Stage.GetScroll()) {
        ChangeScene(SceneName::GameClear);
    } // if
    if (!CCharacterManager::Singleton().GetPlayer()) {
        ChangeScene(SceneName::GameOver);
    } // if

    this->CreateEnemy();

    // Stageの更新
    m_Stage.Update();
    m_pPotGimmick->Update();
    // Characterの更新
    CCharacterManager::Singleton().Update();
    // Bulletの更新
    CBulletManager::Singleton().Update();
    // Effectの更新
    CEffectManager::Singleton().Update();

	if (g_pPad->IsKeyPush(XINPUT_B) && m_pPotGimmick->IsAllrady())
	{
		CAudioManager::Singleton().Play(SoundBufferKey::flash_02);
		m_pPotGimmick->ResetPotFoods();
		if (auto& p = CCharacterManager::Singleton().GetPlayer())
		{
			dynamic_pointer_cast<CPlayer>(p)->GimmickFlash();
		}
	}

    // 衝突判定
    CCollisionManager::Singleton().Update();
    // ストリーム更新
    CAudioManager::Singleton().Update();
}

void CGame::Render(void) {
    m_Stage.Render();
    m_pPotGimmick->Render();
    
    CWeaponItemManager::Singleton().Render();
    CBulletManager::Singleton().Render(Mof::CVector2());
    CCharacterManager::Singleton().Render(Mof::CVector2());
    CEffectManager::Singleton().Render();
    CUICanvas::Singleton().Render();

    ::CGraphicsUtilities::RenderString(20, 20, "FPS = %d", ::CUtilities::GetFPS());
}