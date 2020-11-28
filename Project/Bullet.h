#pragma once


#include <memory>

#include <Mof.h>


using namespace std;


/// <summary>
/// 所属するタイプ
/// </summary>
enum class BulletTeamType
{
	Player,
	Enemy,
};

// ********************************************************************************
/// <summary>
/// 弾丸クラス
/// </summary>
// ********************************************************************************
class CBullet : public enable_shared_from_this<CBullet>
{
protected:
	//! 位置
	CVector2 m_Position;
	//! 更新時に足しこまれる移動量
	CVector2 m_Move;
	//! 表示画像
	weak_ptr<CTexture> m_pTexture;
	//! 表示フラグ
	bool m_bShow;
	//! 表示矩形
	CRectangle m_RenderRect;
	//! 敵が撃ったかどうか
	BulletTeamType m_TeamType;
public:
	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <created>川村,2020/11/28</created>
	/// <changed>川村,2020/11/28</changed>
	// ********************************************************************************
	CBullet();
	// ********************************************************************************
    /// デストラクタ
    /// <created>川村,2020/11/28</created>
    /// <changed>川村,2020/11/28</changed>
    // ********************************************************************************
	~CBullet();
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name="tex">ポインタ</param>
	void SetTexture(const shared_ptr<CTexture>& tex);
	/// <summary>
	/// ゲッター	
	/// </summary>
	/// <returns>Bulletの所属チーム</returns>
	BulletTeamType GetTeamType(void) const;	
	/// <summary>
	/// ゲッター
	/// </summary>
	/// <returns>衝突矩形</returns>
	virtual CRectangle GetRectangle(void) const;
	/// <summary>
	/// 表示フラグ取得
	/// </summary>
	/// <returns>表示していればtrueを返す</returns>
	bool IsShow(void) const;
	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update(void);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="scroll">スクロール値</param>
	void Render(CVector2 scroll);
	/// <summary>
	/// 発射
	/// </summary>
	/// <param name="position">発射位置</param>
	/// <param name="move">更新移動量</param>
	/// <param name="type">所属チーム</param>
	virtual void Fire(CVector2 position, CVector2 move, BulletTeamType type);
	/// <summary>
	/// 表示終了
	/// </summary>
	void Hide(void);
};