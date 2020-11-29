#include "PotGimmick.h"

#include "AssetDefine.h"
#include "Enemy.h"


/// <summary>
/// コンストラクタ
/// </summary>
CPotGimmick::CPotGimmick() : 
    m_Position(CVector2(0.0f, ::g_pFramework->GetWindow()->GetHeight())),
    m_pTexture(),
	m_FoodCount(0) {
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
    if (event == "EnemyDead") {
        CEnemy* food = (CEnemy*)chara;

        auto dir = m_Position - food->GetPosition();
        CVector2Utilities::Normal(dir, dir);
        auto temp = CPotFood(food->GetPosition(), dir * 5.0f);
        m_Foods.push_back(temp);
    } // if
}

void CPotGimmick::Input(void) {
    auto target = CVector2 (g_pFramework->GetWindow()->GetWidth(), 0.0f);
    auto dir = target - m_Position;
    CVector2Utilities::Normal(dir, dir);

    for (auto& food : m_Foods) {
        food = CPotFood(food.GetPosition(), dir * 5.0f);
    } // for
    
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
    float radius  = 60.0f;
    Mof::CCircle zone(m_Position, radius);
    for (auto& food : m_Foods) {
        food.Update();
        if (zone.CollisionPoint( food.GetPosition())) {
            food.Stop();
			m_FoodCount = MOF_MIN(++m_FoodCount, FoodCountMax);
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

        float y = 70.0f;
        tex->Render(-(tex->GetWidth() * 0.4f),
                    g_pFramework->GetWindow()->GetHeight() - tex->GetHeight() + y);

		// べた書き失礼します。
		auto frame = TextureAsset(TextureKey::PotFrame);
		Vector2 framePos(tex->GetWidth() * 0.6f, g_pGraphics->GetTargetHeight() - frame->GetHeight() - 10);
		frame->Render(framePos.x, framePos.y);
		auto bar = TextureAsset(TextureKey::PotBar);
		int margin = 2;
		int barHeight = 16;
		CRectangle barRect(0, (barHeight + margin) * (FoodCountMax - m_FoodCount) - margin * m_FoodCount, bar->GetWidth(), bar->GetHeight());
		bar->Render(framePos.x + 4, framePos.y + 4 + (barHeight + margin) * (FoodCountMax - m_FoodCount), barRect, m_FoodCount == FoodCountMax ? MOF_COLOR_GREEN : MOF_COLOR_WHITE);

        // 描画
        for (auto& food : m_Foods) {
            food.Render();
        } // for
    } // if
}
