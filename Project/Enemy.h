#pragma once


#include "Character.h"

/// <summary>
/// �G�l�~�[
/// </summary>
class CEnemy : public CCharacter 
{
    using super = CCharacter;
private:
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
    /// �X�V
    /// </summary>
    virtual void Update(void) override;
};