#pragma once

#include "Character.h"
#include "GamePad.h"
#include "Weapon.h"

class CPlayer : public CCharacter
{
private:
	CWeapon m_Weapon;
public:
	CPlayer();
	~CPlayer();
	virtual void Update(void) override;
};

