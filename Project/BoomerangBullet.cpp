#include "BoomerangBullet.h"

#include "CharacterManager.h"


/// <summary>
/// コンストラクタ
/// </summary>
CBoomerangBullet::CBoomerangBullet() :
    m_MovedDistance(0.0f),
    m_ReturnLength(500.0f), 
    m_bReturn(false),
    m_pHome()
{
}

/// <summary>
/// デストラクタ
/// </summary>
CBoomerangBullet::~CBoomerangBullet() {
}

/// <summary>
/// 更新
/// </summary>
void CBoomerangBullet::Update(void) {
    super::Update();

    // 通常移動
    if (!m_bReturn) {
        m_MovedDistance += m_Move.Length();
        if (m_ReturnLength < m_MovedDistance) {
            m_bReturn = true;
        } // if
    } // if
    else {
        // m_bReturn = true で 撃った人に向かっていく
        if (auto home = m_pHome.lock()) {
            // 撃った人の方向へ向かっていく
            auto dir = home->GetPosition() - m_Position;
            Mof::CVector2Utilities::Normal(dir, dir);
            m_Move = dir * m_Move.Length();
        } // if
        
        // 撃った人に当たったらshowをfalseにする
        if (auto home = m_pHome.lock()) {
            auto rect = this->GetRectangle();
            if (home->GetRectangle().CollisionRect(rect))
            {
                super::m_bShow = false;
                m_pHome.reset();
            } // if
        } // if
    } // else
    
}

/// <summary>
/// 発射
/// </summary>
/// <param name="position">発射位置</param>
/// <param name="move">更新移動量</param>
/// <param name="type">所属チーム</param>
void CBoomerangBullet::Fire(CVector2 position, CVector2 move, BulletTeamType type) {
    super::Fire(position, move, type);
    m_MovedDistance=0.0f;
    m_bReturn=false;

    if (type == BulletTeamType::Player) {
        m_pHome = CCharacterManager::Singleton().GetPlayer();
    } // if
    else {
        // 撃った直後は撃った本人が近くにいるものとする
        m_pHome = CCharacterManager::Singleton().GetNearestEnemy(position);
    } // else
}