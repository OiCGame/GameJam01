#pragma once
#include "SceneManager.h"

using namespace sip;

enum class SceneName
{
	Title,
	Game,
	GameClear,
	GameOver,
};

struct GameData
{

};

using MyApp = CSceneManager<SceneName, GameData>;