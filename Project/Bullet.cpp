#include "Bullet.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <created>�쑺,2020/11/28</created>
/// <changed>�쑺,2020/11/28</changed>
// ********************************************************************************
CBullet::CBullet() :
    m_Position(),
    m_Move(),
    m_pTexture(),
    m_bShow(false),
    m_RenderRect(200.0f, 200.0f, 250.0f, 250.0f),
    m_TeamType() 
{
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>�쑺,2020/11/28</created>
/// <changed>�쑺,2020/11/28</changed>
// ********************************************************************************
CBullet::~CBullet() 
{
    m_pTexture.reset();
}

/// <summary>
/// �Z�b�^�[
/// </summary>
/// <param name="tex">�|�C���^</param>
void CBullet::SetTexture(shared_ptr<CTexture> tex) 
{
    this->m_pTexture = tex;
}

/// <summary>
/// �Q�b�^�[	
/// </summary>
/// <returns>Bullet�̏����`�[��</returns>
BulletTeamType CBullet::GetTeamType(void) const 
{
    return this->m_TeamType;
}

/// <summary>
/// �Q�b�^�[
/// </summary>
/// <returns>�\����`�i�Փˋ�`�j</returns>
CRectangle CBullet::GetRectangle(void) const
{
    return this->m_RenderRect;
}
/// <summary>
/// �\���t���O�擾
/// </summary>
/// <returns>�\�����Ă����true��Ԃ�</returns>
bool CBullet::IsShow(void) const 
{
    return this->m_bShow;
}

/// <summary>
/// �X�V
/// </summary>
/// <param name=""></param>
void CBullet::Update(void) 
{
    // �\���t���O�������Ă��Ȃ��Ȃ珈�����Ȃ�
    if (!this->IsShow()) {
        return;
    } // if

    // �ړ��ʍX�V
    m_Position += m_Move;

    // �͂ݏo�����\���ɂ���
    if (::g_pFramework->GetWindow()->GetWidth() < m_Position.x) {
        this->m_bShow = false;
    } // if
}

/// <summary>
/// �`��
/// </summary>
/// <param name="scroll">�X�N���[���l</param>
void CBullet::Render(CVector2 scroll) 
{
    // �\���t���O�������Ă��Ȃ��Ȃ珈�����Ȃ�
    if (!this->IsShow()) {
        return;
    } // if

    // �`��
    if (auto r = m_pTexture.lock()) {
        auto pos = m_Position + scroll;
        r->Render(pos.x, pos.y, m_RenderRect);
    } // if
}

/// <summary>
/// ����
/// </summary>
/// <param name="position">���ˈʒu</param>
/// <param name="move">�X�V�ړ���</param>
/// <param name="type">�����`�[��</param>
void CBullet::Fire(CVector2 position, CVector2 move, BulletTeamType type) 
{
    this->m_Position = position;
    this->m_Move = move;
    this->m_bShow = true;
    this->m_TeamType = type;
}