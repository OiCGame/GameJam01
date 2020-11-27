#include "GamePad.h"


bf::GamePad::GamePad() :
    _pad(std::make_shared<Mof::CXGamePad>()) {
    // ゲームパッドの作成
    XGAMEPADCREATEINFO ci; ci.No = 0;
    _pad->Create(&ci);
}

bf::GamePad::~GamePad() {
}

bf::GamePad& bf::GamePad::GetInstance(void) {
    static bf::GamePad object;
    return object;
}

std::shared_ptr<Mof::CXGamePad> bf::GamePad::GetGamePad(void) const {
    return this->_pad;
}

void bf::GamePad::RefreshKey(void) {
    _pad->RefreshKey();
}