#include "Player.h"

CPlayer::CPlayer()
{
	CCharacter();
}

CPlayer::~CPlayer()
{
}

void CPlayer::Update(CVector2 scroll)
{

	float threshold = 0.35f;
	bool StickTop = g_pPad->GetStickVertical() > threshold;
	bool StickBottom = g_pPad->GetStickVertical() < -threshold;
	bool StickRight = g_pPad->GetStickHorizontal() > threshold;
	bool StickLeft = g_pPad->GetStickHorizontal() < -threshold;

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

	//‰æ–Ê‚©‚ço‚È‚¢‚æ‚¤‚É‚·‚éˆ—
	if (m_Position.x + scroll.x < 0)
	{
		m_Position.x = -scroll.x;
	}
	if (m_Position.y + scroll.y < 0)
	{
		m_Position.y  = -scroll.y;
	}
	if (auto r = m_pTexture.lock())
	{
		if (m_Position.x + scroll.x> g_pGraphics->GetTargetWidth() - r->GetWidth())
		{
			m_Position.x = g_pGraphics->GetTargetWidth() - r->GetWidth() - scroll.x;
		}
		if (m_Position.y + scroll.y> g_pGraphics->GetTargetHeight() - r->GetHeight())
		{
			m_Position.y = g_pGraphics->GetTargetHeight() - r->GetHeight() - scroll.y;
		}
	}

	if (g_pPad->IsKeyPush(XInputButton::XINPUT_A))
	{
		m_Weapon.Shot(m_Position, CVector2(0, -2.0f), BulletTeamType::Player);
	}
}
