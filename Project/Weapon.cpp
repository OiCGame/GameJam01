#include "Weapon.h"

#include "BulletManager.h"
#include "Character.h"


CWeapon::CWeapon() :
    m_pOwner(nullptr){
}

CWeapon::CWeapon(Character* ptr) :
    m_pOwner(ptr){
}

CWeapon::~CWeapon() {
}

void CWeapon::Shot(CVector2 move) {
    /*
    CBulletManager::Singleton().Fire(
        m_pOwner->GetPosition(),
        move,
        m_pOwner->GetTeamType());
    */
}