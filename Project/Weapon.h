#pragma once


#include <Mof.h>


/// <summary>
/// ����
/// </summary>
class CWeapon
{
private:
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
    ~CWeapon();
    /// <summary>
    /// Bullet����
    /// </summary>
    /// <param name="move">Bullet�̈ʒu�̍X�V�l</param>
    void Shot(CVector2 move);
};