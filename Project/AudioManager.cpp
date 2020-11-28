#include "AudioManager.h"


CAudioManager::CAudioManager() {
}

CAudioManager::~CAudioManager() {
}

CAudioManager& CAudioManager::Singleton(void) {
    static CAudioManager obj;
    return obj;
}

void CAudioManager::Play(void) {
}