#pragma once
#include "Mof.h"

class CCharacter;
class CPlayer;
class CBullet;
class CWeapomItem;

using namespace std;

// ********************************************************************************
/// <summary>
/// 当たり判定用レイヤー
/// </summary>
// ********************************************************************************
enum class CollisionLayer
{
	Player,
	Enemy,
};

// ********************************************************************************
/// <summary>
/// 当たり判定管理クラス
/// </summary>
// ********************************************************************************
class CCollisionManager
{
private:
	shared_ptr<CPlayer>            m_pPlayer;             //! 主人公
	vector<shared_ptr<CCharacter>> m_pEnemyArray;         //! 敵キャラの配列

	vector<shared_ptr<CBullet>>    m_pPlayerBulletArray;  //! プレイヤー弾の配列
	vector<shared_ptr<CBullet>>    m_pEnemyBulletArray;   //! 敵弾の配列

//	vector<shared_ptr<CWeaponItem>>  m_pWeaponItemArray;   //! 主人公の武器を変更するアイテムの配列
	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <created>いのうえ,2020/11/28</created>
	/// <changed>いのうえ,2020/11/28</changed>
	// ********************************************************************************
	CCollisionManager(void);
public:

	// ********************************************************************************
	/// <summary>
	/// デストラクタ
	/// </summary>
	/// <created>いのうえ,2020/11/28</created>
	/// <changed>いのうえ,2020/11/28</changed>
	// ********************************************************************************
	~CCollisionManager(void);

	// ********************************************************************************
	/// <summary>
	/// 更新
	/// </summary>
	/// <created>いのうえ,2020/11/28</created>
	/// <changed>いのうえ,2020/11/28</changed>
	// ********************************************************************************
	void Update(void);

	// ********************************************************************************
	/// <summary>
	/// 登録
	/// </summary>
	/// <param name="pBullet">弾</param>
	/// <param name="layer">レイヤ</param>
	/// <created>いのうえ,2020/11/28</created>
	/// <changed>いのうえ,2020/11/28</changed>
	// ********************************************************************************
	void Register(const shared_ptr<CBullet>& pBullet, const CollisionLayer& layer);

	// ********************************************************************************
	/// <summary>
	/// 登録
	/// </summary>
	/// <param name="pCharacter">キャラクタ</param>
	/// <param name="layer">レイヤ</param>
	/// <created>いのうえ,2020/11/28</created>
	/// <changed>いのうえ,2020/11/28</changed>
	// ********************************************************************************
	void Register(const shared_ptr<CCharacter>& pCharacter, const CollisionLayer& layer);
	// ********************************************************************************
	/// <summary>
	/// 解放
	/// </summary>
	/// <created>いのうえ,2020/11/28</created>
	/// <changed>いのうえ,2020/11/28</changed>
	// ********************************************************************************
	void Release(void);

	// ********************************************************************************
	/// <summary>
	/// シングルトンの取得
	/// </summary>
	/// <returns>シングルトン</returns>
	/// <created>いのうえ,2020/11/28</created>
	/// <changed>いのうえ,2020/11/28</changed>
	// ********************************************************************************
	static CCollisionManager& Singleton(void);
};

#define g_CollisionManager CCollisionManager::Singleton()