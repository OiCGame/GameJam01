#pragma once


#include "AssetDefine.h"


class CAudioManager {
private:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CAudioManager();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CAudioManager();
public:
	/// <summary>
	/// �V���O���g��
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static CAudioManager& Singleton(void);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="key">�L�[</param>
	void Play(SoundBufferKey key);
	/// <summary>
	/// �X�V
	/// </summary>
	//void Update(void);
};