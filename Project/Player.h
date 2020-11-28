#pragma once

#include "Character.h"
#include "GamePad.h"
#include "Weapon.h"
#include "HP.h"


class CPlayer : public CCharacter
{
private:
public:
	CPlayer();
	~CPlayer();
	virtual void Update(CVector2 scroll) override;
};