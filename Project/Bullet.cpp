#include "Bullet.h"


CBullet::CBullet() :
    m_Position(),
    m_Move(),
    m_pTexture(),
    m_bShow(false),
    m_RenderRect(200.0f, 200.0f, 250.0f, 250.0f),
    m_TeamType() 
{
}

CBullet::~CBullet() 
{
    m_pTexture.reset();
}

void CBullet::SetTexture(shared_ptr<CTexture> tex) 
{
    this->m_pTexture = tex;
}

BulletTeamType CBullet::GetTeamType(void) const 
{
    return this->m_TeamType;
}

CRectangle CBullet::GetRectangle(void) 
{
    return this->m_RenderRect;
}

bool CBullet::IsShow(void) const 
{
    return this->m_bShow;
}

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

void CBullet::Fire(CVector2 position, CVector2 move, BulletTeamType type) 
{
    this->m_Position = position;
    this->m_Move = move;
    this->m_bShow = true;
    this->m_TeamType = type;
}