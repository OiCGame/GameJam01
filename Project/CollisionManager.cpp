#include "CollisionManager.h"
#include "Character.h"
#include "Player.h"
#include "BulletManager.h"

CCollisionManager::CCollisionManager(void)
{
}

CCollisionManager::~CCollisionManager(void)
{
}

void CCollisionManager::Update(void)
{
	for (auto& enemy : m_pEnemyArray)
	{
		// “G‚ÆŽ©•ªŽ©g
		if (m_pPlayer->GetRectangle().CollisionRect(enemy->GetRectangle()))
		{
			m_pPlayer->CollisionEnemy();
		}

		for (auto& playerBullet : m_pPlayerBulletArray)
		{
			// “G‚ÆƒvƒŒƒCƒ„[‚Ì’e
			if (enemy->GetRectangle().CollisionRect(playerBullet->GetRectangle()))
			{
				enemy->CollisionBullet();
			}
		}
	}

	for (auto& enemyBullet : m_pEnemyBulletArray)
	{
		// Ž©•ª‚Æ“G‚Ì’e
		if (m_pPlayer->GetRectangle().CollisionRect(enemyBullet->GetRectangle()))
		{
			m_pPlayer->CollisionBullet();
		}
	}
}

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

void CCollisionManager::Release(void)
{
	m_pEnemyArray.clear();
	m_pPlayerBulletArray.clear();
	m_pPlayerBulletArray.clear();
}

CCollisionManager & CCollisionManager::Singleton(void)
{
	static CCollisionManager singleton;
	return singleton;
}
