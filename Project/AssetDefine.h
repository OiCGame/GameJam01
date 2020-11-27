#pragma once
#include "AssetBase.h"

using namespace sip;

enum class TextureKey
{
	Bullet_01
};

using CTextureAsset = CAssetBase<TextureKey, CTexture>;

#define TextureAsset(key) CTextureAsset::GetAsset(key)