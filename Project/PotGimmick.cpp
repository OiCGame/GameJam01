#include "PotGimmick.h"

#include "AssetDefine.h"
#include "Enemy.h"


/// <summary>
/// コンストラクタ
/// </summary>
CPotGimmick::CPotGimmick() : 
    m_Position(CVector2(0.0f, ::g_pFramework->GetWindow()->GetHeight())),
    m_pTexture() {
}
/// <summary>
/// デストラクタ
/// </summary>
CPotGimmick::~CPotGimmick() {
}

/// <summary>
/// イベント処理
/// </summary>
/// <param name="event"></param>
void CPotGimmick::OnNotify(void* chara, const char* event) {
    //CVector2 pos = CVector2(0.0f, ::g_pFramework->GetWindow()->GetHeight());
    if (event == "EnemyDead") {
        CEnemy* food = (CEnemy*)chara;

        auto dir = m_Position - food->GetPosition();
        CVector2Utilities::Normal(dir, dir);
        auto temp = PotFood(food->GetPosition(), dir * 5.0f);
        m_Foods.push_back(temp);
    } // if
}

/// <summary>
/// 初期化
/// </summary>
void CPotGimmick::Initialize(void) {
    m_pTexture = TextureAsset(TextureKey::PotGimmick);
}
/// <summary>
/// 更新
/// </summary>
void CPotGimmick::Update(void) {
    // 鍋へ移動させる
//    CVector2 pos = CVector2(0.0f, ::g_pFramework->GetWindow()->GetHeight());


    float radius  = 60.0f;
    Mof::CCircle zone(m_Position, radius);
    for (auto& food : m_Foods) {
        food.Update();
        if (zone.CollisionPoint( food.GetPosition())) {
            food.Stop();
        } // if
    } // for
}
/// <summary>
/// 描画
/// </summary>
/// <param name=""></param>
void CPotGimmick::Render(void) {
    if (auto tex = m_pTexture.lock()) {
        auto center_x = g_pFramework->GetWindow()->GetWidth() * 0.5f;

        float y = 50.0f;
        tex->Render(-(tex->GetWidth() * 0.5f),
                    g_pFramework->GetWindow()->GetHeight() - tex->GetHeight() + y);


        for (auto& food : m_Foods) {
            food.Render();
        } // for
    } // if
}
