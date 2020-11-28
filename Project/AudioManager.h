#pragma once


#include "AssetDefine.h"


class CAudioManager {
private:
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
	/// 
	/// </summary>
	/// <param name="key">キー</param>
	void Play(SoundBufferKey key);
	/// <summary>
	/// 更新
	/// </summary>
	//void Update(void);
};