#include "ThreeWayGun.h"

#include "BulletManager.h"
#include "AudioManager.h"

#include "HP.h"


/// <summary>
/// コンストラクタ
/// </summary>
CThreeWayGun::CThreeWayGun() {
}

/// <summary>
/// デストラクタ
/// </summary>
CThreeWayGun::~CThreeWayGun() {
}

/// <summary>
/// Bullet発射
/// </summary>
/// <param name="position">発射位置</param>
/// <param name="move">更新移動量</param>
/// <param name="type">所属チーム</param>
void CThreeWayGun::Shot(CVector2 position, BulletTeamType type, BulletType bt, TextureKey key) {
//    super::AddWait(shot_interval_max_);
    if (0 < super::m_ShotWait) {
        return;
    } // if
    super::m_ShotWait = CUtilities::GetFrameSecond() * 60.0f;

	if (type == BulletTeamType::Player)
	{
		CAudioManager::Singleton().Play(SoundBufferKey::Sound0);
    }

    int shot_count = 3;

    float ad = MOF_ToRadian(-15.0f);
    CVector2 power = Mof::CVector2(1.0f, 1.0f);
    for (int i = 0; i < shot_count; i++) {
        auto speed = this->GetShowPower();
        if (type == BulletTeamType::Player)
            Rotate(speed.x, speed.y, MOF_ToRadian(180.0f), 0.0f, 0.0f);

        Rotate(speed.x, speed.y, ad, 0.0f,0.0f);
        CBulletManager::Singleton().Fire(
            position,
            speed,
            type, bt, key);
        ad += MOF_ToRadian(15.0f);
    } // for

}
