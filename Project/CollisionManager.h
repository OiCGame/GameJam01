#pragma once
#include "Mof.h"

class CCharacter;
class CPlayer;
class CBullet;
class CWeapomItem;

using namespace std;

// ********************************************************************************
/// <summary>
/// �����蔻��p���C���[
/// </summary>
// ********************************************************************************
enum class CollisionLayer
{
	Player,
	Enemy,
};

// ********************************************************************************
/// <summary>
/// �����蔻��Ǘ��N���X
/// </summary>
// ********************************************************************************
class CCollisionManager
{
private:
	shared_ptr<CPlayer>            m_pPlayer;             //! ��l��
	vector<shared_ptr<CCharacter>> m_pEnemyArray;         //! �G�L�����̔z��

	vector<shared_ptr<CBullet>>    m_pPlayerBulletArray;  //! �v���C���[�e�̔z��
	vector<shared_ptr<CBullet>>    m_pEnemyBulletArray;   //! �G�e�̔z��

//	vector<shared_ptr<CWeaponItem>>  m_pWeaponItemArray;   //! ��l���̕����ύX����A�C�e���̔z��
	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	CCollisionManager(void);
public:

	// ********************************************************************************
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	~CCollisionManager(void);

	// ********************************************************************************
	/// <summary>
	/// �X�V
	/// </summary>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void Update(void);

	// ********************************************************************************
	/// <summary>
	/// �o�^
	/// </summary>
	/// <param name="pBullet">�e</param>
	/// <param name="layer">���C��</param>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void Register(const shared_ptr<CBullet>& pBullet, const CollisionLayer& layer);

	// ********************************************************************************
	/// <summary>
	/// �o�^
	/// </summary>
	/// <param name="pCharacter">�L�����N�^</param>
	/// <param name="layer">���C��</param>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void Register(const shared_ptr<CCharacter>& pCharacter, const CollisionLayer& layer);
	// ********************************************************************************
	/// <summary>
	/// ���
	/// </summary>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void Release(void);

	// ********************************************************************************
	/// <summary>
	/// �V���O���g���̎擾
	/// </summary>
	/// <returns>�V���O���g��</returns>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	static CCollisionManager& Singleton(void);
};

#define g_CollisionManager CCollisionManager::Singleton()