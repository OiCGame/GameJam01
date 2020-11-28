#include "BulletManager.h"

#include "AssetDefine.h"
#include "HomingBullet.h"
#include "BoomerangBullet.h"
#include "CollisionManager.h"


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

	// 固定量だけBulletを用意する
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
/// 更新
/// </summary>
void CBulletManager::Update(void)
{
	// 非表示のものは削除
	auto it = std::remove_if(
		m_Bullets.begin(),
		m_Bullets.end(),
		[](shared_ptr<CBullet> bullet) {
		return bullet->IsShow() == false; 
	});
	m_Bullets.erase(it, m_Bullets.end());

	// Bulletの更新
	for (auto bullet : m_Bullets)
	{
		bullet->Update();
	} // for

	MOF_PRINTLOG("BulletManager m_Bullets size = %d \n", m_Bullets.size());

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
	// 表示中でないなら撃てるものとする
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