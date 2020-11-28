#pragma once


#include "Character.h"

#include <Mof.h>

#include "PotFood.h"


/// <summary>
/// 鍋のギミック
/// </summary>
class CPotGimmick : public IObserver {
private:
    //! 位置
    CVector2 m_Position;
    //! テクスチャ
    weak_ptr<CTexture> m_pTexture;
    //! 倒した敵たちの表示位置
//    std::vector<Mof::CVector2> m_FoodPositions;

    std::vector<PotFood> m_Foods;
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

};