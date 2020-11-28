#include "BoomerangBullet.h"

#include "CharacterManager.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
CBoomerangBullet::CBoomerangBullet() :
    m_MovedDistance(0.0f),
    m_ReturnLength(500.0f), 
    m_bReturn(false),
    m_pHome()
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CBoomerangBullet::~CBoomerangBullet() {
}

/// <summary>
/// �X�V
/// </summary>
void CBoomerangBullet::Update(void) {
    super::Update();

    // �ʏ�ړ�
    if (!m_bReturn) {
        m_MovedDistance += m_Move.Length();
        if (m_ReturnLength < m_MovedDistance) {
            m_bReturn = true;
        } // if
    } // if
    else {
        // m_bReturn = true �� �������l�Ɍ������Ă���
        if (auto home = m_pHome.lock()) {
            // �������l�̕����֌������Ă���
            auto dir = home->GetPosition() - m_Position;
            Mof::CVector2Utilities::Normal(dir, dir);
            m_Move = dir * m_Move.Length();
        } // if
        
        // �������l�ɓ���������show��false�ɂ���
        if (auto home = m_pHome.lock()) {
            auto rect = this->GetRectangle();
            if (home->GetRectangle().CollisionRect(rect))
            {
                super::m_bShow = false;
                m_pHome.reset();
            } // if
        } // if
    } // else
    
}

/// <summary>
/// ����
/// </summary>
/// <param name="position">���ˈʒu</param>
/// <param name="move">�X�V�ړ���</param>
/// <param name="type">�����`�[��</param>
void CBoomerangBullet::Fire(CVector2 position, CVector2 move, BulletTeamType type) {
    super::Fire(position, move, type);
    m_MovedDistance=0.0f;
    m_bReturn=false;

    if (type == BulletTeamType::Player) {
        m_pHome = CCharacterManager::Singleton().GetPlayer();
    } // if
    else {
        // ����������͌������{�l���߂��ɂ�����̂Ƃ���
        m_pHome = CCharacterManager::Singleton().GetNearestEnemy(position);
    } // else
}