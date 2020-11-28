#pragma once


#include "Character.h"


class CCharacterManager {
private:
	// 管理対象
	std::vector<std::shared_ptr<CCharacter>>m_pCharacter;
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CCharacterManager();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CCharacterManager();
public:
	/// <summary>
	/// シングルトン
	/// </summary>
	/// <returns>インスタンス</returns>
	static CCharacterManager& Singleton(void);
	/// <summary>
	/// 初期化
	/// </summary>
	/// <returns>成功したらtueを返す</returns>
//	bool Initialize(void);
	/// <summary>
	/// 更新
	/// </summary>
	void Update(void);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="scroll">スクロール値</param>
	void Render(CVector2 scroll);
	/// <summary>
	/// 解放
	/// </summary>
	void Release(void);
	/// <summary>
	/// 管理対象の追加
	/// </summary>
	/// <param name="ptr"></param>
	void AddCharacter(const std::shared_ptr<CCharacter>& ptr);
};