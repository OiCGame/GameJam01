#pragma once


#include <vector>
#include <memory>


#include "WeaponItem.h"


/// <summary>
/// アイテム管理
/// </summary>
class CWeaponItemManager{
private:
	//! 主人公の武器を変更するアイテムの配列
	vector<shared_ptr<CWeaponItem>>  m_pWeaponItemArray;   
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CWeaponItemManager();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CWeaponItemManager();
public:
	/// <summary>
	/// シングルトン
	/// </summary>
	/// <returns>インスタンス</returns>
	static CWeaponItemManager& Singleton(void);
	/// <summary>
	/// ゲッター
	/// </summary>
	/// <returns>アドレス</returns>
	vector<shared_ptr<CWeaponItem>>& GetArray(void);
	// ********************************************************************************
	/// <summary>
	/// 登録
	/// </summary>
	/// <param name="pItem">アイテム</param>
	// ********************************************************************************
	void Register(const shared_ptr<CWeaponItem>& pItem);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	void Render(void);
};