#pragma once


#include <memory>

#include <Mof.h>


using namespace std;

/// <summary>
/// ����ύX�A�C�e��
/// </summary>
class CWeaponItem {
private:
    //! �^�C�v
    int m_Type;
    //! �\���ʒu
    CVector2 m_Position;
    //! �\���摜
    weak_ptr<CTexture> m_pTexture;
    //! �\����`
    CRectangle m_RenderRect;
    //! �\���t���O
    bool m_bShow;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CWeaponItem(CVector2 pos);
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CWeaponItem();
    /// <summary>
    /// �ύX����镐��̖��O
    /// </summary>
    /// <returns>���O</returns>
    const char* GetWeaponType(void);
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <returns>�Փˋ�`</returns>
    CRectangle GetRectangle(void) const;
    /// <summary>
    /// �E�C���h�E�̊O�ɂ��邩���肷��
    /// </summary>
    /// <returns>�E�C���h�E�O�ł����true��Ԃ�</returns>
    bool IsShow(void) const;
    /// <summary>
    /// �`��
    /// </summary>
    void Render(void);
    /// <summary>
    /// �g�p show��false�ɂ���
    /// </summary>
    void Use(void);
};