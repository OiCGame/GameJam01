#pragma once


#include <Mof.h>


/// <summary>
/// 武器
/// </summary>
class CWeapon
{
private:
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
    ~CWeapon();
    /// <summary>
    /// Bullet発射
    /// </summary>
    /// <param name="move">Bulletの位置の更新値</param>
    void Shot(CVector2 move);
};