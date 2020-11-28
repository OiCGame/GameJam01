#include "Player.h"

CPlayer::CPlayer() {
    CCharacter();
}

CPlayer::~CPlayer() {
}

void CPlayer::Update(void) {

    float threshold = 0.35f;
    bool StickTop = g_pPad->GetStickVertical() > threshold;
    bool StickBottom = g_pPad->GetStickVertical() < -threshold;
    bool StickRight = g_pPad->GetStickHorizontal() > threshold;
    bool StickLeft = g_pPad->GetStickHorizontal() < -threshold;

    float rate = 1.0f;
    if (StickTop || StickBottom) {
        if (StickRight || StickLeft) {
            rate = 0.71f;
        }
    }

    if (StickTop)//上
    {
        m_Position.y -= CHARACTER_SPEED * rate;
    }
    else if (StickBottom)//下
    {
        m_Position.y += CHARACTER_SPEED * rate;
    }

    if (StickRight)//右
    {
        m_Position.x += CHARACTER_SPEED * rate;
    }
    else if (StickLeft)//左
    {
        m_Position.x -= CHARACTER_SPEED * rate;
    }

    //画面から出ないようにする処理
    if (m_Position.x < 0) {
        m_Position.x = 0;
    }
    if (m_Position.y < 0) {
        m_Position.y = 0;
    }
    if (auto r = m_pTexture.lock()) {
        if (m_Position.x > g_pGraphics->GetTargetWidth() - r->GetWidth()) {
            m_Position.x = g_pGraphics->GetTargetWidth() - r->GetWidth();
        }
        if (m_Position.y > g_pGraphics->GetTargetHeight() - r->GetHeight()) {
            m_Position.y = g_pGraphics->GetTargetHeight() - r->GetHeight();
        }
    }

    if (g_pPad->IsKeyPush(XInputButton::XINPUT_A)) {
        m_Weapon.Shot(m_Position, CVector2(0, -2.0f), BulletTeamType::Player);
    }
}

void CPlayer::Render(CVector2 scroll) {
    super::Render(scroll);
    // 左右のオフセット
    auto tex = TextureAsset(TextureKey::Muscle);
    CVector2 size = Mof::CVector2(tex->GetWidth(), tex->GetHeight());

    auto pos = this->GetPosition() + scroll ;
    Mof::Rectangle rect;
    CVector2 offset;
    // 描画


    // 左
    rect = Mof::CRectangle(
        0.0f, 0.0f,
        tex->GetWidth(), tex->GetHeight());
//    tex->Render(pos.x - size.x, pos.y, rect);
    tex->Render(pos.x , pos.y, rect);
    tex->Render(pos.x , pos.y, rect);
    // 右
    /*
    offset = CVector2(20.0f, 5.0f);
    rect = Mof::CRectangle(
        tex->GetWidth(), 0.0,
        0.0f, tex->GetHeight());
    tex->Render(pos.x + offset.x, pos.y + offset.y, rect);
    */
}