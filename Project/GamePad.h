/**
* @file : GamePad.h
* @brief : �Q�[���p�b�h
* @date : 2020/10/14
*/



#ifndef BF_GAME_PAD_H
#define BF_GAME_PAD_H


#include <Mof.h>


namespace bf {
class GamePad {
private:
    //! �Q�[���p�b�h
    std::shared_ptr<Mof::CXGamePad>_pad;
    /**
    * @brief : �R���X�g���N�^
    * @param : [in](void) none
    * @return : none
    */
    GamePad();
    /**
    * @brief : �f�X�g���N�^
    * @param : [in](void) none
    * @return : none
    */
    ~GamePad();
public:
    /**
    * @brief : �V���O���g��
    * @param : [in](void) none
    * @return : none
    */
    static bf::GamePad& GetInstance(void);
    /**
    * @brief : �Q�b�^�[
    * @param : [in](void) none
    * @return : �|�C���^
    */
    std::shared_ptr<Mof::CXGamePad>GetGamePad(void) const;
    /**
    * @brief : �X�V
    * @param : [in](void) none
    * @return : none
    */
    void RefreshKey(void);
};
}
#define g_pPad bf::GamePad::GetInstance().GetGamePad()
#endif // !BF_GAME_PAD_H