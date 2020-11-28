#pragma once


#include <memory>

#include <Mof.h>

#include "AssetDefine.h"

using namespace std;

/// <summary>
/// 食べ物
/// </summary>
class PotFood {
private:
    //! 位置
    CVector2 m_Position;
    //! 移動量
    CVector2 m_Move;
    //! 表示画像
    weak_ptr<CTexture> m_pTexture;
    //! 表示矩形
    CRectangle m_RenderRect;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="pos">位置</param>
    PotFood(CVector2 pos, CVector2 move);
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PotFood();
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <returns></returns>
    CVector2 GetPosition(void) const;
    /// <summary>
    /// 移動更新
    /// </summary>
    /// <param name=""></param>
    void Update(void);
    /// <summary>
    /// 描画
    /// </summary>
    /// <param name=""></param>
    void Render(void);
    /// <summary>
    /// 動きを止める
    /// </summary>
    /// <param name=""></param>
    void Stop(void);
};