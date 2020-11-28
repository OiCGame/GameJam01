#pragma once

//ステージ１の情報を定義する

//敵の出現位置定義
float	g_Stg1EnemyStartPosX[] = {
	100.0f,
	100.0f,
	100.0f,
	100.0f,
	100.0f,

	924.0f,
	924.0f,
	924.0f,
	924.0f,
	924.0f,
};

float	g_srg1EnemyStartScroll[] = {
	100.0f,
	400.0f,
	700.0f,
	1000.0f,
	1300.0f,

	1600.0f,
	1900.0f,
	2200.0f,
	2500.0f,
	2800.0f,
};

//敵の開始情報の構造体を作成する
ENEMYSTART g_Stg1EnemyStart = {
	10,
	g_Stg1EnemyStartPosX,
	g_srg1EnemyStartScroll,
};