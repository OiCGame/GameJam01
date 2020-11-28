/*************************************************************************//*!

					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include    "AssetDefine.h"

#include    "EffectManager.h"

//SCENE
#include    "Game.h"
#include    "Title.h"
#include    "GameClear.h"
#include    "GameOver.h"

#include    "GamePad.h"


/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void) {
  
	CUtilities::SetCurrentDirectory("Resource");

	// シーンマネージャーに各シーンの登録
	m_SceneManager
		.Add<CTitle>(SceneName::Title)
		.Add<CGame>(SceneName::Game)
		.Add<CGameClear>(SceneName::GameClear)
		.Add<CGameOver>(SceneName::GameOver)
		.SetFadeColor(MOF_COLOR_WHITE);

	CAnimationAsset::Load(AnimationKey::Effect_Barrier, "Effect/barrier.anim");
	CTextureAsset::Load(TextureKey::Effect_Barrier, AnimationAsset(AnimationKey::Effect_Barrier)->GetTextureFileName().c_str());
	
	g_EffectManager.Initialize();

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
	bf::GamePad::GetInstance().RefreshKey();

	// エスケープで終了（デバッグ用）
	if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		std::exit(0);
	} // if
	if (g_pInput->IsKeyPush(MOFKEY_9))
	{
		g_EffectManager.Start(EffectType::Barrier, Vector2(CUtilities::Random(500), CUtilities::Random(500)));
		g_EffectManager.Start(EffectType::Barrier, Vector2(CUtilities::Random(500), CUtilities::Random(500)));
		g_EffectManager.Start(EffectType::Barrier, Vector2(CUtilities::Random(500), CUtilities::Random(500)));
		g_EffectManager.Start(EffectType::Barrier, Vector2(CUtilities::Random(500), CUtilities::Random(500)));
		g_EffectManager.Start(EffectType::Barrier, Vector2(CUtilities::Random(500), CUtilities::Random(500)));
	}
	g_EffectManager.Update();

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

	g_EffectManager.Render();

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
	CAnimationAsset::Release();

	g_EffectManager.Release();
	return TRUE;
}