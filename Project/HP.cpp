#include "HP.h"

#include <Mof.h>


/// <summary>
/// コンストラクタ
/// </summary>
CHP::CHP() :
    m_Value(100),
    m_ValueMax(100) {
}
/// <summary>
/// デストラクタ
/// </summary>
CHP::~CHP() {
}

/// <summary>
/// ゲッター
/// </summary>
/// <returns>HP</returns>
uint32_t CHP::GetValue(void) const {
    return this->m_Value;
}
/// <summary>
/// ゲッター
/// </summary>
/// <returns>HPの最大値</returns>
uint32_t CHP::GetValueMax(void) const {
    return this->m_ValueMax;
}
/// <summary>
/// レンダラーに登録
/// </summary>
void CHP::RegisterToRenderer(void) {
    auto temp = std::make_shared<CHPRenderer>(shared_from_this());
    CUICanvas::Singleton().SetRenderer(temp);
}

/// <summary>
/// ダメージ
/// </summary>
/// <param name="value">ダメージ値</param>
void CHP::Damage(uint32_t value) {
    m_Value -= value;
    if (m_Value < 0) {
        m_Value = 0;
    } // if
}