#include "Weapon.h"

#include "BulletManager.h"
#include "Character.h"
#include "AudioManager.h"

CVector2 CWeapon::GetShowPower(void) {
    /*
    super::m_pWeapon->Shot(m_Position,
                           ,
                           BulletTeamType::Enemy, BulletType::Default, TextureKey::Bullet_02);
    */
    return Mof::CVector2(0.0f, 5.0f);
}

/// <summary>
/// コンストラクタ
/// </summary>
CWeapon::CWeapon() :
    m_ShotWait(0.0f){
}

/// <summary>
/// デストラクタ
/// </summary>
CWeapon::~CWeapon() {
}

/// <summary>
/// Bullet発射
/// </summary>
/// <param name="position">発射位置</param>
/// <param name="move">更新移動量</param>
/// <param name="type">所属チーム</param>
void CWeapon::Shot(CVector2 position, BulletTeamType type, BulletType bt, TextureKey key) {
    if ( 0 < m_ShotWait )
    {
        return;
    } // if
    m_ShotWait = CUtilities::GetFrameSecond() * 20;
    auto speed = this->GetShowPower();
	if (type == BulletTeamType::Player)
	{
		CAudioManager::Singleton().Play(SoundBufferKey::Sound0);
        Rotate(speed.x, speed.y, MOF_ToRadian(180.0f), 0.0f, 0.0f);
	}

    CBulletManager::Singleton().Fire(
        position,
        speed,
        type, bt, key);
}

void CWeapon::Update(void) {
    m_ShotWait -= CUtilities::GetFrameSecond();
    /*
    if (m_ShotWait <= 0) {
        m_ShotWait = 0;
    } // if
    */
}