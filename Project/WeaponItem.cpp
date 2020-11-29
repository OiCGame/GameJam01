#include "WeaponItem.h"

#include "AssetDefine.h"
#include "AudioManager.h"


/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="pos">位置</param>
CWeaponItem::CWeaponItem(CVector2 pos) :
    m_Type(-1),
    m_Position(pos),
    m_pTexture(),
    m_bShow(true){

    m_Type =  ::CUtilities::Random(1,4);
    switch (m_Type) {
        case 1:
            m_pTexture = TextureAsset(TextureKey::WeaponItem01);
            break;
        case 2:
            m_pTexture = TextureAsset(TextureKey::WeaponItem02);
            break;
        case 3:
            m_pTexture = TextureAsset(TextureKey::WeaponItem03);
            break;
        default:
            break;
    } // switch

    if (auto r = m_pTexture.lock()) {
        m_RenderRect = CRectangle(0.0f, 0.0f, 
                                  r->GetWidth(), r->GetHeight());
    } // if
}

/// <summary>
/// デストラクタ
/// </summary>
CWeaponItem::~CWeaponItem() {
}

/// <summary>
/// 武器タイプを返す
/// </summary>
/// <param name=""></param>
/// <returns></returns>
const char* CWeaponItem::GetWeaponType(void) {
    switch (m_Type) {
        case 1:
            return "Weapon";
            break;
        case 2:
            return "ThreeWayGun";
            break;
        case 3:
            return "MachineGun";
            break;
        default:
            break;
    } // switch
    return nullptr;
}

/// <summary>
/// ゲッター
/// </summary>
/// <returns>衝突矩形</returns>
CRectangle CWeaponItem::GetRectangle(void) const {
    auto rect = m_RenderRect;
    rect.Translation(m_Position);
    return rect;
}

/// <summary>
/// 判定
/// </summary>
/// <returns>表示フラグ</returns>
bool CWeaponItem::IsShow(void) const {
    return this->m_bShow;
}
  
/// <summary>
/// 描画
/// </summary>
void CWeaponItem::Render(void) {
    m_Position.y++;
    
    if (auto tex = m_pTexture.lock()) {
        auto pos = m_Position;
        tex->Render(pos.x, pos.y);

        auto h = g_pFramework->GetWindow()->GetHeight();
        // 画面外かどうか判定する
        if (g_pFramework->GetWindow()->GetHeight() < pos.y) {
            this->m_bShow = false;
        } // if
    } // if
}

void CWeaponItem::Use(void) {
    CAudioManager::Singleton().Play(SoundBufferKey::Sound0);
    this->m_bShow = false;
}