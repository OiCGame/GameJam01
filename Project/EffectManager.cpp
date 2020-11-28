#include "EffectManager.h"
#include "AssetDefine.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
CEffectManager::CEffectManager(void)
	: m_EffectArray()
{
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
CEffectManager::~CEffectManager(void)
{
}

// ********************************************************************************
/// <summary>
/// ������
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffectManager::Initialize(void)
{
	for (int i = 0; i < static_cast<int>(EffectType::Count); i++)
	{
		for (int j = 0; j < EffectMaxCount; j++)
		{
			int keyNo = static_cast<int>(TextureKey::Effect_Barrier) + i;
			m_EffectArray[i][j].SetTexture(TextureAsset(static_cast<TextureKey>(keyNo)));
			keyNo = static_cast<int>(AnimationKey::Effect_Barrier) + i;
			m_EffectArray[i][j].SetAnimationKey(static_cast<AnimationKey>(keyNo));
			m_EffectArray[i][j].Initialize();
		}
	}
}

// ********************************************************************************
/// <summary>
/// �X�V
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffectManager::Update(void)
{
	for (int i = 0; i < static_cast<int>(EffectType::Count); i++)
	{
		for (int j = 0; j < EffectMaxCount; j++)
		{
			m_EffectArray[i][j].Update();
		}
	}
}

// ********************************************************************************
/// <summary>
/// �`��
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffectManager::Render(void)
{
	for (int i = 0; i < static_cast<int>(EffectType::Count); i++)
	{
		for (int j = 0; j < EffectMaxCount; j++)
		{
			m_EffectArray[i][j].Render();
		}
	}
}

// ********************************************************************************
/// <summary>
/// ���
/// </summary>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffectManager::Release(void)
{
	for (int i = 0; i < static_cast<int>(EffectType::Count); i++)
	{
		for (int j = 0; j < EffectMaxCount; j++)
		{
			m_EffectArray[i][j].Release();
		}
	}
}

// ********************************************************************************
/// <summary>
/// �G�t�F�N�g�̊J�n
/// </summary>
/// <param name="type">�G�t�F�N�g�̎��</param>
/// <param name="pos">�\��������W</param>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
void CEffectManager::Start(const EffectType & type, const Vector2 & pos)
{
	for (int i = 0; i < EffectMaxCount; i++)
	{
		if (m_EffectArray[static_cast<int>(type)][i].IsStart())
		{
			continue;
		}
		m_EffectArray[static_cast<int>(type)][i].Start(pos);
		break;
	}
}

// ********************************************************************************
/// <summary>
/// �V���O���g���̎擾
/// </summary>
/// <returns>�V���O���g��</returns>
/// <created>���̂���,2020/11/28</created>
/// <changed>���̂���,2020/11/28</changed>
// ********************************************************************************
CEffectManager & CEffectManager::Singleton(void)
{
	static CEffectManager singleton;
	return singleton;
}
