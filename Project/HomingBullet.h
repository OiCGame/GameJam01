#pragma once


#include "Bullet.h"

#include "Character.h"


/// <summary>
/// ブーメランの弾　射出後一定距離進むと撃った人に戻っていく
/// </summary>
class CHomingBullet : public CBullet {
	using super = CBullet;
private:
	//! 戻り先
	std::weak_ptr<CCharacter>m_pTarget;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CHomingBullet();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CHomingBullet();
	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update(void);
	/// <summary>
	/// 発射
	/// </summary>
	/// <param name="position">発射位置</param>
	/// <param name="move">更新移動量</param>
	/// <param name="type">所属チーム</param>
	virtual void Fire(CVector2 position, CVector2 move, BulletTeamType type);
};