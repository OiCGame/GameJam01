#pragma once


#include "../include/rapidjson/document.h"



//�X�e�[�W�P�̏����`����

//�G�̏o���ʒu��`
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


//�G�̊J�n���̍\���̂��쐬����
ENEMYSTART g_Stg1EnemyStart = {
	10,
	g_Stg1EnemyStartPosX,
	g_srg1EnemyStartScroll,
};

/**
* @brief : json�t�@�C����ǂݍ���
* @param : [in](const char* path) �z��
* @param : [out](rapidjson::Document& document) �f�[�^�̊i�[��
* @return : �ǂݍ��݂ɐ���������true��Ԃ�
*/
static bool LoadJsonDocument(const char* path, rapidjson::Document& document) {
	std::ifstream file(path);
	// �t�@�C�����J���Ȃ��Ȃ�false��Ԃ�
	if (!file.is_open()) {
		return false;
	} // if
	// �ǂݍ���
	std::stringstream stream;
	stream << file.rdbuf();
	std::string temp = stream.str();
	rapidjson::StringStream str(temp.c_str());
	document.ParseStream(str);
	return true;
}