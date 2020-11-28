#include "UICanvas.h"

#include "HP.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
CUICanvas::CUICanvas() :
    m_pRenderer() {
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CUICanvas::~CUICanvas() {
}


/// <summary>
/// �V���O���g��
/// </summary>
/// <returns>�C���X�^���X</returns>
CUICanvas& CUICanvas::Singleton(void) {
    static CUICanvas obj;
    return obj;
}

/// <summary>
/// �Z�b�^�[
/// </summary>
/// <param name="ptr">�|�C���^</param>
void CUICanvas::SetRenderer(std::shared_ptr<class CHPRenderer> ptr) {
    this->m_pRenderer = ptr;
}

/// <summary>
/// �`��
/// </summary>
void CUICanvas::Render(void) {
    m_pRenderer->Render();
}
   
/// <summary>
/// ���
/// </summary>
void CUICanvas::Release(void) {
    m_pRenderer.reset();
}