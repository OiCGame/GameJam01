#pragma once


#include "Character.h"

#include <Mof.h>

#include "PotFood.h"

constexpr int FoodCountMax = 9;

/// <summary>
/// 鍋のギミック
/// </summary>
class CPotGimmick : public IObserver {
private:
    //! 位置
    CVector2 m_Position;
    //! テクスチャ
    weak_ptr<CTexture> m_pTexture;
    //! 鍋の具
    std::vector<CPotFood> m_Foods;
	//! フードの数
	int m_FoodCount;
	//! たまった音用フラグ
	bool m_bCharge;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CPotGimmick();
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CPotGimmick();
    /// <summary>
    /// イベント処理
    /// </summary>
    /// <param name="event"></param>
    void OnNotify(void* chara,const char* event) override; 
    /// <summary>
    /// 入力処理
    /// </summary>
    void Input(void);
    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize(void);
    /// <summary>
    /// 更新
    /// </summary>
    void Update(void);
    /// <summary>
    /// 描画
    /// </summary>
    /// <param name=""></param>
    void Render(void);

	bool IsAllrady(void) const;

	void ResetPotFoods(void);
};