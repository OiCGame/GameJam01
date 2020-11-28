#pragma once
#include "Mof.h"

class CCharacter;
class CBullet;

class CCollisionManager
{
private:

	std::vector<std::shared_ptr<CCharacter>> m_pCharaArray;

	std::vector<std::shared_ptr<CBullet>> m_pBulletArray;

	CCollisionManager(void);

public:

	~CCollisionManager(void);

	void Update(void);

	void Register(std::shared_ptr<CBullet> pBullet);

	void Register(std::shared_ptr<CCharacter> pCharacter);

	void Release(void);
};

