/**
* @file : GamePad.h
* @brief : ゲームパッド
* @date : 2020/10/14
*/



#ifndef BF_GAME_PAD_H
#define BF_GAME_PAD_H


#include <Mof.h>


namespace bf {
class GamePad {
private:
    //! ゲームパッド
    std::shared_ptr<Mof::CXGamePad>_pad;
    /**
    * @brief : コンストラクタ
    * @param : [in](void) none
    * @return : none
    */
    GamePad();
    /**
    * @brief : デストラクタ
    * @param : [in](void) none
    * @return : none
    */
    ~GamePad();
public:
    /**
    * @brief : シングルトン
    * @param : [in](void) none
    * @return : none
    */
    static bf::GamePad& GetInstance(void);
    /**
    * @brief : ゲッター
    * @param : [in](void) none
    * @return : ポインタ
    */
    std::shared_ptr<Mof::CXGamePad>GetGamePad(void) const;
    /**
    * @brief : 更新
    * @param : [in](void) none
    * @return : none
    */
    void RefreshKey(void);
};
}
#define g_pPad bf::GamePad::GetInstance().GetGamePad()
#endif // !BF_GAME_PAD_H