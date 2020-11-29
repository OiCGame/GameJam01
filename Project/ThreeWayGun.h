#pragma once


#include "Weapon.h"

#include <Mof.h>

/// <summary>
/// �RWay����
/// </summary>
class CThreeWayGun : public CWeapon {
    using super = CWeapon;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CThreeWayGun();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CThreeWayGun();
    /// <summary>
    /// Bullet����
    /// </summary>
    /// <param name="position">���ˈʒu</param>
    /// <param name="move">�X�V�ړ���</param>
    /// <param name="type">�����`�[��</param>
    void Shot(CVector2 position, BulletTeamType type, BulletType bt, TextureKey key) override;
};