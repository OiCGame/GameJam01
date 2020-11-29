#include "ThreeWayGun.h"

#include "BulletManager.h"
#include "AudioManager.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
CThreeWayGun::CThreeWayGun() {
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CThreeWayGun::~CThreeWayGun() {
}

void Rotate(float& pos_x, float& pos_y, const float radian,
            const float center_x, const float center_y) {
    float axis_x = pos_x - center_x;
    float axis_y = pos_y - center_y;

    float translate_x = (axis_x)*std::cosf(radian) - (axis_y)*std::sinf(radian);
    float translate_y = (axis_x)*std::sinf(radian) + (axis_y)*std::cosf(radian);

    pos_x = center_x + translate_x;
    pos_y = center_y + translate_y;
};
/// <summary>
/// Bullet����
/// </summary>
/// <param name="position">���ˈʒu</param>
/// <param name="move">�X�V�ړ���</param>
/// <param name="type">�����`�[��</param>
void CThreeWayGun::Shot(CVector2 position, CVector2 move, BulletTeamType type, BulletType bt, TextureKey key) {
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
        auto speed = move;
        Rotate(speed.x, speed.y, ad, 0.0f,0.0f);
        CBulletManager::Singleton().Fire(
            position,
            speed,
            type, bt, key);
        ad += MOF_ToRadian(15.0f);
    } // for

}
