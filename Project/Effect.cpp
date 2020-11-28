#include "Effect.h"
#include "AssetDefine.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
CEffect::CEffect(void)
	: m_pTexture(nullptr)
	, m_AnimationKey()
	, m_Motion()
	, m_bStart(false)
{
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
CEffect::~CEffect(void)
{
}

// ********************************************************************************
/// <summary>
/// �e�N�X�`���̐ݒ�
/// </summary>
/// <param name="pTexture">�ݒ肷��摜�|�C���^</param>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffect::SetTexture(shared_ptr<CTexture> pTexture)
{
	m_pTexture = pTexture;
}

// ********************************************************************************
/// <summary>
/// �A�j���[�V�����L�[�̐ݒ�
/// </summary>
/// <param name="key">�ݒ肷��L�[</param>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffect::SetAnimationKey(const AnimationKey & key)
{
	m_AnimationKey = key;
}

// ********************************************************************************
/// <summary>
/// �摜�̋�`�擾
/// </summary>
/// <returns>��`</returns>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
CRectangle CEffect::GetRectangle(void) const
{
	CRectangle rect = m_Motion.GetSrcRect();
	rect.Translation(m_Position);
	return rect;
}

// ********************************************************************************
/// <summary>
/// �G�t�F�N�g�̊J�n�t���O�擾
/// </summary>
/// <returns>true : �J�n���Ă���, false : �J�n���Ă��Ȃ�</returns>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
bool CEffect::IsStart(void) const
{
	return m_bStart;
}

// ********************************************************************************
/// <summary>
/// ������
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffect::Initialize(void)
{
	LPSpriteAnimationCreate pAnim = AnimationAsset(m_AnimationKey)->GetAnim();
	int animCount = AnimationAsset(m_AnimationKey)->GetAnimationCount();
	m_Motion.Create(pAnim, animCount);
}

// ********************************************************************************
/// <summary>
/// �X�V
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffect::Update(void)
{
	if(!m_bStart)
	{
		return;
	}

	if (m_Motion.IsEndMotion())
	{
		m_bStart = false;
	}

	m_Motion.AddTimer(CUtilities::GetFrameSecond());
}

// ********************************************************************************
/// <summary>
/// �`��
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffect::Render(void)
{
	if (!m_bStart || !m_pTexture)
	{
		return;
	}

	m_pTexture->Render(m_Position.x, m_Position.y, m_Motion.GetSrcRect());
}

// ********************************************************************************
/// <summary>
/// ���
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffect::Release(void)
{
	m_Motion.Release();
}

// ********************************************************************************
/// <summary>
/// �G�t�F�N�g�̊J�n
/// </summary>
/// <param name="pos">�\��������W</param>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffect::Start(const Vector2& pos)
{
	if (m_bStart)
	{
		return;
	}
	m_Motion.SetTime(0);
	m_bStart   = true;
	m_Position = pos;
}
