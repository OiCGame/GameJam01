#include "EffectManager.h"
#include "AssetDefine.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
CEffectManager::CEffectManager(void)
	: m_EffectArray()
{
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
CEffectManager::~CEffectManager(void)
{
}

// ********************************************************************************
/// <summary>
/// 初期化
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffectManager::Initialize(void)
{
	for (int i = 0; i < static_cast<int>(EffectType::Count); i++)
	{
		for (int j = 0; j < EffectMaxCount; j++)
		{
			int keyNo = static_cast<int>(TextureKey::Effect_Barrier) + i;
			m_EffectArray[i][j].SetTexture(TextureAsset(static_cast<TextureKey>(keyNo)));
			keyNo = static_cast<int>(AnimationKey::Effect_Barrier) + i;
			m_EffectArray[i][j].SetAnimationKey(static_cast<AnimationKey>(keyNo));
			m_EffectArray[i][j].Initialize();
		}
	}
}

// ********************************************************************************
/// <summary>
/// 更新
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffectManager::Update(void)
{
	for (int i = 0; i < static_cast<int>(EffectType::Count); i++)
	{
		for (int j = 0; j < EffectMaxCount; j++)
		{
			m_EffectArray[i][j].Update();
		}
	}
}

// ********************************************************************************
/// <summary>
/// 描画
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffectManager::Render(void)
{
	for (int i = 0; i < static_cast<int>(EffectType::Count); i++)
	{
		for (int j = 0; j < EffectMaxCount; j++)
		{
			m_EffectArray[i][j].Render();
		}
	}
}

// ********************************************************************************
/// <summary>
/// 解放
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffectManager::Release(void)
{
	for (int i = 0; i < static_cast<int>(EffectType::Count); i++)
	{
		for (int j = 0; j < EffectMaxCount; j++)
		{
			m_EffectArray[i][j].Release();
		}
	}
}

// ********************************************************************************
/// <summary>
/// エフェクトの開始
/// </summary>
/// <param name="type">エフェクトの種類</param>
/// <param name="pos">表示する座標</param>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffectManager::Start(const EffectType & type, const Vector2 & pos)
{
	for (int i = 0; i < EffectMaxCount; i++)
	{
		if (m_EffectArray[static_cast<int>(type)][i].IsStart())
		{
			continue;
		}
		m_EffectArray[static_cast<int>(type)][i].Start(pos);
		break;
	}
}

// ********************************************************************************
/// <summary>
/// シングルトンの取得
/// </summary>
/// <returns>シングルトン</returns>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
CEffectManager & CEffectManager::Singleton(void)
{
	static CEffectManager singleton;
	return singleton;
}
