#include "Character.h"
#include "GamePad.h"
#include "BulletManager.h"

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

	if (g_pPad->IsKeyPush(XInputButton::XINPUT_A))
	{
		CBulletManager::Singleton().Fire(m_Position, CVector2(0, -2.0f), BulletTeamType::Player);
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

CRectangle CCharacter::GetRectangle(void) const
{
	return CRectangle(m_Position, m_Position + Vector2(m_pTexture.lock()->GetWidth(), m_pTexture.lock()->GetHeight()));
}

void CCharacter::CollisionBullet(void)
{
}

void CCharacter::CollisionEnemy(void)
{
}
