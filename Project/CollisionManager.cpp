#include "CollisionManager.h"
#include "Character.h"
#include "Player.h"
#include "WeaponItem.h"
#include "BulletManager.h"
#include "WeaponItemManager.h"


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
	// ���S�G�l�~�[���폜
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
		// �G�Ǝ������g
		if (m_pPlayer && m_pPlayer->GetRectangle().CollisionRect(enemy->GetRectangle()))
		{
			if (!m_pPlayer->IsDamage())
			{
				m_pPlayer->CollisionEnemy();
			}
		}

		for (auto& playerBullet : m_pPlayerBulletArray)
		{
			// �G�ƃv���C���[�̒e
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
		// �����ƓG�̒e
		if (m_pPlayer->GetRectangle().CollisionRect(enemyBullet->GetRectangle()))
		{
			if (!m_pPlayer->IsDamage())
			{
				m_pPlayer->CollisionBullet();
				enemyBullet->Hide();
			}
		}
	}

	// �A�C�e���Ƃ̏Փ˔���
	for (auto item : CWeaponItemManager::Singleton().GetArray()) {
		auto rect = item->GetRectangle();
		if (m_pPlayer->GetRectangle().CollisionRect(rect)) {
			m_pPlayer->ChangeWeapon(item->GetWeaponType());
			item->Use();
		} // if
	} // for
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
