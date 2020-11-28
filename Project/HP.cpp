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

/// <summary>
/// �Q�b�^�[
/// </summary>
/// <returns>HP</returns>
uint32_t CHP::GetValue(void) const {
    return this->m_Value;
}
/// <summary>
/// �Q�b�^�[
/// </summary>
/// <returns>HP�̍ő�l</returns>
uint32_t CHP::GetValueMax(void) const {
    return this->m_ValueMax;
}
/// <summary>
/// �����_���[�ɓo�^
/// </summary>
void CHP::RegisterToRenderer(void) {
    auto temp = std::make_shared<CHPRenderer>(shared_from_this());
    CUICanvas::Singleton().SetRenderer(temp);
}

/// <summary>
/// �_���[�W
/// </summary>
/// <param name="value">�_���[�W�l</param>
void CHP::Damage(uint32_t value) {
    m_Value -= value;
    if (m_Value < 0) {
        m_Value = 0;
    } // if
}