#include "Player.h"
#include "AudioManager.h"
#include "BulletManager.h"
#include "CharacterManager.h"
#include "EffectManager.h"

CPlayer::CPlayer():
    super(),
	m_bGimmick(false)
//    m_Invincible(0)
{
}

CPlayer::~CPlayer() {
}

CRectangle CPlayer::GetRectangle(void) const {
	if (m_bGimmick) return CRectangle(0, 0, 100000, 1000000);
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
	m_FlashTime.Update();
	if (m_FlashTime.GetTime() > 1)
	{
		m_FlashTime.Stop();
		m_FlashTime.Reset();
	}
    super::Update();
	if (m_bGimmick) { m_bGimmick = false; }
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

    if (g_pPad->IsKeyHold(XInputButton::XINPUT_A)) {
        m_pWeapon->Shot(m_Position, CVector2(0, -2.0f), BulletTeamType::Player, BulletType::Default, TextureKey::Bullet_01);
    }

	if (g_pPad->IsKeyPush(XInputButton::XINPUT_L_BTN)) {

		Vector2 normal{0, 1};
		auto& r = CCharacterManager::Singleton().GetNearestEnemy(m_Position);
		Vector2 enePos = r->GetPosition();
		if (enePos != m_Position)
		{
			CVector2Utilities::Normal(m_Position - enePos, normal);
		}
		CBulletManager::Singleton().Fire(m_Position, normal * -6.0f, BulletTeamType::Player, BulletType::Boomerang, TextureKey::Muscle);
	}
}

void CPlayer::Render(CVector2 scroll) {
	if (m_FlashTime.IsStart())
	{
		int alpha = 255 * (1 - m_FlashTime.GetTime());
		CGraphicsUtilities::RenderFillRect(GetRectangle(), MOF_ALPHA_WHITE(alpha));
	}
	if (m_DamageWait % 4 >= 2)
	{
		return;
	}
    {
        // 筋肉
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
	CEffectManager::Singleton().Start(EffectType::Explosion, this->GetPosition());
}

void CPlayer::CollisionEnemy(void) {
    super::CollisionEnemy();
	CAudioManager::Singleton().Play(SoundBufferKey::player_explosion);
	CEffectManager::Singleton().Start(EffectType::Explosion, this->GetPosition());
}

bool CPlayer::IsGimmick(void) const
{
	return m_bGimmick;
}

void CPlayer::GimmickFlash(void)
{
	m_bGimmick = true;
	m_FlashTime.Start();
}
