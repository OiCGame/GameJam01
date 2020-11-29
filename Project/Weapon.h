#pragma once


#include <Mof.h>


#include "Bullet.h"


enum class TextureKey;
enum class BulletType;

/// <summary>
/// 武器
/// </summary>
class CWeapon
{
protected:
    //! 所有者
//    class CCharacter* m_pOwner;
    //! インターバル
    float m_ShotWait;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CWeapon();
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="ptr">所有者</param>
//    CWeapon(class CCharacter* ptr);
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~CWeapon();
    /// <summary>
    /// 撃つことができるか
    /// </summary>
    /// <returns>できるならばtrueを返す</returns>
//    virtual bool CanShot(void) const;
    /// <summary>
    /// Bullet発射
    /// </summary>
    /// <param name="position">発射位置</param>
    /// <param name="move">更新移動量</param>
    /// <param name="type">所属チーム</param>
    virtual void Shot(CVector2 position, CVector2 move, BulletTeamType type, BulletType bt, TextureKey key);
    /// <summary>
    /// m_ShotWaitの更新
    /// </summary>
    virtual void Update(void);
};