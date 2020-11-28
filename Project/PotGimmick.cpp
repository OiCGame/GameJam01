#include "PotGimmick.h"

#include "AssetDefine.h"
#include "Enemy.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
CPotGimmick::CPotGimmick() : 
    m_Position(CVector2(0.0f, ::g_pFramework->GetWindow()->GetHeight())),
    m_pTexture() {
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
CPotGimmick::~CPotGimmick() {
}

/// <summary>
/// �C�x���g����
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
/// ������
/// </summary>
void CPotGimmick::Initialize(void) {
    m_pTexture = TextureAsset(TextureKey::PotGimmick);
}
/// <summary>
/// �X�V
/// </summary>
void CPotGimmick::Update(void) {
    // ��ֈړ�������
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
/// �`��
/// </summary>
/// <param name=""></param>
void CPotGimmick::Render(void) {
    if (auto tex = m_pTexture.lock()) {
        auto center_x = g_pFramework->GetWindow()->GetWidth() * 0.5f;

        float y = 50.0f;
        tex->Render(-(tex->GetWidth() * 0.5f),
                    g_pFramework->GetWindow()->GetHeight() - tex->GetHeight() + y);
        // �`��
        for (auto& food : m_Foods) {
            food.Render();
        } // for
    } // if
}
