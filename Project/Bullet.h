#pragma once


#include <memory>

#include <Mof.h>

using namespace std;


// ********************************************************************************
/// <summary>
/// �L�����N�^�[�N���X
/// </summary>
// ********************************************************************************
class CBullet
{
protected:
	//! �ʒu
	CVector2 m_Position;
	//! �X�V���ɑ������܂��ړ���
	CVector2 m_Move;
	//! �\���摜
	weak_ptr<CTexture> m_pTexture;
public:
	// ********************************************************************************
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <created>�쑺,2020/11/28</created>
	/// <changed>�쑺,2020/11/28</changed>
	// ********************************************************************************
	CBullet();
	~CBullet();

	void SetTexture(shared_ptr<CTexture> tex);

	void Fire(CVector2 position, CVector2 move);
	void Update(void);
	void Render(CVector2 scroll);
};