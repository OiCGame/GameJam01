#pragma once

#include "Character.h"
#include "GamePad.h"
#include "Weapon.h"
#include "HP.h"


class CPlayer : public CCharacter 
{
    using super = CCharacter;
private:
//    int m_Invincible;
public:
    CPlayer();
    ~CPlayer();

    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <returns>CollisionRect</returns>
    virtual CRectangle GetRectangle(void) const override;
    /// <summary>
    /// �`�[���擾
    /// </summary>
    /// <returns>�`�[��</returns>
    virtual const char* GetTeam(void) const override;

    /// <summary>
    /// ���G��
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
//    bool IsInvincible(void) const;

    virtual void Initialize(const CharacterInitParam& param) override;
    virtual void Update(void) override;
    virtual void Render(CVector2 scroll) override;

    virtual void CollisionBullet(void) override;
    virtual void CollisionEnemy(void) override;
};