#pragma once
#include "AssetBase.h"

using namespace sip;

enum class TextureKey
{

};

using CTextureAsset = CAssetBase<TextureKey, CTexture>;

#define TextureAsset(key) CTextureAsset::GetAsset(key)