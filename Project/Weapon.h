#pragma once


#include <Mof.h>


#include "Bullet.h"


/// <summary>
/// 武器
/// </summary>
class CWeapon
{
protected:
    //! 所有者
    class Character* m_pOwner;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CWeapon();
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="ptr">所有者</param>
    CWeapon(class Character* ptr);
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~CWeapon();
    /// <summary>
    /// Bullet発射
    /// </summary>
    /// <param name="position">発射位置</param>
    /// <param name="move">更新移動量</param>
    /// <param name="type">所属チーム</param>
    virtual void Shot(CVector2 position, CVector2 move, BulletTeamType type);
};