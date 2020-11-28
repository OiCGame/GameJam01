#include "MachineGun.h"

#include "BulletManager.h"


CMachineGun::CMachineGun() :
super(){
}

CMachineGun::~CMachineGun() {
}

void CMachineGun::Shot(CVector2 position, CVector2 move, BulletTeamType type) {
    if (0 < super::m_ShotWait) {
        return;
    } // if
    super::m_ShotWait = CUtilities::GetFrameSecond() * 10.0f;

    CBulletManager::Singleton().Fire(
        position,
        move,
        type);
}