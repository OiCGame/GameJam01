#pragma once
#include "Mof.h"
#include <unordered_map>

namespace sip
{
	// ********************************************************************************
	/// <summary>
	/// �A�Z�b�g�̃x�[�X�N���X
	/// </summary>
	// ********************************************************************************
	template <typename Key, typename T > class CAssetBase
	{
	private:
		// operator= �̍폜
		void operator= (const CAssetBase<Key,T>&) = delete;

		std::unordered_map<Key, std::shared_ptr<T>> m_AssetMap; //! �}�b�v

		// ********************************************************************************
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <created>���̂���,2020/04/26</created>
		/// <changed>���̂���,2020/04/26</changed>
		// ********************************************************************************
		CAssetBase(void) :
			m_AssetMap()
		{
		}

		// ********************************************************************************
		/// <summary>
		/// �}�b�v�̎擾
		/// </summary>
		/// <returns>�}�b�v</returns>
		/// <created>���̂���,2020/04/26</created>
		/// <changed>���̂���,2020/04/26</changed>
		// ********************************************************************************
		static CAssetBase<Key,T>& GetAssetMap(void)
		{
			static CAssetBase<Key,T> assetMap;
			return assetMap;
		}

	public:

		// ********************************************************************************
		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		/// <created>���̂���,2020/04/26</created>
		/// <changed>���̂���,2020/04/26</changed>
		// ********************************************************************************
		~CAssetBase(void)
		{
			Release();
		}

		// ********************************************************************************
		/// <summary>
		/// �A�Z�b�g�̓o�^�B
		/// </summary>
		/// <param name="key">�����p�L�[</param>
		/// <param name="fileName">�t�@�C����</param>
		/// <returns>�o�^����������� true ����ȊO false</returns>
		/// <created>���̂���,2020/04/26</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		static bool Load(const Key& key, LPCMofChar fileName)
		{
			// ���݂��邩�̌����B
			if (GetAssetMap().m_AssetMap.find(key) == GetAssetMap().m_AssetMap.end() ||
				GetAssetMap().m_AssetMap[key] == nullptr)
			{
				// ���݂��Ȃ��ꍇ�̓|�C���^���쐬����B
				GetAssetMap().m_AssetMap[key] = std::make_shared<T>();
			}
			// �A�Z�b�g�̓ǂݍ��݂��s���B
			return GetAssetMap().m_AssetMap[key]->Load(fileName);
		}

		// ********************************************************************************
		/// <summary>
		/// �o�^�����L�[����A�Z�b�g�̎擾�B
		/// </summary>
		/// <param name="key">�L�[</param>
		/// <returns>�f�[�^��Ԃ��B�f�[�^���Ȃ��ꍇ empty ��Ԃ��B</returns>
		/// <created>���̂���,2020/04/26</created>
		/// <changed>���̂���,2020/04/26</changed>
		// ********************************************************************************
		static std::shared_ptr<T> GetAsset(const Key& key)
		{
			return GetAssetMap().m_AssetMap[key];
		}

		// ********************************************************************************
		/// <summary>
		/// �}�b�v����L�[�̃f�[�^���폜����B
		/// </summary>
		/// <param name="key">�����p�L�[</param>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		static void Erase(const Key& key)
		{
			Release(key);
			GetAssetMap().m_AssetMap.erase(key);
		}

		// ********************************************************************************
		/// <summary>
		/// �w��f�[�^�̉���B
		/// </summary>
		/// <param name="key">�J������f�[�^�̃L�[</param>
		/// <created>���̂���,2020/04/26</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		static void Release(const Key& key)
		{
			if (GetAssetMap().m_AssetMap[key])
			{
				GetAssetMap().m_AssetMap[key]->Release();
			}
		}

		// ********************************************************************************
		/// <summary>
		/// �S�f�[�^�̉���B
		/// </summary>
		/// <created>���̂���,2020/04/26</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		static void Release(void)
		{
			for (auto& itr : GetAssetMap().m_AssetMap)
			{
				if (itr.second)
				{
					itr.second->Release();
				}
			}
		}
	};
}