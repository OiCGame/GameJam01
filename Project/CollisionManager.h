#pragma once
#include "Mof.h"

class CCharacter;
class CPlayer;
class CBullet;

using namespace std;

enum class CollisionLayer
{
	Player,
	Enemy,
};

class CCollisionManager
{
private:

	shared_ptr<CPlayer>            m_pPlayer;
	vector<shared_ptr<CCharacter>> m_pEnemyArray;

	vector<shared_ptr<CBullet>>    m_pPlayerBulletArray;
	vector<shared_ptr<CBullet>>    m_pEnemyBulletArray;

	CCollisionManager(void);

public:

	~CCollisionManager(void);

	void Update(void);

	void Register(const shared_ptr<CBullet>& pBullet, const CollisionLayer& layer);

	void Register(const shared_ptr<CCharacter>& pCharacter, const CollisionLayer& layer);

	void Release(void);

	static CCollisionManager& Singleton(void);
};

