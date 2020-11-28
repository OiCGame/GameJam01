#pragma once
#include "AssetBase.h"
#include "AnimationData.h"

using namespace sip;

enum class TextureKey
{
	Character,
	Bullet_01,
	Effect_Barrier,
};

enum class AnimationKey
{
	Effect_Barrier,
	Bullet_01,
	Character,
};

using CTextureAsset   = CAssetBase<TextureKey  , CTexture      >;
using CAnimationAsset = CAssetBase<AnimationKey, CAnimationData>;

#define TextureAsset(key)   CTextureAsset  ::GetAsset(key)
#define AnimationAsset(key) CAnimationAsset::GetAsset(key)