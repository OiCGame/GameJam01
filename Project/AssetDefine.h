#pragma once
#include "AssetBase.h"
#include "AnimationData.h"

using namespace sip;

enum class TextureKey
{
	Character,
	Enemy01,
	Enemy02,
	Enemy03,
	Muscle,
	Bullet_01,
	Bullet_02,
	Bullet_03,
	Effect_Barrier,
	Effect_Explosion,
	Stage,
	PotGimmick,
	HP,
	HPFrame,
  
	Count,
};

enum class AnimationKey 
{
	Effect_Barrier,
	Effect_Explosion,

	Count,
};

enum class SoundBufferKey {
	Sound0,
	boomerang,
	shot_struck,
	enemy_explosion,
	player_explosion,
};
enum class SoundStreamBufferKey {
	Bgm0,
	title,
	gameclear,
	gameover,
};

using CTextureAsset   = CAssetBase<TextureKey  , CTexture      >;
using CAnimationAsset = CAssetBase<AnimationKey, CAnimationData>;
using CSoundBufferAsset = CAssetBase<SoundBufferKey, CSoundBuffer>;
using CSoundStreamBufferAsset = CAssetBase<SoundStreamBufferKey, CSoundBuffer>;

#define TextureAsset(key)   CTextureAsset  ::GetAsset(key)
#define AnimationAsset(key) CAnimationAsset::GetAsset(key)
#define SoundBufferAsset(key) CSoundBufferAsset::GetAsset(key)
#define SoundStreamBufferAsset(key) CSoundStreamBufferAsset::GetAsset(key)