#pragma once


#include <vector>
#include <memory>

#include "Bullet.h"

enum class TextureKey;

enum class BulletType
{
	Boomerang,
	Default,
	Homing,
};


class CBulletManager
{
private:
	//! 表示されるBulletの　
	const uint32_t m_BulletSize;
	// 管理対象
	std::vector<std::shared_ptr<CBullet>>m_Bullets;
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CBulletManager();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CBulletManager();
public:
	/// <summary>
	/// シングルトン
	/// </summary>
	/// <returns>インスタンス</returns>
	static CBulletManager& Singleton(void);
	/// <summary>
	/// 初期化
	/// </summary>
	/// <returns>成功したらtueを返す</returns>
	bool Initialize(void);
	/// <summary>
	/// 更新
	/// </summary>
	void Update(void);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="scroll">スクロール値</param>
	void Render(CVector2 scroll);
	/// <summary>
	/// 解放
	/// </summary>
	void Release(void);
	/// <summary>
	/// 発射
	/// </summary>
	/// <param name="position">発射位置</param>
	/// <param name="move">移動量</param>
	/// <param name="type">Bulletの所属チーム</param>
	void Fire(CVector2 position, CVector2 move, BulletTeamType type, BulletType bt, TextureKey key);

	/// <summary>
	/// Bulletの追加　Weaponから呼ばれることを想定
	/// </summary>
	/// <param name="type">ポインタ</param>
	void AddBullet(std::shared_ptr<CBullet> ptr);
};

