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
/// <param name="move">Bullet�̈ʒu�̍X�V�l</param>
void CWeapon::Shot(CVector2 move) {
    /*
    CBulletManager::Singleton().Fire(
        m_pOwner->GetPosition(),
        move,
        m_pOwner->GetTeamType());
    */
}