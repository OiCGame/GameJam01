#include "HomingBullet.h"

#include "CharacterManager.h"


CHomingBullet ::CHomingBullet () :
    super(),
m_pTarget()
{
}

CHomingBullet ::~CHomingBullet () {
}

void CHomingBullet ::Update(void) {
    super::Update();
    if (auto target = m_pTarget.lock()) {
        auto dir = target->GetPosition() - m_Position;
        Mof::CVector2Utilities::Normal(dir, dir);

        m_Move = dir * m_Move.Length();
    } // if
}

void CHomingBullet ::Fire(CVector2 position, CVector2 move, BulletTeamType type) {
    super::Fire(position, move, type);
    if (type == BulletTeamType::Player) {
        m_pTarget = CCharacterManager::Singleton().GetNearestEnemy(position);
    } // if
    else  {
        m_pTarget = CCharacterManager::Singleton().GetPlayer();
    } // else
}