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
	Stage,
};

enum class AnimationKey 
{
	Effect_Barrier,
	Bullet_01,
	Character,
};

enum class AnimationKey 
{
	Sound0,
};

using CTextureAsset   = CAssetBase<TextureKey  , CTexture      >;
using CAnimationAsset = CAssetBase<AnimationKey, CAnimationData>;
using CSoundBufferAsset = CAssetBase<AnimationKey, CAnimationData>;

#define TextureAsset(key)   CTextureAsset  ::GetAsset(key)
#define AnimationAsset(key) CAnimationAsset::GetAsset(key)