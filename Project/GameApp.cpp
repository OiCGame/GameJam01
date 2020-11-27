/*************************************************************************//*!

					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
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
		@brief			アプリケーションの初期化
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void) {

	// シーンマネージャーに各シーンの登録
	m_SceneManager
		.Add<CTitle>(SceneName::Title)
		.Add<CGame>(SceneName::Game)
		.Add<CGameClear>(SceneName::GameClear)
		.Add<CGameOver>(SceneName::GameOver)
		.SetFadeColor(MOF_COLOR_WHITE);

	// タイトルシーンから開始
	//m_SceneManager.Initialize(SceneName::Title);
	// デバッグ用、ゲームシーンから開始
	m_SceneManager.Initialize(SceneName::Game);

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの更新
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Update(void) {
	//キーの更新
	g_pInput->RefreshKey();
	// エスケープで終了（デバッグ用）
	if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		std::exit(0);
	} // if



	// アクティブのシーン更新
	if (!m_SceneManager.Update())
	{
		return FALSE;
	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの描画
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Render(void) {
	//描画開始
	g_pGraphics->RenderStart();
	//画面のクリア
	g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

	// アクティブのシーン描画
	if (!m_SceneManager.Render())
	{
		return FALSE;
	}

	//描画の終了
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの解放
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Release(void) {

	// テクスチャの解放
	CTextureAsset::Release();

	return TRUE;
}