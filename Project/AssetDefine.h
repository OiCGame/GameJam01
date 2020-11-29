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
	Effect_Explosion2,
	Stage,
	PotGimmick,
	HP,
	HPFrame,
	PotBar,
	PotFrame,
	WeaponItem01,
	WeaponItem02,
	WeaponItem03,

	Count,
};

enum class AnimationKey 
{
	Effect_Barrier,
	Effect_Explosion,
	Effect_Explosion2,

	Count,
};

enum class SoundBufferKey {
	Sound0,
	boomerang,
	shot_struck,
	enemy_explosion,
	player_explosion,
    flash_01,
    flash_02,
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