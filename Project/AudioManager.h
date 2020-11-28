#pragma once


#include "AssetDefine.h"

#include <Mof.h>


class CAudioManager {
private:
	//! 所持している音声
	std::vector<Mof::CSoundBufferBase> m_pSounds;
	
	std::shared_ptr<Mof::CSoundBufferBase> m_pBgm;

	/// <summary>
	/// コンストラクタ
	/// </summary>
	CAudioManager();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CAudioManager();
public:
	/// <summary>
	/// シングルトン
	/// </summary>
	/// <returns>インスタンス</returns>
	static CAudioManager& Singleton(void);

	/// <summary>
	/// 音声再生
	/// </summary>
	/// <param name="key">キー</param>
	void Play(SoundBufferKey key);
	/// <summary>
	/// 音声再生
	/// </summary>
	/// <param name="key">キー</param>
	void Play(SoundStreamBufferKey key);

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name=""></param>
	void Update(void);
};