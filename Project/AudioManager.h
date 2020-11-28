#pragma once


#include <vector>

#include <Mof.h>

#include "AssetDefine.h"


class CAudioManager {
private:
	//! �������Ă��鉹��
	std::vector<std::shared_ptr<Mof::CSoundBufferBase>> m_pSounds;
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
	/// �����Đ�
	/// </summary>
	/// <param name="key">�L�[</param>
	void Play(SoundBufferKey key);
	/// <summary>
	/// �����Đ�
	/// </summary>
	/// <param name="key">�L�[</param>
	void Play(SoundStreamBufferKey key);
	/// <summary>
	/// �ǂݍ���
	/// </summary>
	/// <returns>����������true��Ԃ�</returns>
	bool Load(void);
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name=""></param>
	void Update(void);
	/// <summary>
	/// ���
	/// </summary>
	void Release(void);
};