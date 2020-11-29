#pragma once

#include <memory>

#include "Mof.h"

#include "AssetDefine.h"

using namespace std;

#define		SCROLL_SPEED		1

struct ENEMYSTART {
	int		Count;
	float*	PosX;
	float*	Scroll;
};

class CStage
{
private:
	weak_ptr<CTexture> m_pTexture;
	float				 m_Scroll;
public:
	CStage();
	~CStage();

	float GetScroll(void) const;

	void Initialize(void);
	void Update(void);
	void Render(void);
};

