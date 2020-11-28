#pragma once


#include <memory>

#include <Mof.h>

#include "AssetDefine.h"
#include "HP.h"
#include "Weapon.h"



#define			CHARACTER_SPEED			5

using namespace std;


struct CharacterInitParam
{
	Vector2 position;
	shared_ptr<CTexture> texture;
};
// ********************************************************************************
/// <summary>
/// �L�����N�^�[�N���X
/// </summary>
// ********************************************************************************
class CCharacter
{
protected:
	//! �ʒu
	CVector2 m_Position;
	//! �\���摜
	weak_ptr<CTexture> m_pTexture;
	//! HP
//	CHP m_HP;
	std::shared_ptr<CHP> m_pHP;
	//! ����
//	CWeapon m_Weapon;
	std::unique_ptr<CWeapon>m_pWeapon;
	//! �\����`
	CRectangle m_RenderRect;
public:
	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <created>�쑺,2020/11/28</created>
	/// <changed>�쑺,2020/11/28</changed>
	// ********************************************************************************
	CCharacter();
	virtual ~CCharacter();
	
	virtual Mof::CVector2 GetPosition(void) const;
	virtual const char* GetTeam(void) const = 0;

	virtual void Initialize(const CharacterInitParam& param);
	virtual void Update(void);
	virtual void Render(CVector2 scroll);
	virtual void Release(void);

	virtual CRectangle GetRectangle(void) const;

	virtual void CollisionBullet(void);
	virtual void CollisionEnemy(void);
};