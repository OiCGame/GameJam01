#pragma once


#include "Weapon.h"

#include <Mof.h>


/// <summary>
/// �A�˕���
/// </summary>
class CMachineGun : public CWeapon {
    using super = CWeapon;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CMachineGun();
    /// <summary>
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CMachineGun();
    /// <summary>
    /// Bullet����
    /// </summary>
    /// <param name="position">���ˈʒu</param>
    /// <param name="move">�X�V�ړ���</param>
    /// <param name="type">�����`�[��</param>
    void Shot(CVector2 position, CVector2 move, BulletTeamType type) override;
};