#pragma once


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
	/// 音声再生
	/// </summary>
	/// <param name=""></param>
	void Play(void);

	/// <summary>
	/// 更新
	/// </summary>
	//void Update(void);
};