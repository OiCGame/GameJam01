#include "CollisionManager.h"
#include "Character.h"
#include "Player.h"
#include "BulletManager.h"

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
	for (auto& enemy : m_pEnemyArray)
	{
		// 敵と自分自身
		if (m_pPlayer->GetRectangle().CollisionRect(enemy->GetRectangle()))
		{
			m_pPlayer->CollisionEnemy();
		}

		for (auto& playerBullet : m_pPlayerBulletArray)
		{
			// 敵とプレイヤーの弾
			if (enemy->GetRectangle().CollisionRect(playerBullet->GetRectangle()))
			{
				enemy->CollisionBullet();
			}
		}
	}

	for (auto& enemyBullet : m_pEnemyBulletArray)
	{
		// 自分と敵の弾
		if (m_pPlayer->GetRectangle().CollisionRect(enemyBullet->GetRectangle()))
		{
			m_pPlayer->CollisionBullet();
		}
	}
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
	m_pEnemyArray.clear();
	m_pPlayerBulletArray.clear();
	m_pPlayerBulletArray.clear();
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
