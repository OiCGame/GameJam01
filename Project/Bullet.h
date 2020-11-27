#pragma once


#include <memory>

#include <Mof.h>

using namespace std;


// ********************************************************************************
/// <summary>
/// キャラクタークラス
/// </summary>
// ********************************************************************************
class CBullet
{
protected:
	//! 位置
	CVector2 m_Position;
	//! 更新時に足しこまれる移動量
	CVector2 m_Move;
	//! 表示画像
	weak_ptr<CTexture> m_pTexture;
public:
	// ********************************************************************************
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <created>川村,2020/11/28</created>
	/// <changed>川村,2020/11/28</changed>
	// ********************************************************************************
	CBullet();
	~CBullet();

	void SetTexture(shared_ptr<CTexture> tex);

	void Fire(CVector2 position, CVector2 move);
	void Update(void);
	void Render(CVector2 scroll);
};