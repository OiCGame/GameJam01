#include "BulletManager.h"

#include "AssetDefine.h"
#include "HomingBullet.h"

/// <summary>
/// コンストラクタ
/// </summary>
CBulletManager::CBulletManager() :
	m_Bullets(),
	m_BulletSize(256)
{
}

/// <summary>
/// デストラクタ
/// </summary>
CBulletManager::~CBulletManager()
{
}

/// <summary>
/// シングルトン
/// </summary>
/// <returns>インスタンス</returns>
CBulletManager&CBulletManager::Singleton(void)
{
	static CBulletManager obj;
	return obj;
}

/// <summary>
/// 初期化
/// </summary>
/// <returns>成功したらtueを返す</returns>
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
		//auto temp = std::make_shared<CBullet>();
		auto temp = std::make_shared<CHomingBullet>();
		temp->SetTexture(CTextureAsset::GetAsset(TextureKey::Bullet_01));
		m_Bullets.push_back(temp);
	} // for
	return true;
}

/// <summary>
/// 更新
/// </summary>
void CBulletManager::Update(void)
{
	// 非表示のBulletを非表示にする？

	// Bulletの更新
	for (auto bullet : m_Bullets)
	{
		bullet->Update();
	} // for
}

/// <summary>
/// 描画
/// </summary>
/// <param name="scroll">スクロール値</param>
void CBulletManager::Render(CVector2 scroll)
{
	// Bulletの描画
	for (auto bullet : m_Bullets)
	{
		bullet->Render(scroll);
	} // for
}

/// <summary>
/// 解放
/// </summary>
void CBulletManager::Release(void)
{
	// 解放
	for (auto bullet : m_Bullets)
	{
		bullet.reset();
	} // for
	m_Bullets.clear();
}

/// <summary>
/// 発射
/// </summary>
/// <param name="position">発射位置</param>
/// <param name="move">移動量</param>
/// <param name="type">Bulletの所属チーム</param>
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