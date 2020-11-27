/*************************************************************************//*!

					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include    "AssetDefine.h"

//SCENE
#include    "Game.h"
#include    "Title.h"
#include    "GameClear.h"
#include    "GameOver.h"

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void) {

	// �V�[���}�l�[�W���[�Ɋe�V�[���̓o�^
	m_SceneManager
		.Add<CTitle>(SceneName::Title)
		.Add<CGame>(SceneName::Game)
		.Add<CGameClear>(SceneName::GameClear)
		.Add<CGameOver>(SceneName::GameOver)
		.SetFadeColor(MOF_COLOR_WHITE);

	// �^�C�g���V�[������J�n
	//m_SceneManager.Initialize(SceneName::Title);
	// �f�o�b�O�p�A�Q�[���V�[������J�n
	m_SceneManager.Initialize(SceneName::Game);

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̍X�V
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Update(void) {
	//�L�[�̍X�V
	g_pInput->RefreshKey();
	// �G�X�P�[�v�ŏI���i�f�o�b�O�p�j
	if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		std::exit(0);
	} // if



	// �A�N�e�B�u�̃V�[���X�V
	if (!m_SceneManager.Update())
	{
		return FALSE;
	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̕`��
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Render(void) {
	//�`��J�n
	g_pGraphics->RenderStart();
	//��ʂ̃N���A
	g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

	// �A�N�e�B�u�̃V�[���`��
	if (!m_SceneManager.Render())
	{
		return FALSE;
	}

	//�`��̏I��
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̉��
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Release(void) {

	// �e�N�X�`���̉��
	CTextureAsset::Release();

	return TRUE;
}