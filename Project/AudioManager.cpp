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
    auto temp = SoundBufferAsset(key);
    auto it = std::find(m_pSounds.begin(), m_pSounds.end(), temp);
    if (it == m_pSounds.end()) {
        m_pSounds.push_back(temp);
    } // if
    if (temp) {
        temp->Play();
    } // if
}

void CAudioManager::Play(SoundStreamBufferKey key) {
    auto temp = SoundStreamBufferAsset(key);
    auto it = std::find(m_pSounds.begin(), m_pSounds.end(), temp);
    if (it == m_pSounds.end()) {
        m_pSounds.push_back(temp);
    } // if
    if(temp){
        temp->Play();
    } // if
}

bool CAudioManager::Load(void) {
    if (!CSoundBufferAsset::Load(SoundBufferKey::Sound0, "shot1.mp3")) {
        MOF_PRINTLOG("failed to load sound");
        return false;
    } // if
    auto sound = SoundBufferAsset(SoundBufferKey::Sound0);
    m_pSounds.push_back(sound);


    if (!CSoundStreamBufferAsset::Load(SoundStreamBufferKey::Bgm0, "game_bgm.mp3")) {
        MOF_PRINTLOG("failed to load sound");
        return false;
    } // if
    auto bgm0 = SoundStreamBufferAsset(SoundStreamBufferKey::Bgm0);
    m_pSounds.push_back(bgm0);
    return true;
}

void CAudioManager::Update(void) {
    for (auto sound : m_pSounds) {
        if (sound) {
            sound->Update();
        } // if
    } // for
}

void CAudioManager::Release(void) {
    for (auto sound : m_pSounds) {
        sound->Release();
        sound.reset();
    } // for
    m_pSounds.clear();
}