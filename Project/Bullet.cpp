#include "Bullet.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <created>川村,2020/11/28</created>
/// <changed>川村,2020/11/28</changed>
// ********************************************************************************
CBullet::CBullet() :
    m_Position(),
    m_Move(),
    m_pTexture(),
    m_bShow(false),
    m_RenderRect(200.0f, 200.0f, 250.0f, 250.0f),
    m_TeamType() 
{
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>川村,2020/11/28</created>
/// <changed>川村,2020/11/28</changed>
// ********************************************************************************
CBullet::~CBullet() 
{
    m_pTexture.reset();
}

/// <summary>
/// セッター
/// </summary>
/// <param name="tex">ポインタ</param>
void CBullet::SetTexture(shared_ptr<CTexture> tex) 
{
    this->m_pTexture = tex;
}

/// <summary>
/// ゲッター	
/// </summary>
/// <returns>Bulletの所属チーム</returns>
BulletTeamType CBullet::GetTeamType(void) const 
{
    return this->m_TeamType;
}

/// <summary>
/// ゲッター
/// </summary>
/// <returns>表示矩形（衝突矩形）</returns>
CRectangle CBullet::GetRectangle(void) const
{
    return this->m_RenderRect;
}
/// <summary>
/// 表示フラグ取得
/// </summary>
/// <returns>表示していればtrueを返す</returns>
bool CBullet::IsShow(void) const 
{
    return this->m_bShow;
}

/// <summary>
/// 更新
/// </summary>
/// <param name=""></param>
void CBullet::Update(void) 
{
    // 表示フラグが立っていないなら処理しない
    if (!this->IsShow()) {
        return;
    } // if

    // 移動量更新
    m_Position += m_Move;

    // はみ出たら非表示にする
    if (::g_pFramework->GetWindow()->GetWidth() < m_Position.x) {
        this->m_bShow = false;
    } // if
}

/// <summary>
/// 描画
/// </summary>
/// <param name="scroll">スクロール値</param>
void CBullet::Render(CVector2 scroll) 
{
    // 表示フラグが立っていないなら処理しない
    if (!this->IsShow()) {
        return;
    } // if

    // 描画
    if (auto r = m_pTexture.lock()) {
        auto pos = m_Position + scroll;
        r->Render(pos.x, pos.y, m_RenderRect);
    } // if
}

/// <summary>
/// 発射
/// </summary>
/// <param name="position">発射位置</param>
/// <param name="move">更新移動量</param>
/// <param name="type">所属チーム</param>
void CBullet::Fire(CVector2 position, CVector2 move, BulletTeamType type) 
{
    this->m_Position = position;
    this->m_Move = move;
    this->m_bShow = true;
    this->m_TeamType = type;
}