#pragma once

#include <memory>

#include "Mof.h"

#include "AssetDefine.h"

using namespace std;

#define		SCROLL_SPEED		1

//敵の出現情報構造体
typedef struct tag_ENEMYSTART {
	int			Count;
	float*		PosX;
	float*		Scroll;
}ENEMYSTART;

class CStage
{
private:
	weak_ptr<CTexture> m_pTexture;
	float				 m_Scroll;
public:
	CStage();
	~CStage();
	float GetScroll(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
};

