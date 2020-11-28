#pragma once


#include "Character.h"

#include <memory>

using namespace std;

/// <summary>
/// �G�l�~�[
/// </summary>
class CEnemy : public CCharacter 
{
    using super = CCharacter;
private:
    //! �W�I
    weak_ptr<class CPlayer> m_pTarget;
    //! �ړ���
    CVector2 m_Move;
    //! �x�W�G�Ȑ��ɂ��A�j���[�V�����̎���
    float m_Time = 0.0f;
    //! �g�X�ړ�������Ƃ��̊p�x
    float m_WaveAngle = 0.0f;
    //! �U�����͕p�x
    float m_AttackTime = 0.0f;
    const float m_AttackTimeMax = 0.4f;

    /// <summary>
    /// �^�[�Q�b�g��ǐՂ���ړ��ʂ̎擾
    /// </summary>
    /// <returns>�ړ���</returns>
    CVector2 MoveChase(void);
    /// <summary>
    /// �g�X�ړ�
    /// </summary>
    /// <returns>�ړ���</returns>
    CVector2  WaveMove(void);


    /// <summary>
    /// �U���X�V
    /// </summary>
    void UpdateAttack(void);
    /// <summary>
    /// �ړ�
    /// </summary>
    void UpdateMove(void);
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CEnemy();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CEnemy();

    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="ptr">�|�C���^</param>
    void SetTarget(std::shared_ptr<class CPlayer> ptr);

    /// <summary>
    /// �X�V
    /// </summary>
    virtual void Update(void) override;
};