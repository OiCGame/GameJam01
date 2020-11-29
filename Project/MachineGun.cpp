#include "MachineGun.h"

#include "BulletManager.h"


/// <summary>
/// コンストラクタ
/// </summary>
CMachineGun::CMachineGun() :
super(){
}

/// <summary>
/// デストラクタ
/// </summary>
CMachineGun::~CMachineGun() {
}

/// <summary>
/// Bullet発射
/// </summary>
/// <param name="position">発射位置</param>
/// <param name="move">更新移動量</param>
/// <param name="type">所属チーム</param>
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