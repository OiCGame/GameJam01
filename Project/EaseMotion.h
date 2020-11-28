#pragma once
#include "Easing.h"

namespace sip
{
	// ********************************************************************************
	/// <summary>
	/// �C�[�Y���[�V�����N���X
	/// </summary>
	// ********************************************************************************
	template <typename T > class CEaseMotion
	{
	protected:

		float              m_Timer;            //! �^�C�}�[(�b)

		T                  m_Value;            //! �l

		T                  m_Begin;            //! �J�n�l

		T                  m_End;              //! �I���l

		bool               m_bStart;           //! �J�n�t���O

		bool               m_bEnd;             //! �I���t���O

		float              m_MotionTime;       //! ���[�V�������鎞��(�b)

		Ease               m_Ease;             //! �C�[�Y����

		EaseType           m_EaseType;         //! �C�[�Y���

	public:

		// ********************************************************************************
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		CEaseMotion(void) :
			m_Timer(0.0f),
			m_Value(),
			m_Begin(),
			m_End(),
			m_bStart(false),
			m_bEnd(false),
			m_MotionTime(1.0f),
			m_Ease(Ease::In),
			m_EaseType(EaseType::Sine)
		{
		}

		// ********************************************************************************
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="begin">�J�n�l</param>
		/// <param name="end">�I���l</param>
		/// <param name="ease">�C�[�W���O</param>
		/// <param name="type">�C�[�W���O���</param>
		/// <param name="time">�J�n����I���܂ł̕b</param>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		CEaseMotion(const T& begin, const T& end, const Ease& ease, const EaseType& type, const float& time = 1.0f)
		{
			SetBeginEnd(begin, end);
			SetEase(ease, type);
			SetMotionTime(time);
		}

		// ********************************************************************************
		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual ~CEaseMotion(void) = default;

		// ********************************************************************************
		/// <summary>
		/// ������
		/// </summary>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void Initialize(void)
		{
			Reset();
			m_bStart = false;
		}

		// ********************************************************************************
		/// <summary>
		/// ���߂���X�^�[�g����B
		/// </summary>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void Start(void)
		{
			Reset();
			m_bStart = true;
		}

		// ********************************************************************************
		/// <summary>
		/// �ꎞ��~����B
		/// </summary>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void Stop(void)
		{
			m_bStart = false;
		}

		// ********************************************************************************
		/// <summary>
		/// �ĊJ����B
		/// </summary>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void Resume(void)
		{
			m_bStart = true;
		}

		// ********************************************************************************
		/// <summary>
		/// �X�V
		/// </summary>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void Update(void)
		{
			// �n�܂��Ă��Ȃ��Ȃ�X�V���Ȃ��B
			if (!m_bStart)
			{
				return;
			}

			// �^�C�}�[�̉��Z
			m_Timer += CUtilities::GetFrameSecond();

			// �^�C�}�[����w�肵���b���� 0.0f ~ 1.0f �ɓ����悤�Ɍv�Z����B
			const float timer = m_Timer / m_MotionTime;

			// �^�C�}�[���� 0.0f �` 1.0f ���擾����B
			const float t = MOF_MIN(timer, 1.0f);

			// �^�C�}�[�� 1 �b�𒴂��Ă���Ȃ�I���t���O�𗧂Ă�B
			m_bEnd = (t >= 1.0f);

			// �^�C�}�[���g���ăC�[�W���O����B
			const float e = Easing::Easing(m_Ease, m_EaseType, t);

			// �C�[�W���O�̒l�Ő��`��ԁB
			m_Value = MOF_LERP(m_Begin, m_End, e);
		}

		// ********************************************************************************
		/// <summary>
		/// ���[�V�����̃��Z�b�g
		/// </summary>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void Reset(void)
		{
			m_bEnd = false;

			ResetTimer();
		}

		// ********************************************************************************
		/// <summary>
		/// �^�C�}�[�̃��Z�b�g
		/// </summary>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void ResetTimer(void)
		{
			m_Timer = 0.0f;
		}

		// ********************************************************************************
		/// <summary>
		/// ���[�V�������鎞�Ԃ��w�肷��B(�b)
		/// </summary>
		/// <param name="second">�b</param>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void SetMotionTime(const float& second)
		{
			m_MotionTime = second;
		}

		// ********************************************************************************
		/// <summary>
		/// �J�n�l�ƏI���l�̐ݒ�
		/// </summary>
		/// <param name="begin">�J�n�l</param>
		/// <param name="end">�I���l</param>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void SetBeginEnd(const T& begin, const T& end)
		{
			m_Begin = m_Value = begin;
			m_End = end;
		}

		// ********************************************************************************
		/// <summary>
		/// �C�[�Y���ʂ̐ݒ�
		/// </summary>
		/// <param name="ease">�C�[�Y����</param>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void SetEase(const Ease& ease)
		{
			m_Ease = ease;
		}

		// ********************************************************************************
		/// <summary>
		/// �C�[�Y�̐ݒ�
		/// </summary>
		/// <param name="ease">�C�[�Y����</param>
		/// <param name="easeType">�C�[�Y���</param>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void SetEase(const Ease& ease, const EaseType& easeType)
		{
			SetEase(ease);
			SetEaseType(easeType);
		}

		// ********************************************************************************
		/// <summary>
		/// �C�[�Y��ނ̐ݒ�
		/// </summary>
		/// <param name="easeType">�C�[�Y���</param>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		virtual void SetEaseType(const EaseType& easeType)
		{
			m_EaseType = easeType;
		}

		// ********************************************************************************
		/// <summary>
		/// ���݂̒l�̎擾
		/// </summary>
		/// <returns>���݂̒l</returns>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		T GetValue(void) const
		{
			return m_Value;
		}

		// ********************************************************************************
		/// <summary>
		/// �X�^�[�g���Ă���̌o�ߎ��Ԃ�Ԃ��B(�b)
		/// </summary>
		/// <returns>�X�^�[�g���Ă���̌o�ߎ���(�b)</returns>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		float GetTimer(void) const
		{
			return m_Timer;
		}

		// ********************************************************************************
		/// <summary>
		/// �I���t���O�̎擾
		/// </summary>
		/// <returns>�I���t���O</returns>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		bool IsEnd(void) const
		{
			return m_bEnd;
		}

		// ********************************************************************************
		/// <summary>
		/// �J�n�t���O�̎擾
		/// </summary>
		/// <returns>�J�n�t���O</returns>
		/// <created>���̂���,2020/09/10</created>
		/// <changed>���̂���,2020/09/10</changed>
		// ********************************************************************************
		bool IsStart(void) const
		{
			return m_bStart;
		}
	};
}