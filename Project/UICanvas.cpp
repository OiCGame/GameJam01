#include "UICanvas.h"

#include "HP.h"


CUICanvas::CUICanvas() :
    m_pRenderer() {
}
CUICanvas::~CUICanvas() {
}

CUICanvas& CUICanvas::Singleton(void) {
    static CUICanvas obj;
    return obj;
}

void CUICanvas::SetRenderer(std::shared_ptr<class CHPRenderer> ptr) {
    this->m_pRenderer = ptr;
}

void CUICanvas::Render(void) {
    m_pRenderer->Render();
}
