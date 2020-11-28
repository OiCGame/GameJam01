#pragma once


#include <vector>

#include <Mof.h>

#include "AssetDefine.h"


class CAudioManager {
private:
	//! 所持している音声
	std::vector<std::shared_ptr<Mof::CSoundBufferBase>> m_pSounds;
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
	/// 読み込み
	/// </summary>
	/// <returns>成功したらtrueを返す</returns>
	bool Load(void);
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name=""></param>
	void Update(void);
	/// <summary>
	/// 解放
	/// </summary>
	void Release(void);
};