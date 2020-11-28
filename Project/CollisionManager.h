#pragma once
#include "Mof.h"

class CCharacter;

class CCollisionManager
{
private:

	std::vector<CCharacter*> m_pCharaArray;


	CCollisionManager(void);

public:

	~CCollisionManager(void);

};

