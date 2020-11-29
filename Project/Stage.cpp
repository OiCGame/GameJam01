#include "Stage.h"

CStage::CStage()
{
}

CStage::~CStage()
{
	m_pTexture.reset();
}

float CStage::GetScroll(void) const {
	return this->m_Scroll;
}

void CStage::Initialize(void)
{
	m_Scroll = 0;
	m_pTexture = TextureAsset(TextureKey::Stage);
}

void CStage::Update(void)
{
	m_Scroll += SCROLL_SPEED;
}

void CStage::Render(void)
{
	if (auto r = m_pTexture.lock()) {
		int h = r->GetHeight();
		int sch = g_pGraphics->GetTargetHeight();
		for (float y = ((int)m_Scroll % h) - h; y < sch; y += h)
		{
			r->Render(0.0f, y);
		}
	}


	::CGraphicsUtilities::RenderString(20, 80, "Scroll = %f", m_Scroll);
}
