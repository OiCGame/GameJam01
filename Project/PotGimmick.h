#pragma once


#include "Character.h"

#include <Mof.h>

#include "PotFood.h"


/// <summary>
/// ��̃M�~�b�N
/// </summary>
class CPotGimmick : public IObserver {
private:
    //! �ʒu
    CVector2 m_Position;
    //! �e�N�X�`��
    weak_ptr<CTexture> m_pTexture;
    //! ��̋�
    std::vector<PotFood> m_Foods;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CPotGimmick();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CPotGimmick();
    /// <summary>
    /// �C�x���g����
    /// </summary>
    /// <param name="event"></param>
    void OnNotify(void* chara,const char* event) override; 
    /// <summary>
    /// ������
    /// </summary>
    void Initialize(void);
    /// <summary>
    /// �X�V
    /// </summary>
    void Update(void);
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    void Render(void);
};