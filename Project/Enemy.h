#pragma once


#include "Character.h"

/// <summary>
/// エネミー
/// </summary>
class CEnemy : public CCharacter 
{
    using super = CCharacter;
private:
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CEnemy();
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CEnemy();

    /// <summary>
    /// 更新
    /// </summary>
    virtual void Update(void) override;
};