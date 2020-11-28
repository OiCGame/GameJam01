#include "BoomerangBullet.h"

BoomerangBullet::BoomerangBullet() :
    m_MovedDistance(0.0f),
    m_ReturnLength(20.0f), 
    m_bReturn(false)
{
}

BoomerangBullet::~BoomerangBullet() {
}

void BoomerangBullet::Update(void) {
    super::Update();

    // 通常移動
    if (!m_bReturn) {
        m_MovedDistance += m_Move.Length();
        if (m_ReturnLength < m_MovedDistance) {
            m_bReturn = true;
        } // if
    } // if
    else {
    // m_bReturn = true で 撃った人に向かっていく

    } // else


    // 撃った人に当たったらshowをfalseにする
    if (0) 
    {
        super::m_bShow = false;
    } // if
}

void BoomerangBullet::Fire(CVector2 position, CVector2 move, BulletTeamType type) {
    super::Fire(position, move, type);
    m_MovedDistance = 0.0f;
    m_bReturn = false;
}