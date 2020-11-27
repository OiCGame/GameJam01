#include "Character.h"

CCharacter::CCharacter() :
	m_Position(),
	m_pTexture()
{
}

CCharacter::~CCharacter()
{
}

void CCharacter::Initialize(const CharacterInitParam& param)
{

	m_Position = param.position;
	m_pTexture = param.texture;
}

void CCharacter::Update(void)
{
}

void CCharacter::Render(CVector2 scroll)
{
	if (auto r = m_pTexture.lock())
	{
		r->Render(scroll.x, scroll.y);
	} // if
}

void CCharacter::Release(void)
{
	m_pTexture.reset();
}
