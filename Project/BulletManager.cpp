#include "BulletManager.h"

#include "AssetDefine.h"


CBulletManager::CBulletManager() :
	m_Bullets(),
	m_BulletSize(64)
{
}

CBulletManager::~CBulletManager()
{
}

CBulletManager&CBulletManager::Singleton(void)
{
	static CBulletManager obj;
	return obj;
}

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
		auto temp = std::make_shared<CBullet>();
		temp->SetTexture(CTextureAsset::GetAsset(TextureKey::Bullet_01));
		m_Bullets.push_back(temp);
	} // for
	return true;
}

void CBulletManager::Update(void)
{
	// ��\����Bullet���\���ɂ���H

	// Bullet�̍X�V
	for (auto bullet : m_Bullets)
	{
		bullet->Update();
	} // for
}

void CBulletManager::Render(CVector2 scroll)
{
	// Bullet�̕`��
	for (auto bullet : m_Bullets)
	{
		bullet->Render(scroll);
	} // for
}

void CBulletManager::Release(void)
{
	// ���
	for (auto bullet : m_Bullets)
	{
		bullet.reset();
	} // for
	m_Bullets.clear();
}

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