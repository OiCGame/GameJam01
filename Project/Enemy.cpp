#include "Enemy.h"

#include "Player.h"
#include "BulletManager.h"
#include "EffectManager.h"
#include "AudioManager.h"


/// <summary>
/// 
/// </summary>
void CEnemy::UpdateAttack(void) {
    super::m_pWeapon->Shot(m_Position,
                         Mof::CVector2(0.0f, 5.0f),
                         BulletTeamType::Enemy, BulletType::Default, TextureKey::Bullet_01);
}

/// <summary>
/// 移動更新
/// </summary>
void CEnemy::UpdateMove(void) {

	if (m_bTargetMove)
	{
		float chaseTime = 0.5f;
		float movey = 2;
		shared_ptr<CPlayer> pPlayer = m_pTarget.lock();
		Vector2 move = (pPlayer->GetPosition() - m_Position) / (60.0f * chaseTime);
		move.y = movey;
		m_Move = move;
	}
	else
	{
		if (m_MoveMotion.IsEnd())
		{
			m_MoveMotion.Reset();
		}

		m_Move = m_MoveMotion.GetValue();
		m_MoveMotion.Update();
	}
}

void CEnemy::InitMoveMotionDefault(void)
{
	float moveY = 2;
	m_MoveMotion << CEaseMotion<Vector2>(Vector2(0, moveY), Vector2(0, moveY), Ease::InOut, EaseType::Linear);
}

void CEnemy::InitMoveMotionWave(void)
{
	float waveWidth = 10;
	float moveY = 2;
	m_MoveMotion << CEaseMotion<Vector2>(Vector2(0, moveY), Vector2( waveWidth * 0.5f, moveY), Ease::Out, EaseType::Sine, 0.25f);
	m_MoveMotion << CEaseMotion<Vector2>(Vector2( waveWidth * 0.5f, moveY), Vector2(0, moveY), Ease::In , EaseType::Sine, 0.25f);
	m_MoveMotion << CEaseMotion<Vector2>(Vector2(0, moveY), Vector2(-waveWidth * 0.5f, moveY), Ease::Out, EaseType::Sine, 0.25f);
	m_MoveMotion << CEaseMotion<Vector2>(Vector2(-waveWidth * 0.5f, moveY), Vector2(0, moveY), Ease::In , EaseType::Sine, 0.25f);
}

void CEnemy::InitMoveMotionChase(void)
{
	m_bTargetMove = true;
}

void CEnemy::InitMoveMotionCustom(void)
{
	m_MoveMotion << CEaseMotion<Vector2>(Vector2( 0.0f,  4), Vector2( 0.0f,  4), Ease::Out  , EaseType::Back, 2.0f);
	m_MoveMotion << CEaseMotion<Vector2>(Vector2( 0.0f, -3), Vector2( 0.0f, -3), Ease::InOut, EaseType::Back, 5.0f);
}

/// <summary>
/// コンストラクタ
/// </summary>
CEnemy::CEnemy() :
    super() {

}

/// <summary>
/// デストラクタ
/// </summary>
CEnemy::~CEnemy() {
	m_MoveMotion.Clear();
}
/// <summary>
/// セッター
/// </summary>
/// <param name="ptr">ポインタ</param>
void CEnemy::SetTarget(std::shared_ptr<CPlayer> ptr) {
    this->m_pTarget = ptr;
}

const char* CEnemy::GetTeam(void) const {
    return "Enemy";
}

void CEnemy::Initialize(const CharacterInitParam& param) {
    super::Initialize(param);
	m_bTargetMove = false;
	switch (param.type)
	{
	case 1: //直進
		InitMoveMotionDefault();
		break;
	case 2: //ウェーブ
		InitMoveMotionWave();
		break;
	case 3: //追跡
		InitMoveMotionChase();
		break;
	case 4: //こったやつ
		InitMoveMotionCustom();
		break;
	}
	m_MoveMotion.Start();
}

/// <summary>
/// 更新
/// </summary>
void CEnemy::Update(void) {
    super::Update();

    this->UpdateMove();
	
    float delta = ::CUtilities::GetFrameSecond();
    m_AttackTime += delta;
    if (m_AttackTimeMax < m_AttackTime) {
        m_AttackTime = 0;
		
        this->UpdateAttack();
    } // if
    
    m_Position += m_Move;
//    m_Position = gAnime.CalculatePointPosition(_time);

}

void CEnemy::Render(CVector2 scroll) {
    super::Render(scroll);
}

void CEnemy::CollisionBullet(void) {
	CAudioManager::Singleton().Play(SoundBufferKey::shot_struck);
	CEffectManager::Singleton().Start(EffectType::Explosion, this->GetPosition());
	m_pHP->Damage(40);
	if (m_pHP->GetValue() <= 0) {
		CAudioManager::Singleton().Play(SoundBufferKey::enemy_explosion);
		CEffectManager::Singleton().Start(EffectType::Explosion2,
										  this->GetPosition());
		super::Notify(this, "EnemyDead");
		m_bShow = false;
	} // if
}

void CEnemy::CollisionEnemy(void) {
	m_pHP->Damage(100);
	if (m_pHP->GetValue() <= 0) {
		CEffectManager::Singleton().Start(EffectType::Barrier,
										  this->GetPosition());
		super::Notify(this, "EnemyDead");
		m_bShow = false;
	} // if
}