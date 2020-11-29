#include "MachineGun.h"

#include "BulletManager.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
CMachineGun::CMachineGun() :
super(){
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CMachineGun::~CMachineGun() {
}

/// <summary>
/// Bullet����
/// </summary>
/// <param name="position">���ˈʒu</param>
/// <param name="move">�X�V�ړ���</param>
/// <param name="type">�����`�[��</param>
void CMachineGun::Shot(CVector2 position, CVector2 move, BulletTeamType type, BulletType bt, TextureKey key) {
    if (0 < super::m_ShotWait) {
        return;
    } // if
    super::m_ShotWait = CUtilities::GetFrameSecond() * 10.0f;

    CBulletManager::Singleton().Fire(
        position,
        move,
        type, bt, key);
}