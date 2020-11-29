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
	//! �\�������Bullet�́@
	const uint32_t m_BulletSize;
	// �Ǘ��Ώ�
	std::vector<std::shared_ptr<CBullet>>m_Bullets;
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CBulletManager();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CBulletManager();
public:
	/// <summary>
	/// �V���O���g��
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static CBulletManager& Singleton(void);
	/// <summary>
	/// ������
	/// </summary>
	/// <returns>����������tue��Ԃ�</returns>
	bool Initialize(void);
	/// <summary>
	/// �X�V
	/// </summary>
	void Update(void);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="scroll">�X�N���[���l</param>
	void Render(CVector2 scroll);
	/// <summary>
	/// ���
	/// </summary>
	void Release(void);
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="position">���ˈʒu</param>
	/// <param name="move">�ړ���</param>
	/// <param name="type">Bullet�̏����`�[��</param>
	void Fire(CVector2 position, CVector2 move, BulletTeamType type, BulletType bt, TextureKey key);

	/// <summary>
	/// Bullet�̒ǉ��@Weapon����Ă΂�邱�Ƃ�z��
	/// </summary>
	/// <param name="type">�|�C���^</param>
	void AddBullet(std::shared_ptr<CBullet> ptr);
};

