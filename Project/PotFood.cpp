#include "PotFood.h"

#include "AssetDefine.h"


PotFood::PotFood(CVector2 pos, CVector2 move) {
	m_Position = pos;
	m_Move = move;
	m_pTexture = TextureAsset(TextureKey::Enemy01);
	// •\Ž¦‹éŒ`Ý’è
	if (auto r = m_pTexture.lock()) {
		m_RenderRect = CRectangle(
			0.0f, 0.0f,
			r->GetWidth(), r->GetHeight());
	} // if
}

PotFood::~PotFood() {
}

CVector2 PotFood::GetPosition(void) const {
	return this->m_Position;
}

void PotFood::Update(void) {
	m_Position += m_Move;
}

void PotFood::Render(void) {
	if (auto tex = m_pTexture.lock()) {
		tex->Render(m_Position.x, m_Position.y);
	} // if
}

void PotFood::Stop(void) {
	m_Move = CVector2();
}