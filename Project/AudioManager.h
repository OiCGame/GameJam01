#pragma once


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
	/// �����Đ�
	/// </summary>
	/// <param name=""></param>
	void Play(void);

	/// <summary>
	/// �X�V
	/// </summary>
	//void Update(void);
};