#include "AudioManager.h"

#include "AssetDefine.h"


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