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
/*
bool CWeapon::CanShot(void) const {
    return m_ShotWait <= 0;
}
*/
/// <summary>
/// Bullet����
/// </summary>
/// <param name="position">���ˈʒu</param>
/// <param name="move">�X�V�ړ���</param>
/// <param name="type">�����`�[��</param>
void CWeapon::Shot(CVector2 position, CVector2 move, BulletTeamType type) {
    if ( 0 < m_ShotWait )
    {
        return;
    } // if
    m_ShotWait = CUtilities::GetFrameSecond() * 20;

    CBulletManager::Singleton().Fire(
        position,
        move,
        type);
}

void CWeapon::Update(void) {
    m_ShotWait -= CUtilities::GetFrameSecond();
    /*
    if (m_ShotWait <= 0) {
        m_ShotWait = 0;
    } // if
    */
}