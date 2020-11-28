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
/// <param name="position">発射位置</param>
/// <param name="move">更新移動量</param>
/// <param name="type">所属チーム</param>
void CWeapon::Shot(CVector2 position, CVector2 move, BulletTeamType type) {
    CBulletManager::Singleton().Fire(
        position,
        move,
        type);
}