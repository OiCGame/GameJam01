#include "CharacterManager.h"


CCharacterManager::CCharacterManager() :
    m_pCharacter() {
}

CCharacterManager::~CCharacterManager() {
    this->Release();
}

CCharacterManager& CCharacterManager::Singleton(void) {
    static CCharacterManager obj;
    return obj;
}

/*
bool CCharacterManager::Initialize(void) {
    return true;
}
*/
void CCharacterManager::Update(void) {
    for (auto chara : m_pCharacter) {
        chara->Update();
    } // for
}

void CCharacterManager::Render(CVector2 scroll) {
    for (auto chara : m_pCharacter) {
        chara->Render(scroll);
    } // for
}

void CCharacterManager::Release(void) {
    for (auto chara : m_pCharacter) {
        chara->Release();
        chara.reset();
    } // for
    m_pCharacter.clear();
}

void CCharacterManager::AddCharacter(const std::shared_ptr<CCharacter>& ptr) {
    m_pCharacter.push_back(ptr);
}