#pragma once


#include <memory>

#include <Mof.h>

#include "AssetDefine.h"
#include "HP.h"
#include "Weapon.h"



#define			CHARACTER_SPEED			5

using namespace std;

/// <summary>
/// 監視者
/// </summary>
class IObserver {
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    IObserver() {}
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~IObserver() {}
    /// <summary>
    /// 通知
    /// </summary>
    /// <param name="event">名前</param>
    virtual void OnNotify(void* chara,const char* event) = 0;
};
/// <summary>
/// 監視対象
/// </summary>
class Subject {
private:
    //! オブザーバ
    std::vector<std::shared_ptr<IObserver>> m_pObservers;
protected:
    /// <summary>
    /// 通知
    /// </summary>
    /// <param name="event"名前</param>
    void Notify(void* chara,const char* event) {
        auto& o = m_pObservers;
        std::for_each(o.begin(), o.end(), [&](std::shared_ptr<IObserver> ptr) {
            ptr->OnNotify(chara, event);
        });
    }
public:
    /// <summary>
    /// オブザーバ追加
    /// </summary>
    /// <param name="ptr">参照</param>
    void AddObserver(const std::shared_ptr<IObserver>& ptr) {
        m_pObservers.push_back(ptr);
    }
    /// <summary>
    /// オブザーバ削除
    /// </summary>
    /// <param name="ptr">ポインタ</param>
    void RemoveObserver(std::shared_ptr<IObserver>& ptr) {
        auto it = std::remove(m_pObservers.begin(), m_pObservers.end(), ptr);
        m_pObservers.erase(it, m_pObservers.end());
    }
};


struct CharacterInitParam {
    Vector2 position;
    shared_ptr<CTexture> texture;
	int type;
};
// ********************************************************************************
/// <summary>
/// キャラクタークラス
/// </summary>
// ********************************************************************************
class CCharacter : public Subject {
protected:
    //! 位置
    CVector2 m_Position;
    //! 表示画像
    weak_ptr<CTexture> m_pTexture;
    //! HP
//	CHP m_HP;
    std::shared_ptr<CHP> m_pHP;
    //! 武器
//	CWeapon m_Weapon;
    std::unique_ptr<CWeapon>m_pWeapon;
    //! 表示矩形
    CRectangle m_RenderRect;
    //! 表示フラグ
    bool m_bShow;

	int m_DamageWait;
public:
    // ********************************************************************************
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <created>川村,2020/11/28</created>
    /// <changed>川村,2020/11/28</changed>
    // ********************************************************************************
    CCharacter();
    virtual ~CCharacter();

    virtual Mof::CVector2 GetPosition(void) const;
    virtual const char* GetTeam(void) const = 0;
    bool IsShow(void) const;
	bool IsDamage(void) const;


    virtual void Initialize(const CharacterInitParam& param);
    virtual void Update(void);
    virtual void Render(CVector2 scroll);
    virtual void Release(void);

    virtual CRectangle GetRectangle(void) const;

    virtual void CollisionBullet(void);
    virtual void CollisionEnemy(void);
};