#include "Character.h"
#include "GamePad.h"
#include "BulletManager.h"

CCharacter::CCharacter() :
	m_Position(),
	m_pTexture(),
	m_pHP(std::make_shared<CHP>()){
}

CCharacter::~CCharacter()
{
}

Mof::CVector2 CCharacter::GetPosition(void) const {
	return this->m_Position;
}

void CCharacter::Initialize(const CharacterInitParam& param)
{
	m_Position = param.position;
	m_pTexture = param.texture;
}

void CCharacter::Update(CVector2 scroll)
{
}

void CCharacter::Render(CVector2 scroll)
{
	if (auto r = m_pTexture.lock())
	{
		r->Render(m_Position.x + scroll.x, m_Position.y + scroll.y);
	} // if
}

void CCharacter::Release(void)
{
	m_pTexture.reset();
	m_pHP.reset();
}