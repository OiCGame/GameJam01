#include "Weapon.h"

#include "BulletManager.h"
#include "Character.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
CWeapon::CWeapon() :
    m_pOwner(nullptr){
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="ptr">���L��</param>
CWeapon::CWeapon(Character* ptr) :
    m_pOwner(ptr){
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CWeapon::~CWeapon() {
}

/// <summary>
/// Bullet����
/// </summary>
/// <param name="position">���ˈʒu</param>
/// <param name="move">�X�V�ړ���</param>
/// <param name="type">�����`�[��</param>
void CWeapon::Shot(CVector2 position, CVector2 move, BulletTeamType type) {
    CBulletManager::Singleton().Fire(
        position,
        move,
        type);
}