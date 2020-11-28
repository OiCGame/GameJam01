#pragma once

//ステージ１の情報を定義する

//敵の出現位置定義
float	g_Stg1EnemyStartPosX[] = {
	100.0f,
	100.0f,
	150.0f,
	100.0f,
	200.0f,

	924.0f,
	924.0f,
	924.0f,
	924.0f,
	924.0f,
};

float	g_srg1EnemyStartScroll[] = {
	100.0f,
	150.0f,
	200.0f,
	250.0f,
	300.0f,

	600.0f,
	650.0f,
	700.0f,
	750.0f,
	800.0f,
};

//敵の開始情報の構造体を作成する
ENEMYSTART g_Stg1EnemyStart = {
	10,
	g_Stg1EnemyStartPosX,
	g_srg1EnemyStartScroll,
};