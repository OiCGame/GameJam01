#pragma once


#include <memory>

#include <Mof.h>


using namespace std;


/// <summary>
/// ��������^�C�v
/// </summary>
enum class BulletTeamType
{
	Player,
	Enemy,
};

// ********************************************************************************
/// <summary>
/// �e�ۃN���X
/// </summary>
// ********************************************************************************
class CBullet : public enable_shared_from_this<CBullet>
{
protected:
	//! �ʒu
	CVector2 m_Position;
	//! �X�V���ɑ������܂��ړ���
	CVector2 m_Move;
	//! �\���摜
	weak_ptr<CTexture> m_pTexture;
	//! �\���t���O
	bool m_bShow;
	//! �\����`
	CRectangle m_RenderRect;
	//! �G�����������ǂ���
	BulletTeamType m_TeamType;
public:
	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <created>�쑺,2020/11/28</created>
	/// <changed>�쑺,2020/11/28</changed>
	// ********************************************************************************
	CBullet();
	// ********************************************************************************
    /// �f�X�g���N�^
    /// <created>�쑺,2020/11/28</created>
    /// <changed>�쑺,2020/11/28</changed>
    // ********************************************************************************
	~CBullet();
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name="tex">�|�C���^</param>
	void SetTexture(const shared_ptr<CTexture>& tex);
	/// <summary>
	/// �Q�b�^�[	
	/// </summary>
	/// <returns>Bullet�̏����`�[��</returns>
	BulletTeamType GetTeamType(void) const;	
	/// <summary>
	/// �Q�b�^�[
	/// </summary>
	/// <returns>�Փˋ�`</returns>
	virtual CRectangle GetRectangle(void) const;
	/// <summary>
	/// �\���t���O�擾
	/// </summary>
	/// <returns>�\�����Ă����true��Ԃ�</returns>
	bool IsShow(void) const;
	/// <summary>
	/// �X�V
	/// </summary>
	virtual void Update(void);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="scroll">�X�N���[���l</param>
	void Render(CVector2 scroll);
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="position">���ˈʒu</param>
	/// <param name="move">�X�V�ړ���</param>
	/// <param name="type">�����`�[��</param>
	virtual void Fire(CVector2 position, CVector2 move, BulletTeamType type);
	/// <summary>
	/// �\���I��
	/// </summary>
	void Hide(void);
};