#pragma once

#include "Character.h"
#include "GamePad.h"
#include "Weapon.h"
#include "HP.h"


class CPlayer : public CCharacter 
{
    using super = CCharacter;
private:
    uint32_t m_Invincible;
public:
    CPlayer();
    ~CPlayer();

    virtual CRectangle GetRectangle(void) const override;

    virtual void Initialize(const CharacterInitParam& param) override;
    virtual void Update(void) override;
    virtual void Render(CVector2 scroll) override;

    virtual void CollisionBullet(void) override;
    virtual void CollisionEnemy(void) override;
};