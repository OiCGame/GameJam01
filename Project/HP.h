#pragma once


#include <Mof.h>

#include "UICanvas.h"


/// <summary>
/// HP
/// </summary>
class CHP : public std::enable_shared_from_this<CHP> {
private:
    //! HPの値
    uint32_t m_Value;
    //! HPの最大値
    uint32_t m_ValueMax;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CHP();
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CHP();
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name="">HP</param>
    /// <returns></returns>
    uint32_t GetValue(void) const;
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name="">HPの最大値</param>
    /// <returns></returns>
    uint32_t GetValueMax(void) const;
    /// <summary>
    /// レンダラーに登録
    /// </summary>
    /// <param name=""></param>
    void RegisterToRenderer(void);
    /// <summary>
    /// ダメージ
    /// </summary>
    /// <param name="value">ダメージ量</param>
    void Damage(uint32_t value);
};

// (UIRenderer)
class CHPRenderer {
private:
    //! 描画対象
    std::shared_ptr<CHP> m_pHP;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="ptr">描画対象</param>
    CHPRenderer(std::shared_ptr<CHP> ptr) :
        m_pHP(ptr) {
    }
    /// <summary>
    /// 描画
    /// </summary>
    void Render(void) {

        uint32_t length = 1.0f;
        {
            uint32_t value = m_pHP->GetValueMax();
            auto rect = Mof::CRectangle(0.0f, 100.0f, value * length, 200.0f);
            ::CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_RED);
        }
        {
            uint32_t value = m_pHP->GetValue();
            auto rect = Mof::CRectangle(0.0f, 100.0f, value * length, 200.0f);
            ::CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_GREEN);
        }
        
    }

};

