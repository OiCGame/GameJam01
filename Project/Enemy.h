#pragma once


#include "Character.h"

#include <memory>

#include "EaseMotionController.h"

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
	CEaseMotionController<Vector2> m_MoveMotion;
	bool                           m_bTargetMove;

    /// <summary>
    /// �U���X�V
    /// </summary>
    void UpdateAttack(void);
    /// <summary>
    /// �ړ�
    /// </summary>
    void UpdateMove(void);

	void InitMoveMotionDefault(void);
	void InitMoveMotionWave(void);
	void InitMoveMotionChase(void);
	void InitMoveMotionCustom(void);
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
    /// �`�[���擾
    /// </summary>
    /// <returns>�`�[��</returns>
    virtual const char* GetTeam(void) const override;
    /// <summary>
    /// ������
    /// </summary>
    /// <param name="param">�������l</param>
    virtual void Initialize(const CharacterInitParam& param) override;
    /// <summary>
    /// �X�V
    /// </summary>
    virtual void Update(void) override;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="scroll">�X�N���[���l</param>
    virtual void Render(CVector2 scroll) override;


    virtual void CollisionBullet(void) override;
    virtual void CollisionEnemy(void) override;
};