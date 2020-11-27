#pragma once
#include "Mof.h"

enum class AnimationKey;

using namespace std;

// ********************************************************************************
/// <summary>
/// �G�t�F�N�g�N���X
/// </summary>
// ********************************************************************************
class CEffect
{
private:

	shared_ptr<CTexture>      m_pTexture;     //! �摜�|�C���^

	AnimationKey              m_AnimationKey; //! �A�j���[�V�����p�L�[

	CSpriteMotionController   m_Motion;       //! ���[�V����

	bool                      m_bStart;       //! �J�n�t���O

	Vector2                   m_Position;     //! �\�����W

public:

	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	CEffect(void);

	// ********************************************************************************
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	~CEffect(void);

	// ********************************************************************************
	/// <summary>
	/// �e�N�X�`���̐ݒ�
	/// </summary>
	/// <param name="pTexture">�ݒ肷��摜�|�C���^</param>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void SetTexture(shared_ptr<CTexture> pTexture);

	// ********************************************************************************
	/// <summary>
	/// �A�j���[�V�����L�[�̐ݒ�
	/// </summary>
	/// <param name="key">�ݒ肷��L�[</param>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void SetAnimationKey(const AnimationKey& key);

	// ********************************************************************************
	/// <summary>
	/// �摜�̋�`�擾
	/// </summary>
	/// <returns>��`</returns>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	CRectangle GetRectangle(void) const;

	// ********************************************************************************
	/// <summary>
	/// �G�t�F�N�g�̊J�n�t���O�擾
	/// </summary>
	/// <returns>true : �J�n���Ă���, false : �J�n���Ă��Ȃ�</returns>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	bool IsStart(void) const;

	// ********************************************************************************
	/// <summary>
	/// ������
	/// </summary>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void Initialize(void);

	// ********************************************************************************
	/// <summary>
	/// �X�V
	/// </summary>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void Update(void);

	// ********************************************************************************
	/// <summary>
	/// �`��
	/// </summary>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void Render(void);

	// ********************************************************************************
	/// <summary>
	/// ���
	/// </summary>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void Release(void);

	// ********************************************************************************
	/// <summary>
	/// �G�t�F�N�g�̊J�n
	/// </summary>
	/// <param name="pos">�\��������W</param>
	/// <created>���̂���,2020/11/28</created>
	/// <changed>���̂���,2020/11/28</changed>
	// ********************************************************************************
	void Start(const Vector2& pos);
};
