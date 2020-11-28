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

std::shared_ptr<CCharacter> CCharacterManager::GetPlayer(void) const {
    auto it = std::find_if(m_pCharacter.begin(), m_pCharacter.end(),
                           [](std::shared_ptr<CCharacter> chara) {
        return (chara)->GetTeam() == "Player";
    });
    if(it == m_pCharacter.end()){
        return nullptr;
    } // if
    return *it;
}

std::shared_ptr<CCharacter> CCharacterManager::GetNearestEnemy(CVector2 position) const {
        auto it = std::min_element(m_pCharacter.begin(), m_pCharacter.end(), [&](
        std::shared_ptr<CCharacter> a,
        std::shared_ptr<CCharacter> b) {
            if (a->GetTeam() == "Player") {
                return false;
            } // if
        return 
            Mof::CVector2Utilities::Distance(a->GetPosition(), position) <
            Mof::CVector2Utilities::Distance(b->GetPosition(), position);
    });
    if (it == m_pCharacter.end()) {
        return nullptr;
    } // if
    return *it;

    return std::shared_ptr<CCharacter>();
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