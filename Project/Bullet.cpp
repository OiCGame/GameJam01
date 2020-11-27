#include "Bullet.h"

CBullet::CBullet() :
	m_Position(),
	m_Move(),
	m_pTexture() {
}

CBullet::~CBullet()
{
}

void CBullet::SetTexture(shared_ptr<CTexture> tex)
{
	this->m_pTexture = tex;
}

void CBullet::Fire(CVector2 position, CVector2 move)
{
	this->m_Position = position;
	this->m_Move = move;
}

void CBullet::Update(void)
{
	m_Position += m_Move;
}

void CBullet::Render(CVector2 scroll)
{
	if (auto r = m_pTexture.lock())
	{
		auto pos = m_Position + scroll;
		r->Render(pos.x, pos.y);
	} // if
}
