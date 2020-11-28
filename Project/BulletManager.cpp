#include "BulletManager.h"

#include "AssetDefine.h"
#include "HomingBullet.h"
#include "BoomerangBullet.h"
#include "CollisionManager.h"


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

	// �Œ�ʂ���Bullet��p�ӂ���
	m_Bullets.reserve(m_BulletSize);
	/*
	for (int i = 0; i < m_BulletSize; i++) {
		//auto temp = std::make_shared<CBullet>();
//		auto temp = std::make_shared<CHomingBullet>();
		auto temp = std::make_shared<CBoomerangBullet>();
		temp->SetTexture(CTextureAsset::GetAsset(TextureKey::Bullet_01));
		m_Bullets.push_back(temp);
	} // for
	*/
	return true;
}

/// <summary>
/// �X�V
/// </summary>
void CBulletManager::Update(void)
{
	// ��\���̂��͍̂폜
	auto it = std::remove_if(
		m_Bullets.begin(),
		m_Bullets.end(),
		[](shared_ptr<CBullet> bullet) {
		return bullet->IsShow() == false; 
	});
	m_Bullets.erase(it, m_Bullets.end());

	// Bullet�̍X�V
	for (auto bullet : m_Bullets)
	{
		bullet->Update();
	} // for

	MOF_PRINTLOG("BulletManager m_Bullets size = %d \n", m_Bullets.size());

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
//	auto bullet= std::make_shared<CBoomerangBullet>();
	auto bullet= std::make_shared<CBullet>();
	bullet->SetTexture(CTextureAsset::GetAsset(TextureKey::Bullet_01));
	m_Bullets.push_back(bullet);

	bullet->Fire(position, move, type);


	if (type == BulletTeamType::Player) {
		CCollisionManager::Singleton().Register(
			bullet,
			CollisionLayer::Player);
	} // if
	else {
		CCollisionManager::Singleton().Register(
			bullet,
			CollisionLayer::Enemy);
	} // else

	/*
	// �\�����łȂ��Ȃ猂�Ă���̂Ƃ���
	for (auto bullet : m_Bullets)
	{
		if (!bullet->IsShow())
		{
			bullet->Fire(position, move, type);
			return;
		} // if
	} // for
	*/
}
/*
void CBulletManager::AddBullet(std::shared_ptr<CBullet> ptr) {
	m_Bullets.push_back(ptr);
}
*/