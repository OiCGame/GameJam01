#pragma once


#include "Bullet.h"

#include "Character.h"


/// <summary>
/// �u�[�������̒e�@�ˏo���苗���i�ނƌ������l�ɖ߂��Ă���
/// </summary>
class CHomingBullet : public CBullet {
	using super = CBullet;
private:
	//! �߂��
	std::weak_ptr<CCharacter>m_pTarget;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CHomingBullet();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CHomingBullet();
	/// <summary>
	/// �X�V
	/// </summary>
	virtual void Update(void);
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="position">���ˈʒu</param>
	/// <param name="move">�X�V�ړ���</param>
	/// <param name="type">�����`�[��</param>
	virtual void Fire(CVector2 position, CVector2 move, BulletTeamType type);
};