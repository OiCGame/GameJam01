#include "HP.h"

#include <Mof.h>


/// <summary>
/// �R���X�g���N�^
/// </summary>
CHP::CHP() :
    m_Value(100),
    m_ValueMax(100) {
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
CHP::~CHP() {
}

uint32_t CHP::GetValue(void) const {
    return this->m_Value;
}

void CHP::RegisterToRenderer(void) {
    auto temp = std::make_shared<CHPRenderer>(shared_from_this());
    CUICanvas::Singleton().SetRenderer(temp);
}

void CHP::Damage(uint32_t value) {
    m_Value -= value;
    if (m_Value < 0) {
        m_Value = 0;
    } // if
}