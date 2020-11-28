#include "Effect.h"
#include "AssetDefine.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
CEffect::CEffect(void)
	: m_pTexture(nullptr)
	, m_AnimationKey()
	, m_Motion()
	, m_bStart(false)
{
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
CEffect::~CEffect(void)
{
}

// ********************************************************************************
/// <summary>
/// テクスチャの設定
/// </summary>
/// <param name="pTexture">設定する画像ポインタ</param>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffect::SetTexture(shared_ptr<CTexture> pTexture)
{
	m_pTexture = pTexture;
}

// ********************************************************************************
/// <summary>
/// アニメーションキーの設定
/// </summary>
/// <param name="key">設定するキー</param>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffect::SetAnimationKey(const AnimationKey & key)
{
	m_AnimationKey = key;
}

// ********************************************************************************
/// <summary>
/// 画像の矩形取得
/// </summary>
/// <returns>矩形</returns>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
CRectangle CEffect::GetRectangle(void) const
{
	CRectangle rect = m_Motion.GetSrcRect();
	rect.Translation(m_Position);
	return rect;
}

// ********************************************************************************
/// <summary>
/// エフェクトの開始フラグ取得
/// </summary>
/// <returns>true : 開始している, false : 開始していない</returns>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
bool CEffect::IsStart(void) const
{
	return m_bStart;
}

// ********************************************************************************
/// <summary>
/// 初期化
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffect::Initialize(void)
{
	LPSpriteAnimationCreate pAnim = AnimationAsset(m_AnimationKey)->GetAnim();
	int animCount = AnimationAsset(m_AnimationKey)->GetAnimationCount();
	m_Motion.Create(pAnim, animCount);
}

// ********************************************************************************
/// <summary>
/// 更新
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffect::Update(void)
{
	if(!m_bStart)
	{
		return;
	}

	if (m_Motion.IsEndMotion())
	{
		m_bStart = false;
	}

	m_Motion.AddTimer(CUtilities::GetFrameSecond());
}

// ********************************************************************************
/// <summary>
/// 描画
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffect::Render(void)
{
	if (!m_bStart || !m_pTexture)
	{
		return;
	}

	m_pTexture->Render(m_Position.x, m_Position.y, m_Motion.GetSrcRect());
}

// ********************************************************************************
/// <summary>
/// 解放
/// </summary>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffect::Release(void)
{
	m_Motion.Release();
}

// ********************************************************************************
/// <summary>
/// エフェクトの開始
/// </summary>
/// <param name="pos">表示する座標</param>
/// <created>いのうえ,2020/11/28</created>
/// <changed>いのうえ,2020/11/28</changed>
// ********************************************************************************
void CEffect::Start(const Vector2& pos)
{
	if (m_bStart)
	{
		return;
	}
	m_Motion.SetTime(0);
	m_bStart   = true;
	m_Position = pos;
}
