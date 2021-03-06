#include "Character.h"
#include "GamePad.h"
#include "BulletManager.h"
#include "EffectManager.h"
#include "ThreeWayGun.h"
#include "MachineGun.h"


CCharacter::CCharacter() :
	m_Position(),
	m_pTexture(),
	m_pHP(std::make_shared<CHP>()),
	m_pWeapon(),
	m_pWeapons(),
	m_RenderRect(),
	m_bShow(false){
	m_pWeapons.emplace("Weapon", std::make_shared<CWeapon>());
	m_pWeapons.emplace("ThreeWayGun", std::make_shared<CThreeWayGun>());
	m_pWeapons.emplace("MachineGun", std::make_shared<CMachineGun>());
	this->ChangeWeapon("Weapon");
}

CCharacter::~CCharacter()
{
	this->Release();
}

Mof::CVector2 CCharacter::GetPosition(void) const {
	return this->m_Position;
}

bool CCharacter::IsShow(void) const {
	return this->m_bShow;
}

bool CCharacter::IsDamage(void) const
{
	return m_DamageWait > 0;
}

void CCharacter::ChangeWeapon(const char* name) {
	auto it = m_pWeapons.find(name);
	if (it != m_pWeapons.end()) {
		m_pWeapon = it->second;
	} // if
}
void CCharacter::Initialize(const CharacterInitParam& param)
{
	m_Position = param.position;
	m_pTexture = param.texture;
	// 表示矩形設定
	if (auto r = m_pTexture.lock()) 
	{
		m_RenderRect = CRectangle(
			0.0f, 0.0f, 
			r->GetWidth(), r->GetHeight());
	} // if
	m_bShow = true;
	m_DamageWait = 0;
}

void CCharacter::Update(void)
{
	m_pWeapon->Update();
	if (m_DamageWait > 0)
	{
		m_DamageWait--;
	}
}

void CCharacter::Render(CVector2 scroll)
{
	if (m_DamageWait % 4 >= 2)
	{
		return;
	}
	//::CGraphicsUtilities::RenderFillRect(this->GetRectangle(),
	//									 MOF_COLOR_GREEN);
	if (auto r = m_pTexture.lock())
	{
		r->Render(m_Position.x + scroll.x, m_Position.y + scroll.y);
	} // if
}

void CCharacter::Release(void)
{
	m_pWeapon.reset();
	m_pTexture.reset();
	m_pHP.reset();
}

CRectangle CCharacter::GetRectangle(void) const
{
	auto rect = m_RenderRect;
	rect.Translation(m_Position);
	return rect;
}

void CCharacter::CollisionBullet(void)
{
	m_pHP->Damage(10);
	if (m_pHP->GetValue() <= 0) {
		CEffectManager::Singleton().Start(EffectType::Explosion2,
			this->GetPosition());
		m_bShow = false;
	} // if
	m_DamageWait = 60;
}

void CCharacter::CollisionEnemy(void)
{
	m_pHP->Damage(10);
	
	if (m_pHP->GetValue() <= 0) {
		CEffectManager::Singleton().Start(EffectType::Explosion2,
			this->GetPosition());
		m_bShow = false;
	} // if
	m_DamageWait = 60;
}