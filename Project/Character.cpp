#include "Character.h"
#include "GamePad.h"

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
	if (g_pPad->GetStickVertical() > 0.35f)
	{
		m_Position.y -= CHARACTER_SPEED;
	}
	else if (g_pPad->GetStickVertical() < -0.35f)
	{
		m_Position.y += CHARACTER_SPEED;
	}

	if (g_pPad->GetStickHorizontal() > 0.35f)
	{
		m_Position.x += CHARACTER_SPEED;
	}
	else if (g_pPad->GetStickHorizontal() < -0.35f)
	{
		m_Position.x -= CHARACTER_SPEED;
	}
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
}
