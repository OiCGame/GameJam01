#pragma once


#include <Mof.h>

#include "UICanvas.h"
#include "AssetDefine.h"


static void Rotate(float& pos_x, float& pos_y, const float radian,
            const float center_x, const float center_y) {
    float axis_x = pos_x - center_x;
    float axis_y = pos_y - center_y;

    float translate_x = (axis_x)*std::cosf(radian) - (axis_y)*std::sinf(radian);
    float translate_y = (axis_x)*std::sinf(radian) + (axis_y)*std::cosf(radian);

    pos_x = center_x + translate_x;
    pos_y = center_y + translate_y;
};


/// <summary>
/// HP
/// </summary>
class CHP : public std::enable_shared_from_this<CHP> {
private:
    //! HP�̍ő�l
    const uint32_t m_ValueMax;
    //! HP�̒l
    int m_Value;
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
    /// �Q�b�^�[
    /// </summary>
    /// <param name="">HP�̍ő�l</param>
    /// <returns></returns>
//    uint32_t GetValueMax(void) const;
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
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="ptr">�`��Ώ�</param>
    CHPRenderer(std::shared_ptr<CHP> ptr) :
        m_pHP(ptr) {
    }
    /// <summary>
    /// �`��
    /// </summary>
    void Render(void) {
        uint32_t value = m_pHP->GetValue();
            if (auto tex = TextureAsset(TextureKey::HPFrame)) {
                tex->Render(10.0f, 10.0f);
        } // 
        if (auto tex = TextureAsset(TextureKey::HP)) {
            CRectangle rect(
                0, 0, tex->GetWidth() * (value * 0.01f), tex->GetHeight());
            tex->Render(10.0f + 150.0f, 10.0f + 64.0f, rect);
        } // if


        /*
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
        */
    }

};

