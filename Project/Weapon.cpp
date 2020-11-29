#include "Weapon.h"

#include "BulletManager.h"
#include "Character.h"
#include "AudioManager.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
CWeapon::CWeapon() {
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CWeapon::~CWeapon() {
}

/// <summary>
/// Bullet����
/// </summary>
/// <param name="position">���ˈʒu</param>
/// <param name="move">�X�V�ړ���</param>
/// <param name="type">�����`�[��</param>
void CWeapon::Shot(CVector2 position, CVector2 move, BulletTeamType type, BulletType bt, TextureKey key) {
    if ( 0 < m_ShotWait )
    {
        return;
    } // if
    m_ShotWait = CUtilities::GetFrameSecond() * 20;
	if (type == BulletTeamType::Player)
	{
		CAudioManager::Singleton().Play(SoundBufferKey::Sound0);
	}

    CBulletManager::Singleton().Fire(
        position,
        move,
        type, bt, key);
}

void CWeapon::Update(void) {
    m_ShotWait -= CUtilities::GetFrameSecond();
    /*
    if (m_ShotWait <= 0) {
        m_ShotWait = 0;
    } // if
    */
}