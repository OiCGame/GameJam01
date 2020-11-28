#pragma once

#include "Character.h"
#include "GamePad.h"
#include "Weapon.h"
#include "HP.h"


class CPlayer : public CCharacter 
{
    using super = CCharacter;
private:
public:
    CPlayer();
    ~CPlayer();
    virtual void Update(void) override;
    virtual void Render(CVector2 scroll) override;
};