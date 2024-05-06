#ifndef KEYBOARDBUTTON_H
#define KEYBOARDBUTTON_H

/*
試作版キーボード キーボタンクラス
*/
#include    <bitset>
#include "mbed.h"

class keyboardButton
{
public:

    //コンストラクタ 
    //--keycode:割り当てキーボードコード
    //--funccode:割り当てファンクションキーボードコード
    //--modifier:shift,ctrlキーの様な同時押しすると状態が変更するキー値
    //--push   :キー押下状態
    keyboardButton(uint8_t keycode, uint8_t funccode, uint8_t modifier, uint8_t funcmodifier, bool push);

    //デストラクタ
    ~keyboardButton();

    //キー押下状態を設定する
    void set(bool push);

    //キー押下状態を取得する
    bool press(void);

    //割り当てキーボードコードを取得する
    uint8_t code(void);

    //割り当てファンクションキーボードコードを取得する
    uint8_t funccode(void);

    //通常時：同時押しすると状態が変更するキー値
    uint8_t modifier(void);

    //ファンクション押下時：同時押しすると状態が変更するキー値
    uint8_t funcmodifier(void);
        
protected:
    uint8_t _keycode;    //キーボードコード
    uint8_t _funccode;       //ファンクションキーボードコード
    uint8_t _modifier;       //通常時：同時押しすると状態が変更するキー値
    uint8_t _funcmodifier;   //ファンクション押下時：同時押しすると状態が変更するキー値
    bool    _push;       //キー押下状態 true:押下中 ,fase:未押下
};

#endif
