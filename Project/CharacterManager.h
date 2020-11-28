#pragma once


#include "Character.h"


class CCharacterManager {
private:
	// �Ǘ��Ώ�
	std::vector<std::shared_ptr<CCharacter>>m_pCharacter;
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CCharacterManager();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CCharacterManager();
public:
	/// <summary>
	/// �V���O���g��
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static CCharacterManager& Singleton(void);
	/// <summary>
	/// ������
	/// </summary>
	/// <returns>����������tue��Ԃ�</returns>
//	bool Initialize(void);
	/// <summary>
	/// �X�V
	/// </summary>
	void Update(void);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="scroll">�X�N���[���l</param>
	void Render(CVector2 scroll);
	/// <summary>
	/// ���
	/// </summary>
	void Release(void);
	/// <summary>
	/// �Ǘ��Ώۂ̒ǉ�
	/// </summary>
	/// <param name="ptr"></param>
	void AddCharacter(const std::shared_ptr<CCharacter>& ptr);
};