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
	if (!CSoundBufferAsset::Load(SoundBufferKey::boomerang, "boomerang1.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	sound = SoundBufferAsset(SoundBufferKey::boomerang);
	m_pSounds.push_back(sound);
	if (!CSoundBufferAsset::Load(SoundBufferKey::shot_struck, "shot-struck1.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	sound = SoundBufferAsset(SoundBufferKey::shot_struck);
	m_pSounds.push_back(sound);
	if (!CSoundBufferAsset::Load(SoundBufferKey::enemy_explosion, "enemy_explosion.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	sound = SoundBufferAsset(SoundBufferKey::enemy_explosion);
	m_pSounds.push_back(sound);
	if (!CSoundBufferAsset::Load(SoundBufferKey::player_explosion, "player_explosion.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	sound = SoundBufferAsset(SoundBufferKey::player_explosion);
	m_pSounds.push_back(sound);
	if (!CSoundBufferAsset::Load(SoundBufferKey::ok_se, "ok_se.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	sound = SoundBufferAsset(SoundBufferKey::ok_se);
	if (!CSoundBufferAsset::Load(SoundBufferKey::flash_01, "shakin1.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	sound = SoundBufferAsset(SoundBufferKey::flash_01);
	m_pSounds.push_back(sound);
	if (!CSoundBufferAsset::Load(SoundBufferKey::flash_02, "shakin2.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	sound = SoundBufferAsset(SoundBufferKey::flash_02);
	m_pSounds.push_back(sound);
	if (!CSoundBufferAsset::Load(SoundBufferKey::item_get, "itemGet.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	sound = SoundBufferAsset(SoundBufferKey::item_get);
	m_pSounds.push_back(sound);
	

    if (!CSoundStreamBufferAsset::Load(SoundStreamBufferKey::Bgm0, "game_bgm.mp3")) {
        MOF_PRINTLOG("failed to load sound");
        return false;
    } // if
    auto bgm0 = SoundStreamBufferAsset(SoundStreamBufferKey::Bgm0);
	bgm0->SetLoop(true);
    m_pSounds.push_back(bgm0);
	if (!CSoundStreamBufferAsset::Load(SoundStreamBufferKey::title, "title_bgm.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	bgm0 = SoundStreamBufferAsset(SoundStreamBufferKey::title);
	bgm0->SetLoop(true);
	m_pSounds.push_back(bgm0);
	if (!CSoundStreamBufferAsset::Load(SoundStreamBufferKey::gameclear, "gameclear_bgm.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	bgm0 = SoundStreamBufferAsset(SoundStreamBufferKey::gameclear);
	bgm0->SetLoop(true);
	m_pSounds.push_back(bgm0);
	if (!CSoundStreamBufferAsset::Load(SoundStreamBufferKey::gameover, "gameover_bgm.mp3")) {
		MOF_PRINTLOG("failed to load sound");
		return false;
	} // if
	bgm0 = SoundStreamBufferAsset(SoundStreamBufferKey::gameover);
	bgm0->SetLoop(true);
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