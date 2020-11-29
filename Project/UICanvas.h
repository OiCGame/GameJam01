#pragma once


#include <memory>

#include <Mof.h>

using namespace std;


/// <summary>
/// UIを表示
/// </summary>
class CUICanvas {
private:
//    std::vector<class IHPRenderer> ;
    //! 描画対象
    std::shared_ptr<class CHPRenderer> m_pRenderer;

	CFont                              m_Font;

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
    void Render(void);
    /// <summary>
    /// 解放
    /// </summary>
    void Release(void);

	CFont& GetFont(void);
};