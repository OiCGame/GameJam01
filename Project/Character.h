#pragma once


#include <memory>

#include <Mof.h>

#include "AssetDefine.h"


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
	CVector2 m_Position;
	weak_ptr<CTexture> m_pTexture;
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
	
	virtual void Initialize(const CharacterInitParam& param);
	virtual void Update(void);
	virtual void Render(CVector2 scroll);
	virtual void Release(void);
};