#include "keyboardButton.h"

/*
試作版キーボード 日本語53キー版 クラス
*/

keyboardButton::keyboardButton(uint8_t keycode, uint8_t funccode, uint8_t modifier, uint8_t funcmodifier, bool push)
{
    _keycode        = keycode;
    _funccode       = funccode;
    _modifier       = modifier;
    _funcmodifier   = funcmodifier;
    _push           = push;
}

keyboardButton::~keyboardButton()
{
}

//キー押下状態を設定する
void keyboardButton::set(bool push) {
    _push = push;
}

//キー押下状態を取得する
bool keyboardButton::press(void) {
    return _push;
}

//割り当てキーボードコードを取得する
uint8_t keyboardButton::code(void) {
    return _keycode;
}


//割り当てファンクションキーボードコードを取得する
uint8_t keyboardButton::funccode(void) {
    return _funccode;
}


//通常時：同時押しすると状態が変更するキー値を取得する
uint8_t keyboardButton::modifier(void) {
    return _modifier;
}

//ファンクション押下時：同時押しすると状態が変更するキー値を取得する
uint8_t keyboardButton::funcmodifier(void) {
    return _funcmodifier;
}

