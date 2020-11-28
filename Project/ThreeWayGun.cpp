#include "ThreeWayGun.h"

#include "BulletManager.h"


/// <summary>
/// コンストラクタ
/// </summary>
CThreeWayGun::CThreeWayGun() {
}

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="ptr">所有者</param>
CThreeWayGun::CThreeWayGun(Character* ptr) :
super(ptr){
}

/// <summary>
/// デストラク
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
void CThreeWayGun::Shot(CVector2 position, CVector2 move, BulletTeamType type) {
//    super::AddWait(shot_interval_max_);

    int shot_count = 3;

    float ad = MOF_ToRadian(-15.0f);
    CVector2 power = Mof::CVector2(1.0f, 1.0f);
    for (int i = 0; i < shot_count; i++) {
        auto speed = move;
        Rotate(speed.x, speed.y, ad, 0.0f,0.0f);
        CBulletManager::Singleton().Fire(
            position,
            speed,
            type);
        ad += MOF_ToRadian(15.0f);
    } // for

}
