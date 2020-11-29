#pragma once


#include "Weapon.h"

#include <Mof.h>

/// <summary>
/// ３Way武器
/// </summary>
class CThreeWayGun : public CWeapon {
    using super = CWeapon;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CThreeWayGun();
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CThreeWayGun();
    /// <summary>
    /// Bullet発射
    /// </summary>
    /// <param name="position">発射位置</param>
    /// <param name="move">更新移動量</param>
    /// <param name="type">所属チーム</param>
    void Shot(CVector2 position, BulletTeamType type, BulletType bt, TextureKey key) override;
};