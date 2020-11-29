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
	CEaseMotionController<Vector2> m_MoveMotion;
	bool                           m_bTargetMove;

    /// <summary>
    /// 攻撃更新
    /// </summary>
    void UpdateAttack(void);
    /// <summary>
    /// 移動
    /// </summary>
    void UpdateMove(void);

	void InitMoveMotionDefault(void);
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


    virtual void CollisionBullet(void) override;
    virtual void CollisionEnemy(void) override;
};