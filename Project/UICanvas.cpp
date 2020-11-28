#include "UICanvas.h"

#include "HP.h"


/// <summary>
/// コンストラクタ
/// </summary>
CUICanvas::CUICanvas() :
    m_pRenderer() {
}

/// <summary>
/// デストラクタ
/// </summary>
CUICanvas::~CUICanvas() {
}


/// <summary>
/// シングルトン
/// </summary>
/// <returns>インスタンス</returns>
CUICanvas& CUICanvas::Singleton(void) {
    static CUICanvas obj;
    return obj;
}

/// <summary>
/// セッター
/// </summary>
/// <param name="ptr">ポインタ</param>
void CUICanvas::SetRenderer(std::shared_ptr<class CHPRenderer> ptr) {
    this->m_pRenderer = ptr;
}

/// <summary>
/// 描画
/// </summary>
void CUICanvas::Render(void) {
    m_pRenderer->Render();
}
   
/// <summary>
/// 解放
/// </summary>
void CUICanvas::Release(void) {
    m_pRenderer.reset();
}