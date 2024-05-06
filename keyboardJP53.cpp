#include "keyboardJP53.h"

/*
試作版キーボード 日本語53キー版 クラス
*/

keyboardJP53::keyboardJP53()
{
    //行*列毎にキーコードを指定してkeyboardButtonを定義する
    //[参考]HID Usage Tables FOR Universal Serial Bus (USB) Version 1.21
    //[参考URL] http://www2d.biglobe.ne.jp/~msyk/keyboard/layout/usbkeycode.html
    //https://blog.boochow.com/article/usb-keyboard-scan-code-109jp.html
    //https://www.win.tue.nl/~aeb/linux/kbd/scancodes-8.html

    _map[0][0] = new    keyboardButton(0xE1,     SP_NULL,    KEY_SHIFT  , KEY_NONE, false); //L-SHIFT
    _map[0][1] = new    keyboardButton(0xE0,     SP_NULL,    KEY_CTRL   , KEY_NONE, false); //Ctlr
    _map[0][2] = new    keyboardButton(0xE2,     SP_NULL,    KEY_ALT    , KEY_NONE, false); //L-Alt
    _map[0][3] = new    keyboardButton(0x8B,     SP_NULL,    KEY_NONE   , KEY_NONE, false); //無変換
    _map[0][4] = new    keyboardButton(0x8A,     SP_NULL,    KEY_NONE   , KEY_NONE, false); //変換
    _map[0][5] = new    keyboardButton(0x88,     SP_NULL,    KEY_NONE   , KEY_NONE, false); //カタカナ
    _map[0][6] = new    keyboardButton(0x2C,     SP_NULL,    KEY_NONE   , KEY_NONE, false); //スペース
    _map[0][7] = NULL;

    _map[1][0] = new    keyboardButton(  SP_FUNC, SP_NULL,    KEY_NONE,   KEY_NONE,   false); //Func(キーボード内で利用するだけでそのままキーコードを送信しない)
    _map[1][1] = new    keyboardButton(     0x1D,    0x36,    KEY_NONE,   KEY_SHIFT,  false); //Z【<】
    _map[1][2] = new    keyboardButton(     0x1B,    0x37,    KEY_NONE,   KEY_SHIFT,  false); //X【>】
    _map[1][3] = new    keyboardButton(     0x06,    0x2E,    KEY_NONE,   KEY_SHIFT,  false); //C【~】
    _map[1][4] = new    keyboardButton(     0x19,    0x87,    KEY_NONE,   KEY_SHIFT,  false); //V【_】
    _map[1][5] = new    keyboardButton(     0x05, SP_NULL,    KEY_NONE,   KEY_NONE,   false); //B
    _map[1][6] = new    keyboardButton(     0x11, SP_NULL,    KEY_NONE,   KEY_NONE,   false); //N
    _map[1][7] = NULL;

    _map[2][0] = new    keyboardButton(0x2B,     0x39,   KEY_NONE,   KEY_NONE,  false); //TAB【CAPS】
    _map[2][1] = new    keyboardButton(0x04,     0x25,   KEY_NONE,   KEY_SHIFT, false); //A【(】
    _map[2][2] = new    keyboardButton(0x16,     0x26,   KEY_NONE,   KEY_SHIFT, false); //S【)】
    _map[2][3] = new    keyboardButton(0x07,     0x34,   KEY_NONE,   KEY_SHIFT, false); //D【*】
    _map[2][4] = new    keyboardButton(0x09,     0x33,   KEY_NONE,   KEY_SHIFT, false); //F【+】
    _map[2][5] = new    keyboardButton(0x0A,     0x30,   KEY_NONE,   KEY_SHIFT, false); //G【{】
    _map[2][6] = new    keyboardButton(0x0B,     0x32,   KEY_NONE,   KEY_SHIFT, false); //H【}】
    _map[2][7] = NULL;

    _map[3][0] = new    keyboardButton(0x35,     0x1E,   KEY_NONE,  KEY_SHIFT,  false); //半角/全角【!】
    _map[3][1] = new    keyboardButton(0x29,     0x1F,   KEY_NONE,  KEY_SHIFT,  false); //ESC【"】
    _map[3][2] = new    keyboardButton(0x14,     0x20,   KEY_NONE,  KEY_SHIFT,  false); //Q【#】
    _map[3][3] = new    keyboardButton(0x1A,     0x21,   KEY_NONE,  KEY_SHIFT,  false); //W【$】
    _map[3][4] = new    keyboardButton(0x08,     0x22,   KEY_NONE,  KEY_SHIFT,  false); //E【%】
    _map[3][5] = new    keyboardButton(0x15,     0x23,   KEY_NONE,  KEY_SHIFT,  false); //R【&】
    _map[3][6] = new    keyboardButton(0x17,     0x24,   KEY_NONE,  KEY_SHIFT,  false); //T【'】
    _map[3][7] = NULL;

    _map[4][0] = new    keyboardButton(0x1C,     0x24,   KEY_NONE,   KEY_NONE,   false);    //Y【7】
    _map[4][1] = new    keyboardButton(0x18,     0x25,   KEY_NONE,   KEY_NONE,   false);    //U【8】
    _map[4][2] = new    keyboardButton(0x0C,     0x26,   KEY_NONE,   KEY_NONE,   false);    //I【9】
    _map[4][3] = new    keyboardButton(0x12,     0x2D,   KEY_NONE,   KEY_SHIFT,  false);    //O【=】
    _map[4][4] = new    keyboardButton(0x13,     0x49,   KEY_NONE,   KEY_NONE,   false);    //P【ins】
    _map[4][5] = new    keyboardButton(0x2D,     0x4A,   KEY_NONE,   KEY_NONE,   false);    //-【home】
    _map[4][6] = new    keyboardButton(0x2A,     0x4B,   KEY_NONE,   KEY_NONE,   false);    //BackSpace【PageUP】
    _map[4][7] = NULL;


    _map[5][0] = new    keyboardButton(0x0D,     0x21,   KEY_NONE,  KEY_NONE,   false); //J【4】
    _map[5][1] = new    keyboardButton(0x0E,     0x22,   KEY_NONE,  KEY_NONE,   false); //K【5】
    _map[5][2] = new    keyboardButton(0x0F,     0x23,   KEY_NONE,  KEY_NONE,   false); //L【6】
    _map[5][3] = new    keyboardButton(0x2F,     0x89,   KEY_NONE,  KEY_NONE,   false); //@【\】
    _map[5][4] = new    keyboardButton(0x30,     0x4C,   KEY_NONE,  KEY_NONE,   false); //[【del】
    _map[5][5] = new    keyboardButton(0x2E,     0x4D,   KEY_NONE,  KEY_NONE,   false); //^【end】
    _map[5][6] = new    keyboardButton(0x89,     0x4E,   KEY_NONE,  KEY_NONE,   false); //￥【PageDown】
    _map[5][7] = NULL;


    _map[6][0] = new    keyboardButton(0x10,     0x1E,   KEY_NONE,   KEY_NONE,  false); //M【1】
    _map[6][1] = new    keyboardButton(0x33,     0x1F,   KEY_NONE,   KEY_NONE,  false); //;【2】
    _map[6][2] = new    keyboardButton(0x34,     0x20,   KEY_NONE,   KEY_NONE,  false); //:【3】
    _map[6][3] = new    keyboardButton(0x52,     0x52,   KEY_NONE,   KEY_NONE,  false); //↑【↑】
    _map[6][4] = new    keyboardButton(0x32,     0x89,   KEY_NONE,   KEY_SHIFT, false); //]【|】
    _map[6][5] = new    keyboardButton(0x38,     0x38,   KEY_NONE,   KEY_SHIFT, false); //／【?】
    _map[6][6] = new    keyboardButton(0x58,     0x58,   KEY_NONE,   KEY_NONE,  false); //Enter【Enter】
    _map[6][7] = NULL;


    _map[7][0] = new    keyboardButton(0x36,        0x27,      KEY_NONE, KEY_NONE,   false); //,【0】
    _map[7][1] = new    keyboardButton(0x37,        0x37,      KEY_NONE, KEY_NONE,   false); //.【.】
    _map[7][2] = new    keyboardButton(0x50,        0x50,      KEY_NONE, KEY_NONE,   false); //←【←】
    _map[7][3] = new    keyboardButton(0x51,        0x51,      KEY_NONE, KEY_NONE,   false); //↓【↓】
    _map[7][4] = new    keyboardButton(0x4F,        0x4F,      KEY_NONE, KEY_NONE,   false); //→【→】
    _map[7][5] = new    keyboardButton(0xE5,     SP_NULL,    KEY_RSHIFT, KEY_NONE, false);  //R-SHIFT
    _map[7][6] = new    keyboardButton(SP_NULL,     0x4C,      KEY_NONE, (KEY_CTRL + KEY_ALT),   false);  //【ALT+CTRL+DEL】
    _map[7][7] = NULL;

    
    //全てのキーボタンを未押下状態＆スキャン回数を初期化する
    reset();
}


