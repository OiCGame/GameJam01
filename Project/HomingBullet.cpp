#include "HomingBullet.h"

#include "CharacterManager.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
CHomingBullet ::CHomingBullet () :
    super(),
m_pTarget()
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CHomingBullet ::~CHomingBullet () {
}

/// <summary>
/// �X�V
/// </summary>
/// <param name=""></param>
void CHomingBullet ::Update(void) {
    super::Update();
    if (auto target = m_pTarget.lock()) {
        // �^�[�Q�b�g�̕����֌������Ă���
        auto dir = target->GetPosition() - m_Position;
        Mof::CVector2Utilities::Normal(dir, dir);
        m_Move = dir * m_Move.Length();
    } // if
}

/// <summary>
/// ����
/// </summary>
/// <param name="position">���ˈʒu</param>
/// <param name="move">�X�V�ړ���</param>
/// <param name="type">�����`�[��</param>
void CHomingBullet ::Fire(CVector2 position, CVector2 move, BulletTeamType type) {
    super::Fire(position, move, type);
    if (type == BulletTeamType::Player) {
        m_pTarget = CCharacterManager::Singleton().GetNearestEnemy(position);
    } // if
    else  {
        m_pTarget = CCharacterManager::Singleton().GetPlayer();
    } // else
}