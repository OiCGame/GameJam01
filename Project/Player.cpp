#include "Player.h"
#include "AudioManager.h"

CPlayer::CPlayer():
    super()
//    m_Invincible(0)
{
}

CPlayer::~CPlayer() {
}

CRectangle CPlayer::GetRectangle(void) const {
    auto rect = 
        CRectangle(m_Position, m_Position + Vector2(m_pTexture.lock()->GetWidth(), m_pTexture.lock()->GetHeight()));

    rect.Expansion(-16.0f);
    return rect;
}

const char* CPlayer::GetTeam(void) const {
    return "Player";
}

void CPlayer::Initialize(const CharacterInitParam& param) {
    super::Initialize(param);
    super::m_pHP->RegisterToRenderer();
}

void CPlayer::Update(void) {
    super::Update();
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

    if (StickTop)//ã
    {
        m_Position.y -= CHARACTER_SPEED * rate;
    }
    else if (StickBottom)//‰º
    {
        m_Position.y += CHARACTER_SPEED * rate;
    }

    if (StickRight)//‰E
    {
        m_Position.x += CHARACTER_SPEED * rate;
    }
    else if (StickLeft)//¶
    {
        m_Position.x -= CHARACTER_SPEED * rate;
    }

    //‰æ–Ê‚©‚ço‚È‚¢‚æ‚¤‚É‚·‚éˆ—
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

    if (g_pPad->IsKeyHold(XInputButton::XINPUT_A)) {
        m_pWeapon->Shot(m_Position, CVector2(0, -2.0f), BulletTeamType::Player);
    }
}

void CPlayer::Render(CVector2 scroll) {
    {
        // ‹Ø“÷
        auto tex = TextureAsset(TextureKey::Muscle);
        auto pos = this->GetPosition() + scroll;
        float y = 10.0f;
        tex->Render(pos.x - tex->GetWidth() * 0.5f, pos.y + y);
        auto rect = Mof::CRectangle(
            tex->GetWidth(), 0.0f,
            0.0f, tex->GetHeight());
        tex->Render(pos.x + tex->GetWidth() * 0.5f, pos.y + y, rect);
    }
    super::Render(scroll);
}

void CPlayer::CollisionBullet(void) {
    super::CollisionBullet();
	CAudioManager::Singleton().Play(SoundBufferKey::player_explosion);
}

void CPlayer::CollisionEnemy(void) {
    super::CollisionEnemy();
	CAudioManager::Singleton().Play(SoundBufferKey::player_explosion);
}