#pragma once


#include <memory>

#include <Mof.h>

#include "AssetDefine.h"
#include "HP.h"
#include "Weapon.h"



#define			CHARACTER_SPEED			5

using namespace std;

/// <summary>
/// �Ď���
/// </summary>
class IObserver {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    IObserver() {}
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~IObserver() {}
    /// <summary>
    /// �ʒm
    /// </summary>
    /// <param name="event">���O</param>
    virtual void OnNotify(void* chara,const char* event) = 0;
};
/// <summary>
/// �Ď��Ώ�
/// </summary>
class Subject {
private:
    //! �I�u�U�[�o
    std::vector<std::shared_ptr<IObserver>> m_pObservers;
protected:
    /// <summary>
    /// �ʒm
    /// </summary>
    /// <param name="event"���O</param>
    void Notify(void* chara,const char* event) {
        auto& o = m_pObservers;
        std::for_each(o.begin(), o.end(), [&](std::shared_ptr<IObserver> ptr) {
            ptr->OnNotify(chara, event);
        });
    }
public:
    /// <summary>
    /// �I�u�U�[�o�ǉ�
    /// </summary>
    /// <param name="ptr">�Q��</param>
    void AddObserver(const std::shared_ptr<IObserver>& ptr) {
        m_pObservers.push_back(ptr);
    }
    /// <summary>
    /// �I�u�U�[�o�폜
    /// </summary>
    /// <param name="ptr">�|�C���^</param>
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
/// �L�����N�^�[�N���X
/// </summary>
// ********************************************************************************
class CCharacter : public Subject {
protected:
    //! �ʒu
    CVector2 m_Position;
    //! �\���摜
    weak_ptr<CTexture> m_pTexture;
    //! HP
//	CHP m_HP;
    std::shared_ptr<CHP> m_pHP;
    //! ����
//	CWeapon m_Weapon;
    std::unique_ptr<CWeapon>m_pWeapon;
    //! �\����`
    CRectangle m_RenderRect;
    //! �\���t���O
    bool m_bShow;

	int m_DamageWait;
public:
    // ********************************************************************************
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <created>�쑺,2020/11/28</created>
    /// <changed>�쑺,2020/11/28</changed>
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