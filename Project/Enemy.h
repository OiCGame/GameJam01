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
    //! ベジエ曲線によるアニメーションの時間
    float m_Time = 0.0f;
    //! 波々移動をするときの角度
    float m_WaveAngle = 0.0f;
    //! 攻撃入力頻度
    float m_AttackTime = 0.0f;
    const float m_AttackTimeMax = 0.4f;

    /// <summary>
    /// ターゲットを追跡する移動量の取得
    /// </summary>
    /// <returns>移動量</returns>
    CVector2 MoveChase(void);
    /// <summary>
    /// 波々移動
    /// </summary>
    /// <returns>移動量</returns>
    CVector2  WaveMove(void);


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