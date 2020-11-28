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
	bool StickTop = g_pPad->GetStickVertical() > 0.35f;
	bool StickBottom = g_pPad->GetStickVertical() < -0.35f;
	bool StickRight = g_pPad->GetStickHorizontal() > 0.35f;
	bool StickLeft = g_pPad->GetStickHorizontal() < -0.35f;

	float rate = 1.0f;
	if (StickTop || StickBottom)
	{
		if (StickRight || StickLeft)
		{
			rate = 0.71f;
		}
	}

	if (StickTop)//ã
	{
		m_Position.y -= CHARACTER_SPEED * rate;
	}
	else if (StickBottom)//‰º
	{
		m_Position.y += CHARACTER_SPEED * rate;
	}

	if (StickRight)//‰E
	{
		m_Position.x += CHARACTER_SPEED * rate;
	}
	else if (StickLeft)//¶
	{
		m_Position.x -= CHARACTER_SPEED * rate;
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
