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
	// Bulletのテクスチャを用意する
	if (!CTextureAsset::Load(TextureKey::Bullet_01, "FOOD.png"))
	{
		MOF_PRINTLOG("failed to load texture");
		return false;
	} // if

	// 固定量だけBulletを用意する
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
	// 非表示のBulletを非表示にする？

	// Bulletの更新
	for (auto bullet : m_Bullets)
	{
		bullet->Update();
	} // for
}

void CBulletManager::Render(CVector2 scroll)
{
	// Bulletの描画
	for (auto bullet : m_Bullets)
	{
		bullet->Render(scroll);
	} // for
}

void CBulletManager::Release(void)
{
	// 解放
	for (auto bullet : m_Bullets)
	{
		bullet.reset();
	} // for
	m_Bullets.clear();
}

void CBulletManager::Fire(CVector2 position, CVector2 move, BulletTeamType type)
{
	// 表示中でないなら撃てるものとする
	for (auto bullet : m_Bullets)
	{
		if (!bullet->IsShow())
		{
			bullet->Fire(position, move, type);
			return;
		} // if
	} // for
}