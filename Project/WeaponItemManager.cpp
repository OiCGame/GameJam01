#include "WeaponItemManager.h"


CWeaponItemManager::CWeaponItemManager() :
    m_pWeaponItemArray() {
}

CWeaponItemManager::~CWeaponItemManager() {
}

CWeaponItemManager& CWeaponItemManager::Singleton(void) {
    static CWeaponItemManager obj;
    return obj;
}

vector<shared_ptr<CWeaponItem>>& CWeaponItemManager::GetArray(void) {
    return m_pWeaponItemArray;
}
void CWeaponItemManager::Register(const shared_ptr<CWeaponItem>& pItem) {
    m_pWeaponItemArray.push_back(pItem);
}

void CWeaponItemManager::Render(void) {
    m_pWeaponItemArray.erase(std::remove_if(
        m_pWeaponItemArray.begin(),
        m_pWeaponItemArray.end(),
        [](shared_ptr<CWeaponItem> item) {
        return !item->IsShow();
    }), m_pWeaponItemArray.end());

    for (auto item : m_pWeaponItemArray) {
        item->Render();
    } // for
}