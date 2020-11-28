#pragma once


#include <stdint.h>

#include <Mof.h>

#include "UICanvas.h"


/// <summary>
/// HP
/// </summary>
class CHP : public std::enable_shared_from_this<CHP> {
private:
    //! HP�̒l
    uint32_t m_Value;
    //! HP�̍ő�l
    uint32_t m_ValueMax;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CHP();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CHP();
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name="">HP</param>
    /// <returns></returns>
    uint32_t GetValue(void) const;
    /// <summary>
    /// �����_���[�ɓo�^
    /// </summary>
    /// <param name=""></param>
    void RegisterToRenderer(void);

    /// <summary>
    /// �_���[�W
    /// </summary>
    /// <param name="value">�_���[�W��</param>
    void Damage(uint32_t value);
};

// (UIRenderer)
class CHPRenderer {
private:
    //! �`��Ώ�
    std::shared_ptr<CHP> m_pHP;
public:
    CHPRenderer(std::shared_ptr<CHP> ptr) :
        m_pHP(ptr) {
    }

    void Render(void) {
        uint32_t value = m_pHP->GetValue();
        
        auto rect = Mof::CRectangle(0.0f, 100.0f, value, 200.0f);
        ::CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_BLACK);
    }

};

