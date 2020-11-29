#pragma once


#include <memory>

#include <Mof.h>

using namespace std;


/// <summary>
/// UI��\��
/// </summary>
class CUICanvas {
private:
//    std::vector<class IHPRenderer> ;
    //! �`��Ώ�
    std::shared_ptr<class CHPRenderer> m_pRenderer;

	CFont                              m_Font;

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CUICanvas();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CUICanvas();
public:
    /// <summary>
    /// �V���O���g��
    /// </summary>
    /// <returns>�C���X�^���X</returns>
    static CUICanvas& Singleton(void);
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="ptr">�|�C���^</param>
    void SetRenderer(std::shared_ptr<class CHPRenderer> ptr);
//    void AddRenderer();
    /// <summary>
    /// �`��
    /// </summary>
    void Render(void);
    /// <summary>
    /// ���
    /// </summary>
    void Release(void);

	CFont& GetFont(void);
};