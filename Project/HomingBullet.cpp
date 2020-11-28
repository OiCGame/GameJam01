#include "HomingBullet.h"

#include "CharacterManager.h"


/// <summary>
/// コンストラクタ
/// </summary>
CHomingBullet ::CHomingBullet () :
    super(),
m_pTarget()
{
}

/// <summary>
/// デストラクタ
/// </summary>
CHomingBullet ::~CHomingBullet () {
}

/// <summary>
/// 更新
/// </summary>
/// <param name=""></param>
void CHomingBullet ::Update(void) {
    super::Update();
    if (auto target = m_pTarget.lock()) {
        // ターゲットの方向へ向かっていく
        auto dir = target->GetPosition() - m_Position;
        Mof::CVector2Utilities::Normal(dir, dir);
        m_Move = dir * m_Move.Length();
    } // if
}

/// <summary>
/// 発射
/// </summary>
/// <param name="position">発射位置</param>
/// <param name="move">更新移動量</param>
/// <param name="type">所属チーム</param>
void CHomingBullet ::Fire(CVector2 position, CVector2 move, BulletTeamType type) {
    super::Fire(position, move, type);
    if (type == BulletTeamType::Player) {
        m_pTarget = CCharacterManager::Singleton().GetNearestEnemy(position);
    } // if
    else  {
        m_pTarget = CCharacterManager::Singleton().GetPlayer();
    } // else
}