keyboardJP53::~keyboardJP53()
{
    //newしたkeyboardButtonをdeleteする
    for (int _row = 0; _row < KEYBORAD_JP53_ROW; _row++) {
        for (int _col = 0; _col < KEYBORAD_JP53_COL; _col++) {
            if (NULL != _map[_row][_col]) {
                delete _map[_row][_col];
            }
        }
    }
}



//全てのキーボタンを未押下状態＆スキャン回数を初期化する
void keyboardJP53::reset()
{
    _scan = KEYBORAD_JP53_INIT_SCAN;
 
    for (int temp = 0; temp < KEYBORAD_JP53_MAX_SCAN; temp++) {
        for (int _row = 0; _row < KEYBORAD_JP53_ROW; _row++) {
            for (int _col = 0; _col < KEYBORAD_JP53_COL; _col++) {
                _status[temp][_row][_col] = false;
            }
        }
    }
}

//現在のスキャン回数を取得する
int keyboardJP53::scan()
{
    return  _scan;
}

//最大スキャン回数を取得する
int keyboardJP53::maxScan()
{
    return  KEYBORAD_JP53_MAX_SCAN;
}

//最大row数を取得する
int keyboardJP53::maxRow()
{
    return  KEYBORAD_JP53_ROW;
}


//指定RowへのCol値をスキャンする
//--row  : 更新対象row値
//--value: col7,col6,col5,col4,col3,col2,col1,col0
void    keyboardJP53::scanRow(int row, unsigned char value)
{

    //valueをstd:bitsetへ変換
    std::bitset<8> bsValue(value);

    for  ( int i=0; i<=7; i++) {
        _status[_scan][row][i] = bsValue[i];
    }
}


