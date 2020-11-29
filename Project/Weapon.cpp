#include "Weapon.h"

#include "BulletManager.h"
#include "Character.h"
#include "AudioManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
CWeapon::CWeapon() {
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
void CWeapon::Shot(CVector2 position, CVector2 move, BulletTeamType type, BulletType bt, TextureKey key) {
    if ( 0 < m_ShotWait )
    {
        return;
    } // if
    m_ShotWait = CUtilities::GetFrameSecond() * 20;
	if (type == BulletTeamType::Player)
	{
		CAudioManager::Singleton().Play(SoundBufferKey::Sound0);
	}

    CBulletManager::Singleton().Fire(
        position,
        move,
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