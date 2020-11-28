#pragma once


#include "Character.h"

#include <memory>

using namespace std;

/// <summary>
/// エネミー
/// </summary>
class CEnemy : public CCharacter 
{
    using super = CCharacter;
private:
    //! 標的
    weak_ptr<class CPlayer> m_pTarget;
    //! 移動量
    CVector2 m_Move;
    

    float _time = 0.0f;


    /// <summary>
    /// ターゲットを追跡する移動量の取得
    /// </summary>
    /// <returns>移動量</returns>
    CVector2 MoveChase(void);



    /// <summary>
    /// 攻撃更新
    /// </summary>
    void UpdateAttack(void);
    /// <summary>
    /// 移動
    /// </summary>
    void UpdateMove(void);
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
    /// セッター
    /// </summary>
    /// <param name="ptr">ポインタ</param>
    void SetTarget(std::shared_ptr<class CPlayer> ptr);

    /// <summary>
    /// 更新
    /// </summary>
    virtual void Update(void) override;
};