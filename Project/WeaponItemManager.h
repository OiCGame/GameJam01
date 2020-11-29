#pragma once


#include <vector>
#include <memory>


#include "WeaponItem.h"


/// <summary>
/// �A�C�e���Ǘ�
/// </summary>
class CWeaponItemManager{
private:
	//! ��l���̕����ύX����A�C�e���̔z��
	vector<shared_ptr<CWeaponItem>>  m_pWeaponItemArray;   
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CWeaponItemManager();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CWeaponItemManager();
public:
	/// <summary>
	/// �V���O���g��
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static CWeaponItemManager& Singleton(void);
	/// <summary>
	/// �Q�b�^�[
	/// </summary>
	/// <returns>�A�h���X</returns>
	vector<shared_ptr<CWeaponItem>>& GetArray(void);
	// ********************************************************************************
	/// <summary>
	/// �o�^
	/// </summary>
	/// <param name="pItem">�A�C�e��</param>
	// ********************************************************************************
	void Register(const shared_ptr<CWeaponItem>& pItem);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name=""></param>
	void Render(void);
};