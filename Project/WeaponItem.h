#pragma once


#include <memory>

#include <Mof.h>


using namespace std;

/// <summary>
/// 武器変更アイテム
/// </summary>
class CWeaponItem {
private:
    //! タイプ
    int m_Type;
    //! 表示位置
    CVector2 m_Position;
    //! 表示画像
    weak_ptr<CTexture> m_pTexture;
    //! 表示矩形
    CRectangle m_RenderRect;
    //! 表示フラグ
    bool m_bShow;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CWeaponItem(CVector2 pos);
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CWeaponItem();
    /// <summary>
    /// 変更される武器の名前
    /// </summary>
    /// <returns>名前</returns>
    const char* GetWeaponType(void);
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <returns>衝突矩形</returns>
    CRectangle GetRectangle(void) const;
    /// <summary>
    /// ウインドウの外にあるか判定する
    /// </summary>
    /// <returns>ウインドウ外であればtrueを返す</returns>
    bool IsShow(void) const;
    /// <summary>
    /// 描画
    /// </summary>
    void Render(void);
    /// <summary>
    /// 使用 showをfalseにする
    /// </summary>
    void Use(void);
};