//スキャン回数をインクリメントする
void    keyboardJP53::nextScan()
{
    _scan++;
    if (_scan >= KEYBORAD_JP53_MAX_SCAN) {
        _scan = KEYBORAD_JP53_INIT_SCAN;
    }
}

//スキャン結果を元にキーボード押下/未押下状態を更新する
void    keyboardJP53::update(std::vector<keyboardButton>& newPressedButton, std::vector<keyboardButton>& newReleasedButton)
{
    bool pressed;
    keyboardButton *button;
 
    //_newPressedButton,_newReleasedButtonを初期化する
    newPressedButton.clear();
    newReleasedButton.clear();

    for (int _row = 0; _row < KEYBORAD_JP53_ROW; _row++) {
        for (int _col = 0; _col < KEYBORAD_JP53_COL; _col++) {

            //スキャン回数が全てTrueなら押下状態 1つでもfalseなら未押下状態とする
            pressed = true;
            for (int temp = 0; temp < KEYBORAD_JP53_MAX_SCAN; temp++) {
                pressed = pressed && _status[temp][_row][_col];
            }

            button = _map[_row][_col];
            //未定義であればコピー処理をスルー
            if (button == NULL) {
                continue;
            }

            //新規に押下されたキーボードボタンに当該ボタンをコピー
            if ((pressed) && (not button->press())) {
                newPressedButton.push_back(*button);
                button->set(true);
            }

            //新規に未押下されたキーボードボタンに当該ボタンをコピー
            if ((not pressed) && (button->press())) {
                newReleasedButton.push_back(*button);
                button->set(false);
            }

        }
    }
}

