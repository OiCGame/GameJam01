#pragma once


#include "../include/rapidjson/document.h"



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

/**
* @brief : jsonファイルを読み込む
* @param : [in](const char* path) 配列
* @param : [out](rapidjson::Document& document) データの格納先
* @return : 読み込みに成功したらtrueを返す
*/
static bool LoadJsonDocument(const char* path, rapidjson::Document& document) {
	std::ifstream file(path);
	// ファイルを開けないならfalseを返す
	if (!file.is_open()) {
		return false;
	} // if
	// 読み込み
	std::stringstream stream;
	stream << file.rdbuf();
	std::string temp = stream.str();
	rapidjson::StringStream str(temp.c_str());
	document.ParseStream(str);
	return true;
}