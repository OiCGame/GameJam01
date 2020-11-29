#include "MachineGun.h"

#include "BulletManager.h"
#include "AudioManager.h"
#include "HP.h"


CVector2 CMachineGun::GetShowPower(void) {
    return CVector2(0.0f, 9.0f);
}

/// <summary>
/// コンストラクタ
/// </summary>
CMachineGun::CMachineGun() :
super(){
}

/// <summary>
/// デストラクタ
/// </summary>
CMachineGun::~CMachineGun() {
}

/// <summary>
/// Bullet発射
/// </summary>
/// <param name="position">発射位置</param>
/// <param name="move">更新移動量</param>
/// <param name="type">所属チーム</param>
void CMachineGun::Shot(CVector2 position, BulletTeamType type, BulletType bt, TextureKey key) {
    if (0 < super::m_ShotWait) {
        return;
    } // if
    m_ShotWait = 0.0167f * 10.0f;
    //super::m_ShotWait = CUtilities::GetFrameSecond() * 10.0f;
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