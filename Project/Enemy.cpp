#include "Enemy.h"

#include "Player.h"
#include "BulletManager.h"

/// <summary>
/// 
/// </summary>
void CEnemy::UpdateAttack(void) {
    super::m_Weapon.Shot(m_Position,
                         Mof::CVector2(0.0f, 2.0f),
                         BulletTeamType::Enemy);
}

/// <summary>
/// �ړ��X�V
/// </summary>
void CEnemy::UpdateMove(void) {

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
}

void CEnemy::InitMoveMotionCustom(void)
{
	m_MoveMotion << CEaseMotion<Vector2>(Vector2( 500.0f / 60.0f, 5), Vector2( 500.0f / 60.0f, 5), Ease::Out, EaseType::Back, 1.0f);
	m_MoveMotion << CEaseMotion<Vector2>(Vector2(-500.0f / 60.0f, 5), Vector2(-500.0f / 60.0f, 5), Ease::In , EaseType::Back, 1.0f);
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
CEnemy::CEnemy() :
    super() {

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CEnemy::~CEnemy() {
	m_MoveMotion.Clear();
}
/// <summary>
/// �Z�b�^�[
/// </summary>
/// <param name="ptr">�|�C���^</param>
void CEnemy::SetTarget(std::shared_ptr<CPlayer> ptr) {
    this->m_pTarget = ptr;
}

void CEnemy::Initialize(const CharacterInitParam& param) {
    super::Initialize(param);
	//InitMoveMotionWave();
	InitMoveMotionCustom();
	m_MoveMotion.Start();
}

/// <summary>
/// �X�V
/// </summary>
void CEnemy::Update(void) {

    this->UpdateMove();

	if (m_MoveMotion.IsEnd())
	{
		m_MoveMotion.Reset();
	}
	m_MoveMotion.Update();
	m_Move = m_MoveMotion.GetValue();

	
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