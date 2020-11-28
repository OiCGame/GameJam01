#pragma once


#include <memory>


using namespace std;


/// <summary>
/// UIを表示
/// </summary>
class CUICanvas {
private:
//    std::vector<class IHPRenderer> ;
    std::shared_ptr<class CHPRenderer> m_pRenderer;

    /// <summary>
    /// コンストラクタ
    /// </summary>
    CUICanvas();
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CUICanvas();
public:
    /// <summary>
    /// シングルトン
    /// </summary>
    /// <returns>インスタンス</returns>
    static CUICanvas& Singleton(void);
    /// <summary>
    /// セッター
    /// </summary>
    /// <param name="ptr">ポインタ</param>
    void SetRenderer(std::shared_ptr<class CHPRenderer> ptr);
//    void AddRenderer();
    /// <summary>
    /// 描画
    /// </summary>
    /// <param name=""></param>
    void Render(void);
};