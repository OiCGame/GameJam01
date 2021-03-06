#pragma once


#include "Bullet.h"

#include "Character.h"


/// <summary>
/// ブーメランの弾　射出後一定距離進むと撃った人に戻っていく
/// </summary>
class CBoomerangBullet : public CBullet {
	using super = CBullet;
private:
    //! 発射されてから移動した距離
    float m_MovedDistance;
    //! 戻り（折り返し）始める距離
    const float m_ReturnLength;
	//! 折り返す
	bool m_bReturn;
	//! 折り返す先
	weak_ptr<CCharacter>m_pHome;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CBoomerangBullet();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CBoomerangBullet();
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