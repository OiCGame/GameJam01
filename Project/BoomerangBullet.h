#pragma once


#include "Bullet.h"

#include "Character.h"


/// <summary>
/// �u�[�������̒e�@�ˏo���苗���i�ނƌ������l�ɖ߂��Ă���
/// </summary>
class CBoomerangBullet : public CBullet {
	using super = CBullet;
private:
    //! ���˂���Ă���ړ���������
    float m_MovedDistance;
    //! �߂�i�܂�Ԃ��j�n�߂鋗��
    const float m_ReturnLength;
	//! �܂�Ԃ�
	bool m_bReturn;
	//! �܂�Ԃ���
	weak_ptr<CCharacter>m_pHome;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CBoomerangBullet();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CBoomerangBullet();
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