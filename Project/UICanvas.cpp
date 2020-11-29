#include "UICanvas.h"

#include "HP.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
CUICanvas::CUICanvas() :
    m_pRenderer() {
	m_Font.Create(20, "UD �f�W�^�� ���ȏ��� NP-B");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CUICanvas::~CUICanvas() {
	m_Font.Release();
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

	CCircle buttonCircle(0, 0, 16);

	buttonCircle.Position = Vector2(g_pGraphics->GetTargetWidth() * 0.1f, g_pGraphics->GetTargetHeight() * 0.125f);
	CGraphicsUtilities::RenderFillCircle(buttonCircle, MOF_COLOR_BLACK);
	buttonCircle.r -= 3;
	CGraphicsUtilities::RenderFillCircle(buttonCircle, MOF_COLOR_GREEN);
	CRectangle fontrect;
	m_Font.CalculateStringRect(0, 0, "A", fontrect);
	Vector2 renPos = buttonCircle.Position - Vector2(fontrect.GetWidth(), fontrect.GetHeight()) * 0.5f;
	m_Font.RenderString(renPos.x, renPos.y, MOF_COLOR_BLACK, "A");
	m_Font.RenderString(buttonCircle.x + buttonCircle.r, renPos.y, MOF_COLOR_WHITE, " :");
	TextureAsset(TextureKey::Bullet_01)->RenderScale(buttonCircle.x + buttonCircle.r + fontrect.GetWidth(), buttonCircle.y - buttonCircle.r, 0.5f);
	buttonCircle.r += 3;
	buttonCircle.Position.x += 100;
	CGraphicsUtilities::RenderFillCircle(buttonCircle, MOF_COLOR_BLACK);
	buttonCircle.r -= 3;
	CGraphicsUtilities::RenderFillCircle(buttonCircle, MOF_COLOR_YELLOW);
	renPos = buttonCircle.Position - Vector2(fontrect.GetWidth(), fontrect.GetHeight()) * 0.5f;
	m_Font.RenderString(renPos.x, renPos.y, MOF_COLOR_BLACK, "L");
	m_Font.RenderString(buttonCircle.x + buttonCircle.r, renPos.y, MOF_COLOR_WHITE, " :");
	TextureAsset(TextureKey::Muscle)->RenderScale(buttonCircle.x + buttonCircle.r + fontrect.GetWidth(), buttonCircle.y - buttonCircle.r, 0.5f);
	buttonCircle.r += 3;
	buttonCircle.Position.x += 100;
	CGraphicsUtilities::RenderFillCircle(buttonCircle, MOF_COLOR_BLACK);
	buttonCircle.r -= 3;
	CGraphicsUtilities::RenderFillCircle(buttonCircle, MOF_COLOR_RED);
	renPos = buttonCircle.Position - Vector2(fontrect.GetWidth(), fontrect.GetHeight()) * 0.5f;
	m_Font.RenderString(renPos.x, renPos.y, MOF_COLOR_BLACK, "B");
	m_Font.RenderString(buttonCircle.x + buttonCircle.r, renPos.y, MOF_COLOR_WHITE, " :");
	TextureAsset(TextureKey::Bullet_03)->RenderScale(buttonCircle.x + buttonCircle.r + fontrect.GetWidth(), buttonCircle.y - buttonCircle.r, 0.5f);

}
   
/// <summary>
/// ���
/// </summary>
void CUICanvas::Release(void) {
    m_pRenderer.reset();
}

CFont & CUICanvas::GetFont(void)
{
	return m_Font;
}
