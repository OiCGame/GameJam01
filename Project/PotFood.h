#pragma once


#include <memory>

#include <Mof.h>

#include "AssetDefine.h"

using namespace std;

/// <summary>
/// �H�ו�
/// </summary>
class CPotFood {
private:
    //! �ʒu
    CVector2 m_Position;
    //! �ړ���
    CVector2 m_Move;
    //! �\���摜
    weak_ptr<CTexture> m_pTexture;
    //! �\����`
    CRectangle m_RenderRect;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="pos">�ʒu</param>
    CPotFood(CVector2 pos, CVector2 move);
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CPotFood();
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <returns></returns>
    CVector2 GetPosition(void) const;
    /// <summary>
    /// �ړ��X�V
    /// </summary>
    /// <param name=""></param>
    void Update(void);
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    void Render(void);
    /// <summary>
    /// �������~�߂�
    /// </summary>
    /// <param name=""></param>
    void Stop(void);
};