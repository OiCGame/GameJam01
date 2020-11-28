#include "Player.h"

CPlayer::CPlayer()
{
	CCharacter();
}

CPlayer::~CPlayer()
{
}

void CPlayer::Update(void)
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

	if (StickTop)//��
	{
		m_Position.y -= CHARACTER_SPEED * rate;
	}
	else if (StickBottom)//��
	{
		m_Position.y += CHARACTER_SPEED * rate;
	}

	if (StickRight)//�E
	{
		m_Position.x += CHARACTER_SPEED * rate;
	}
	else if (StickLeft)//��
	{
		m_Position.x -= CHARACTER_SPEED * rate;
	}

	if (g_pPad->IsKeyPush(XInputButton::XINPUT_A))
	{
		m_Weapon.Shot(m_Position, CVector2(0, -2.0f), BulletTeamType::Player);
	}
}
