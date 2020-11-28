#include "AudioManager.h"


CAudioManager::CAudioManager() {
}

CAudioManager::~CAudioManager() {
}

CAudioManager& CAudioManager::Singleton(void) {
    static CAudioManager obj;
    return obj;
}

void CAudioManager::Play(SoundBufferKey key) {
    auto sound = SoundBufferAsset(key);
    sound->Play();
    if (1) 
    {

    } // if
}

void CAudioManager::Play(SoundStreamBufferKey key) {
    m_pBgm = SoundStreamBufferAsset(key);
    m_pBgm->Play();
}

void CAudioManager::Update(void) {
    m_pBgm->Update();
}