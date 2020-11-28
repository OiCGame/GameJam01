#include "Enemy.h"

#include "Player.h"
#include "BulletManager.h"

enum class EaseType {
    Linear,
    EaseIn,
    EaseOut,
    EaseInOut,
};
struct AnimData {
    float value;
    float time;
    EaseType ease_type;
};
class BezierCurve {
private:
public:
    // timeは正規化されているものとする 
    float Interpolation(float time, float prev, float next,
                        EaseType type = EaseType::Linear) {
        switch (type) {
            case  EaseType::EaseInOut:
                time = 0.5f - 0.5f * MOF_COS(MOF_MATH_PI * time);
                break;
        } // switch


        float from = prev;
        float to = next;
        return from + (to - from) * time;
    }

    //!-----------------------------------------------------
    //! @brief : 補間計算
    //! @param : [in](float normalized) アニメーションさせたい時間で割った値
    //!                                 最大値が1.0f
    //! @param : [in](std::vector<float>& poistion) コントロールポイントの位置 
    //! @param : [in]( EaseType type) イージングのタイプ
    //! @return : none
    //!-----------------------------------------------------
    float InterpolationAnimData(float normalized,
                                std::vector<float>& control,
                                EaseType type = EaseType::Linear) {
        _ASSERT_EXPR(0.0 <= normalized, L"アニメーションの時間の閾値を超えています");
        if (control.size() > 2) {
            std::vector<float> anim_data;
            for (int i = 1; i < control.size(); i++) {
                float value = Interpolation(normalized,
                                            control.at(i - 1),
                                            control.at(i),
                                            type);
                anim_data.push_back(value);
            } // for
            return InterpolationAnimData(normalized, anim_data);
        } // if
        else if (control.size() == 2) {
            return Interpolation(normalized,
                                 control.at(0),
                                 control.at(1),
                                 type);
        } // else if
        return 0.0f;
    }
};

class BezierCurveAnimation {
private:
    //! コントロールポイント
    std::vector<float> _anim_data_x;
    //! コントロールポイント
    std::vector<float> _anim_data_y;
    //! アニメーション所要時間
    float _rate;
public:
    BezierCurveAnimation(float rate) :
        _anim_data_x(),
        _anim_data_y(),
        _rate(rate) {
    };

    void AddControlPoint(Mof::CVector2 point) {
        _anim_data_x.push_back(point.x); _anim_data_y.push_back(point.y);
    }

    Mof::CVector2 CalculatePointPosition(float time) {
        BezierCurve b;
        Mof::CVector2 ret;
        ret.x = b.InterpolationAnimData(time / _rate,
                                        _anim_data_x);
        ret.y = b.InterpolationAnimData(time / _rate,
                                        _anim_data_y);
        return ret;
    }
};

CVector2 CEnemy::MoveChase(void) {
    if (m_pTarget.expired()) {
        return CVector2();
    } // if
    if (auto target = m_pTarget.lock()) {
        auto dir = target->GetPosition() - this->GetPosition();
        Mof::CVector2Utilities::Normal(dir, dir);

        return dir * CHARACTER_SPEED * 0.1f;
    } // if
    return CVector2();
}
void Rotate(float& pos_x, float& pos_y, const float radian,
            const float center_x, const float center_y) {
    float axis_x = pos_x - center_x;
    float axis_y = pos_y - center_y;

    float translate_x = (axis_x)*std::cosf(radian) - (axis_y)*std::sinf(radian);
    float translate_y = (axis_x)*std::sinf(radian) + (axis_y)*std::cosf(radian);

    pos_x = center_x + translate_x;
    pos_y = center_y + translate_y;
};

void Rotate(CVector2& pos, const float radian, const CVector2 center) {
    Rotate(pos.x, pos.y,
           radian,
           center.x, center.y);
};
/// <summary>
/// 波々移動
/// </summary>
/// <returns>移動量</returns>
CVector2 CEnemy::WaveMove(void) {
    m_WaveAngle++;
    // 周期
    float period = 0.05f;
    // 振幅
    float amplitude = 5.0f;
    // 移動量を作成
    Mof::CVector2 ret;
    ret.x = std::cosf(m_WaveAngle * period) * amplitude;
    ret.y = -2.0f;
//    m_Move.y += std::sinf(_wave_angle);
    Rotate(ret,
           MOF_ToRadian(0.0f),
           Mof::CVector2());
    return ret;
}

/// <summary>
/// 
/// </summary>
void CEnemy::UpdateAttack(void) {
    super::m_Weapon.Shot(m_Position,
                         Mof::CVector2(0.0f, 2.0f),
                         BulletTeamType::Enemy);
}

/// <summary>
/// 移動更新
/// </summary>
void CEnemy::UpdateMove(void) {
    m_Move = WaveMove();
//    m_Move = this->MoveChase();
}

BezierCurveAnimation gAnime(5.0f);
/// <summary>
/// コンストラクタ
/// </summary>
CEnemy::CEnemy() :
    super() {
    gAnime.AddControlPoint(Mof::CVector2(200.0f, 600.0f));
    gAnime.AddControlPoint(Mof::CVector2(600.0f, 400.0f));
    gAnime.AddControlPoint(Mof::CVector2(200.0f, 200.0f));
    gAnime.AddControlPoint(Mof::CVector2(400.0f, 600.0f));
}

/// <summary>
/// デストラクタ
/// </summary>
CEnemy::~CEnemy() {
}
/// <summary>
/// セッター
/// </summary>
/// <param name="ptr">ポインタ</param>
void CEnemy::SetTarget(std::shared_ptr<CPlayer> ptr) {
    this->m_pTarget = ptr;
}

void CEnemy::Initialize(const CharacterInitParam& param) {
    super::Initialize(param);
}

/// <summary>
/// 更新
/// </summary>
void CEnemy::Update(void) {
    m_Time += ::CUtilities::GetFrameSecond();

    this->UpdateMove();



    float delta = ::CUtilities::GetFrameSecond();
    m_AttackTime += delta;
    if (m_AttackTimeMax < m_AttackTime) {
        m_AttackTime = 0;
        this->UpdateAttack();
    } // if
    
    m_Position += m_Move;
//    m_Position = gAnime.CalculatePointPosition(_time);
}

void CEnemy::Render(CVector2 scroll) {
    super::Render(scroll);
}