#pragma once


#include "Weapon.h"

#include <Mof.h>


/// <summary>
/// 連射武器
/// </summary>
class CMachineGun : public CWeapon {
    using super = CWeapon;

    virtual CVector2 GetShowPower(void) override;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CMachineGun();
    /// <summary>
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CMachineGun();
    /// <summary>
    /// Bullet発射
    /// </summary>
    /// <param name="position">発射位置</param>
    /// <param name="move">更新移動量</param>
    /// <param name="type">所属チーム</param>
    void Shot(CVector2 position, BulletTeamType type, BulletType bt, TextureKey key) override;
};