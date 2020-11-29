#include "CollisionManager.h"
#include "Character.h"
#include "Player.h"
#include "WeaponItem.h"
#include "BulletManager.h"
#include "WeaponItemManager.h"


// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
CCollisionManager::CCollisionManager(void)
{
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
CCollisionManager::~CCollisionManager(void)
{
}

// ********************************************************************************
/// <summary>
/// 更新
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CCollisionManager::Update(void)
{
	// 死亡エネミーを削除
	m_pEnemyArray.erase(std::remove_if(
		m_pEnemyArray.begin(),
		m_pEnemyArray.end(),
		[](shared_ptr<CCharacter> enemy) {
		return !enemy->IsShow();
	}), m_pEnemyArray.end());
	m_pPlayerBulletArray.erase(std::remove_if(
		m_pPlayerBulletArray.begin(),
		m_pPlayerBulletArray.end(),
		[](shared_ptr<CBullet> bullet) {
		return !bullet->IsShow();
	}), m_pPlayerBulletArray.end());
	m_pEnemyBulletArray.erase(std::remove_if(
		m_pEnemyBulletArray.begin(),
		m_pEnemyBulletArray.end(),
		[](shared_ptr<CBullet> bullet) {
		return !bullet->IsShow();
	}), m_pEnemyBulletArray.end());
	if (!m_pPlayer) {
		m_pPlayer.reset();
	} // if
	MOF_PRINTLOG("CollisionManager m_pEnemyArray size = %d \n", m_pEnemyArray.size());
	MOF_PRINTLOG("CollisionManager m_pPlayerBulletArray size = %d \n", m_pPlayerBulletArray.size());
	MOF_PRINTLOG("CollisionManager m_pEnemyBulletArray size = %d \n", m_pEnemyBulletArray.size());
	

	for (auto& enemy : m_pEnemyArray)
	{
		// 敵と自分自身
		if (m_pPlayer && m_pPlayer->GetRectangle().CollisionRect(enemy->GetRectangle()))
		{
			if (m_pPlayer->IsGimmick())
			{
				enemy->CollisionEnemy();
			}
			else if (!m_pPlayer->IsDamage())
			{
				m_pPlayer->CollisionEnemy();
			}
		}

		for (auto& playerBullet : m_pPlayerBulletArray)
		{
			// 敵とプレイヤーの弾
			if (enemy->GetRectangle().CollisionRect(playerBullet->GetRectangle()))
			{
				enemy->CollisionBullet();
				playerBullet->Hide();
			}
		}
	}

	for (auto& enemyBullet : m_pEnemyBulletArray)
	{
		if (!m_pPlayer) {
			break;
		} // if
		if (m_pPlayer->IsGimmick())
		{
			enemyBullet->Hide();
		}
		// 自分と敵の弾
		else if (m_pPlayer->GetRectangle().CollisionRect(enemyBullet->GetRectangle()))
		{
			if (!m_pPlayer->IsDamage())
			{
				m_pPlayer->CollisionBullet();
				enemyBullet->Hide();
			}
		}
	}

	// アイテムとの衝突判定
	for (auto item : CWeaponItemManager::Singleton().GetArray()) {
		if (m_pPlayer->IsGimmick()) {
			break;
		} // if
		auto rect = item->GetRectangle();
		if (m_pPlayer->GetRectangle().CollisionRect(rect)) {
			m_pPlayer->ChangeWeapon(item->GetWeaponType());
			item->Use();
		} // if
	} // for
}

// ********************************************************************************
/// <summary>
/// 登録
/// </summary>
/// <param name="pBullet">弾</param>
/// <param name="layer">レイヤ</param>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CCollisionManager::Register(const shared_ptr<CBullet>& pBullet, const CollisionLayer& layer)
{
	switch (layer)
	{
	case CollisionLayer::Player:
		m_pPlayerBulletArray.push_back(pBullet);
		break;
	case CollisionLayer::Enemy:
		m_pEnemyBulletArray.push_back(pBullet);
		break;
	}
}

// ********************************************************************************
/// <summary>
/// 登録
/// </summary>
/// <param name="pCharacter">キャラクタ</param>
/// <param name="layer">レイヤ</param>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CCollisionManager::Register(const shared_ptr<CCharacter>& pCharacter, const CollisionLayer& layer)
{
	switch (layer)
	{
	case CollisionLayer::Player:
		m_pPlayer = dynamic_pointer_cast<CPlayer>(pCharacter);
		break;
	case CollisionLayer::Enemy:
		m_pEnemyArray.push_back(pCharacter);
		break;
	}
}

// ********************************************************************************
/// <summary>
/// 解放
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CCollisionManager::Release(void)
{
	// enemy
	for (auto chara : m_pEnemyArray) {
		chara.reset();
	} // for
	m_pEnemyArray.clear();
	// enemy bullet
	for (auto bullet : m_pPlayerBulletArray) {
		bullet.reset();
	} // for
	m_pPlayerBulletArray.clear();
	// player bullet
	for (auto bullet: m_pEnemyBulletArray) {
		bullet.reset();
	} // for
	m_pEnemyBulletArray.clear();
}

// ********************************************************************************
/// <summary>
/// シングルトンの取得
/// </summary>
/// <returns>シングルトン</returns>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
CCollisionManager & CCollisionManager::Singleton(void)
{
	static CCollisionManager singleton;
	return singleton;
}
