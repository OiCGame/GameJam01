#pragma once


#include "Character.h"

#include <memory>

#include "EaseMotionController.h"

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
    //! 攻撃入力頻度
    float m_AttackTime = 0.0f;
    const float m_AttackTimeMax = 0.4f;

	CEaseMotionController<Vector2> m_MoveMotion;

    /// <summary>
    /// 攻撃更新
    /// </summary>
    void UpdateAttack(void);
    /// <summary>
    /// 移動
    /// </summary>
    void UpdateMove(void);

	void InitMoveMotionWave(void);
	void InitMoveMotionChase(void);
	void InitMoveMotionCustom(void);

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
    /// チーム取得
    /// </summary>
    /// <returns>チーム</returns>
    virtual const char* GetTeam(void) const override;
    /// <summary>
    /// 初期化
    /// </summary>
    /// <param name="param">初期化値</param>
    virtual void Initialize(const CharacterInitParam& param) override;
    /// <summary>
    /// 更新
    /// </summary>
    virtual void Update(void) override;
    /// <summary>
    /// 描画
    /// </summary>
    /// <param name="scroll">スクロール値</param>
    virtual void Render(CVector2 scroll) override;
};