#pragma once


#include <Mof.h>


#include "Bullet.h"


/// <summary>
/// ����
/// </summary>
class CWeapon
{
protected:
    //! ���L��
    class Character* m_pOwner;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CWeapon();
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="ptr">���L��</param>
    CWeapon(class Character* ptr);
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~CWeapon();
    /// <summary>
    /// Bullet����
    /// </summary>
    /// <param name="position">���ˈʒu</param>
    /// <param name="move">�X�V�ړ���</param>
    /// <param name="type">�����`�[��</param>
    virtual void Shot(CVector2 position, CVector2 move, BulletTeamType type);
};