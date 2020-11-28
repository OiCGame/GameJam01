#include "Weapon.h"

#include "BulletManager.h"
#include "Character.h"


/// <summary>
/// コンストラクタ
/// </summary>
CWeapon::CWeapon() :
    m_pOwner(nullptr){
}

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="ptr">所有者</param>
CWeapon::CWeapon(Character* ptr) :
    m_pOwner(ptr){
}

/// <summary>
/// デストラクタ
/// </summary>
CWeapon::~CWeapon() {
}

/// <summary>
/// Bullet発射
/// </summary>
/// <param name="move">Bulletの位置の更新値</param>
void CWeapon::Shot(CVector2 move) {
    /*
    CBulletManager::Singleton().Fire(
        m_pOwner->GetPosition(),
        move,
        m_pOwner->GetTeamType());
    */
}