#pragma once

#include "Character.h"
#include "GamePad.h"
#include "Weapon.h"
#include "HP.h"


class CPlayer : public CCharacter 
{
    using super = CCharacter;
private:
    uint32_t m_Invincible;
public:
    CPlayer();
    ~CPlayer();

    /// <summary>
    /// ゲッター
    /// </summary>
    /// <returns>CollisionRect</returns>
    virtual CRectangle GetRectangle(void) const override;
    /// <summary>
    /// チーム取得
    /// </summary>
    /// <returns>チーム</returns>
    virtual const char* GetTeam(void) const override;

    virtual void Initialize(const CharacterInitParam& param) override;
    virtual void Update(void) override;
    virtual void Render(CVector2 scroll) override;

    virtual void CollisionBullet(void) override;
    virtual void CollisionEnemy(void) override;
};