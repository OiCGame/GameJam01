#include "CharacterManager.h"
#include "CollisionManager.h"


CCharacterManager::CCharacterManager() :
    m_pCharacters() {
}

CCharacterManager::~CCharacterManager() {
    this->Release();
}

CCharacterManager& CCharacterManager::Singleton(void) {
    static CCharacterManager obj;
    return obj;
}

std::shared_ptr<CCharacter> CCharacterManager::GetPlayer(void) const {
    auto it = std::find_if(m_pCharacters.begin(), m_pCharacters.end(),
                           [](std::shared_ptr<CCharacter> chara) {
        return (chara)->GetTeam() == "Player";
    });
    if (it == m_pCharacters.end()) {
        return nullptr;
    } // if
    return *it;
}

std::shared_ptr<CCharacter> CCharacterManager::GetNearestEnemy(CVector2 position) const {
    // positionに元も近い位置にいるEnemyを返す
    auto it = std::min_element(m_pCharacters.begin(), m_pCharacters.end(), [&](
        std::shared_ptr<CCharacter> a,
        std::shared_ptr<CCharacter> b) {
        if (a->GetTeam() == "Player") {
            return false;
        } // if
        return
            Mof::CVector2Utilities::Distance(a->GetPosition(), position) <
            Mof::CVector2Utilities::Distance(b->GetPosition(), position);
    });
    if (it == m_pCharacters.end()) {
        return nullptr;
    } // if
    return *it;

    return std::shared_ptr<CCharacter>();
}

void CCharacterManager::Update(void) {
    // 死亡キャラを削除
    m_pCharacters.erase(
        std::remove_if(
            m_pCharacters.begin(),
            m_pCharacters.end(),
            [](shared_ptr<CCharacter> chara) {
        return !chara->IsShow();}),
        m_pCharacters.end());

    // 更新
    for (auto chara : m_pCharacters) {
        chara->Update();
    } // for
    MOF_PRINTLOG("CharacterManager m_pCharacters size = %d \n", m_pCharacters.size());
}

void CCharacterManager::Render(CVector2 scroll) {
    for (auto chara : m_pCharacters) {
        chara->Render(scroll);
    } // for
}

void CCharacterManager::Release(void) {
    for (auto chara : m_pCharacters) {
        chara->Release();
        chara.reset();
    } // for
    m_pCharacters.clear();
}

void CCharacterManager::AddCharacter(const std::shared_ptr<CCharacter>& ptr) {
    m_pCharacters.push_back(ptr);
}