//スキャン結果を元にキーボード押下/未押下状態を更新する
void    keyboardJP53::update()
{
    bool pressed;
    keyboardButton *button;
    
    for (int _row = 0; _row < KEYBORAD_JP53_ROW; _row++) {
        for (int _col = 0; _col < KEYBORAD_JP53_COL; _col++) {

            //スキャン回数が全てTrueなら押下状態 1つでもfalseなら未押下状態とする
            pressed = true;
            for (int temp = 0; temp < KEYBORAD_JP53_MAX_SCAN; temp++) {
                pressed = pressed && _status[temp][_row][_col];
            }

            button = _map[_row][_col];
            //未定義であればコピー処理をスルー
            if (button == NULL) {
                continue;
            }

            //新規に押下されたキーボードボタンに当該ボタンをコピー
            if ((pressed) && (not button->press())) {
                button->set(true);
            }

            //新規に未押下されたキーボードボタンに当該ボタンをコピー
            if ((not pressed) && (button->press())) {
                button->set(false);
            }

        }
    }
}


//押下中のキーボードボタンを取得する
bool    keyboardJP53::pressedButton(std::vector<keyboardButton>& result)
{

    bool returnValue = false;
    keyboardButton *button;

    //resultに_newPressedButtonの要素を挿入する
    result.clear();

    for (int _row = 0; _row < KEYBORAD_JP53_ROW; _row++) {
        for (int _col = 0; _col < KEYBORAD_JP53_COL; _col++) {
            button = _map[_row][_col];

            //未定義であればコピー処理をスルー
            if (button == NULL) {
                continue;
            }

            //押下されたキーボードボタンに当該ボタンをコピー
            if (button->press()) {
                returnValue = true;
                result.push_back(*button);
            }
        }
    }
    return  returnValue;
}

//未押下のキーボードボタンを取得する
bool    keyboardJP53::releasedButton(std::vector<keyboardButton>& result)
{

    bool returnValue = false;
    keyboardButton *button;

    //resultに_newPressedButtonの要素を挿入する
    result.clear();

    for (int _row = 0; _row < KEYBORAD_JP53_ROW; _row++) {
        for (int _col = 0; _col < KEYBORAD_JP53_COL; _col++) {
            button = _map[_row][_col];

            //未定義であればコピー処理をスルー
            if (button == NULL) {
                continue;
            }

            //押下されたキーボードボタンに当該ボタンをコピー
            if (not button->press()) {
                returnValue = true;
                result.push_back(*button);
            }
        }
    }
    return  returnValue;
}

//通常時:同時押しすると状態が変更するキー値を取得する
uint8_t keyboardJP53::modifierKey(std::vector<keyboardButton>& newPressedButton)
{
    int modifierKey = KEY_NONE;
   
    for (int i = 0; i < newPressedButton.size(); ++i)
    {
    keyboardButton _button = newPressedButton[i];
    modifierKey = modifierKey + _button.modifier();
    }

    return  modifierKey;
}

//ファンクションキーの押下状況を取得する
bool keyboardJP53::function(std::vector<keyboardButton>& newPressedButton)
{
    bool returnValue = false;
   
    for (int i = 0; i < newPressedButton.size(); ++i)
    {
    keyboardButton _button = newPressedButton[i];
    
    if ( SP_FUNC == _button.code() ) 
      {
      returnValue = true;
      }
    }

    return  returnValue;
}

//vector<keyboardButton>間で登録されたkeyboardButtonクラスの差分をチェックする
bool keyboardJP53::changed(std::vector<keyboardButton>& b1, std::vector<keyboardButton>& b2)
{
    bool returnValue = false;
    
    if (b1.size() != b2.size()) 
    {
      returnValue = true;
    } 
    else if ( (0 == b1.size()) && (0 == b2.size()) ) 
    {   
      returnValue = false;
    } 
    else 
    {
      returnValue = false;

      for (int i=0; i<b1.size(); ++i)
      {
      keyboardButton _b1button = b1[i];
      bool _press = false;
      
        for (int j=0; j<b2.size(); ++j)
        {
        keyboardButton _b2button = b2[j];
          if (  _b1button.code() == _b2button.code() )
          {
          _press = true;
          }
        }
        
        if ( !_press ) 
        {
        returnValue = true;
        }
      }
    }
   
    return  returnValue;
}
