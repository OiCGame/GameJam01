#pragma once


#include <Mof.h>


#include "Bullet.h"


enum class TextureKey;
enum class BulletType;

/// <summary>
/// ����
/// </summary>
class CWeapon
{
protected:
    //! ���L��
//    class CCharacter* m_pOwner;
    //! �C���^�[�o��
    float m_ShotWait;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CWeapon();
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="ptr">���L��</param>
//    CWeapon(class CCharacter* ptr);
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~CWeapon();
    /// <summary>
    /// �����Ƃ��ł��邩
    /// </summary>
    /// <returns>�ł���Ȃ��true��Ԃ�</returns>
//    virtual bool CanShot(void) const;
    /// <summary>
    /// Bullet����
    /// </summary>
    /// <param name="position">���ˈʒu</param>
    /// <param name="move">�X�V�ړ���</param>
    /// <param name="type">�����`�[��</param>
    virtual void Shot(CVector2 position, CVector2 move, BulletTeamType type, BulletType bt, TextureKey key);
    /// <summary>
    /// m_ShotWait�̍X�V
    /// </summary>
    virtual void Update(void);
};