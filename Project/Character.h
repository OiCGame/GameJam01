#pragma once


#include <memory>

#include <Mof.h>

#include "AssetDefine.h"

#define			CHARACTER_SPEED			5

using namespace std;


struct CharacterInitParam
{
	Vector2 position;
	shared_ptr<CTexture> texture;
};
// ********************************************************************************
/// <summary>
/// キャラクタークラス
/// </summary>
// ********************************************************************************
class CCharacter
{
protected:
	CVector2 m_Position;
	weak_ptr<CTexture> m_pTexture;
public:
	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <created>川村,2020/11/28</created>
	/// <changed>川村,2020/11/28</changed>
	// ********************************************************************************
	CCharacter();
	virtual ~CCharacter();
	
	virtual void Initialize(const CharacterInitParam& param);
	virtual void Update(void);
	virtual void Render(CVector2 scroll);
	virtual void Release(void);

	virtual CRectangle GetRectangle(void) const;

	virtual void CollisionBullet(void);
	virtual void CollisionEnemy(void);
};