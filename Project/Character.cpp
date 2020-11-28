#include "Character.h"
#include "GamePad.h"
#include "BulletManager.h"
#include "EffectManager.h"
#include "ThreeWayGun.h"


CCharacter::CCharacter() :
	m_Position(),
	m_pTexture(),
	m_pHP(std::make_shared<CHP>()),
	m_pWeapon(std::make_unique<CThreeWayGun>()),
	m_RenderRect(){
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
	// •\Ž¦‹éŒ`Ý’è
	if (auto r = m_pTexture.lock()) 
	{
		m_RenderRect = CRectangle(
			0.0f, 0.0f, 
			r->GetWidth(), r->GetHeight());
	} // if
}

void CCharacter::Update(void)
{
}

void CCharacter::Render(CVector2 scroll)
{
	::CGraphicsUtilities::RenderFillRect(this->GetRectangle(),
										 MOF_COLOR_GREEN);
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

CRectangle CCharacter::GetRectangle(void) const
{
	auto rect = m_RenderRect;
	rect.Translation(m_Position);
	return rect;
//	return CRectangle(m_Position, m_Position + Vector2(m_pTexture.lock()->GetWidth(), m_pTexture.lock()->GetHeight()));
}

void CCharacter::CollisionBullet(void)
{
	m_pHP->Damage(1);
	CEffectManager::Singleton().Start(EffectType::Barrier,
									  this->GetPosition());
}

void CCharacter::CollisionEnemy(void)
{
	m_pHP->Damage(1);
	CEffectManager::Singleton().Start(EffectType::Barrier,
									  this->GetPosition());
}