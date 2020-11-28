#include "BulletManager.h"

#include "AssetDefine.h"
#include "HomingBullet.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
CBulletManager::CBulletManager() :
	m_Bullets(),
	m_BulletSize(256)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CBulletManager::~CBulletManager()
{
}

/// <summary>
/// �V���O���g��
/// </summary>
/// <returns>�C���X�^���X</returns>
CBulletManager&CBulletManager::Singleton(void)
{
	static CBulletManager obj;
	return obj;
}

/// <summary>
/// ������
/// </summary>
/// <returns>����������tue��Ԃ�</returns>
bool CBulletManager::Initialize(void)
{
	// Bullet�̃e�N�X�`����p�ӂ���
	if (!CTextureAsset::Load(TextureKey::Bullet_01, "FOOD.png"))
	{
		MOF_PRINTLOG("failed to load texture");
		return false;
	} // if

	// �Œ�ʂ���Bullet��p�ӂ���
	m_Bullets.reserve(m_BulletSize);
	for (int i = 0; i < m_BulletSize; i++) {
		//auto temp = std::make_shared<CBullet>();
		auto temp = std::make_shared<CHomingBullet>();
		temp->SetTexture(CTextureAsset::GetAsset(TextureKey::Bullet_01));
		m_Bullets.push_back(temp);
	} // for
	return true;
}

/// <summary>
/// �X�V
/// </summary>
void CBulletManager::Update(void)
{
	// ��\����Bullet���\���ɂ���H

	// Bullet�̍X�V
	for (auto bullet : m_Bullets)
	{
		bullet->Update();
	} // for
}

/// <summary>
/// �`��
/// </summary>
/// <param name="scroll">�X�N���[���l</param>
void CBulletManager::Render(CVector2 scroll)
{
	// Bullet�̕`��
	for (auto bullet : m_Bullets)
	{
		bullet->Render(scroll);
	} // for
}

/// <summary>
/// ���
/// </summary>
void CBulletManager::Release(void)
{
	// ���
	for (auto bullet : m_Bullets)
	{
		bullet.reset();
	} // for
	m_Bullets.clear();
}

/// <summary>
/// ����
/// </summary>
/// <param name="position">���ˈʒu</param>
/// <param name="move">�ړ���</param>
/// <param name="type">Bullet�̏����`�[��</param>
void CBulletManager::Fire(CVector2 position, CVector2 move, BulletTeamType type)
{
	// �\�����łȂ��Ȃ猂�Ă���̂Ƃ���
	for (auto bullet : m_Bullets)
	{
		if (!bullet->IsShow())
		{
			bullet->Fire(position, move, type);
			return;
		} // if
	} // for
}