#include "CollisionManager.h"
#include "Character.h"
#include "Player.h"
#include "BulletManager.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
CCollisionManager::CCollisionManager(void)
{
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
CCollisionManager::~CCollisionManager(void)
{
}

// ********************************************************************************
/// <summary>
/// �X�V
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CCollisionManager::Update(void)
{
	for (auto& enemy : m_pEnemyArray)
	{
		// �G�Ǝ������g
		if (m_pPlayer->GetRectangle().CollisionRect(enemy->GetRectangle()))
		{
			m_pPlayer->CollisionEnemy();
		}

		for (auto& playerBullet : m_pPlayerBulletArray)
		{
			// �G�ƃv���C���[�̒e
			if (enemy->GetRectangle().CollisionRect(playerBullet->GetRectangle()))
			{
				enemy->CollisionBullet();
			}
		}
	}

	for (auto& enemyBullet : m_pEnemyBulletArray)
	{
		// �����ƓG�̒e
		if (m_pPlayer->GetRectangle().CollisionRect(enemyBullet->GetRectangle()))
		{
			m_pPlayer->CollisionBullet();
		}
	}
}

// ********************************************************************************
/// <summary>
/// �o�^
/// </summary>
/// <param name="pBullet">�e</param>
/// <param name="layer">���C��</param>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
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
/// �o�^
/// </summary>
/// <param name="pCharacter">�L�����N�^</param>
/// <param name="layer">���C��</param>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
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
/// ���
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CCollisionManager::Release(void)
{
	m_pEnemyArray.clear();
	m_pPlayerBulletArray.clear();
	m_pPlayerBulletArray.clear();
}

// ********************************************************************************
/// <summary>
/// �V���O���g���̎擾
/// </summary>
/// <returns>�V���O���g��</returns>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
CCollisionManager & CCollisionManager::Singleton(void)
{
	static CCollisionManager singleton;
	return singleton;
}
