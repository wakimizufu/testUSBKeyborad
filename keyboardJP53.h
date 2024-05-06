#ifndef KEYBOARDJP53_H
#define KEYBOARDJP53_H

#include    <vector>
#include    <bitset>
#include    <algorithm>
#include    "keyboardButton.h"

class keyboardJP53
{
public:
    //コンストラクタ 
    keyboardJP53();

    //デストラクタ 
    ~keyboardJP53();

    /* 列挙値:同時押しすると状態が変更するキー値 */
    enum MODIFIER_KEY {
        KEY_NONE = 0x00,
        KEY_CTRL = 0x01,
        KEY_SHIFT = 0x02,
        KEY_ALT = 0x04,
        KEY_LOGO = 0x08,
        KEY_RCTRL = 0x10,
        KEY_RSHIFT = 0x20,
        KEY_RALT = 0x40,
        KEY_RLOGO = 0x80,
    };
    
    /* 列挙値:直接USB通信しないキーコード */
    enum SPECIAL_KEY {
        SP_NULL = 0x00,
        SP_FUNC = 0xFF,
    };
    
    //全てのキーボタンを未押下状態＆スキャン回数を初期化する
    void    reset();

    //現在のスキャン回数を取得する
    int scan();

    //最大スキャン回数を取得する
    int maxScan();

    //指定RowへのCol値をスキャンする 
    //--row  : 更新対象row値
    //--value: col7,col6,col5,col4,col3,col2,col1,col0
    void    scanRow( int row, unsigned char value);

    //スキャン回数をインクリメントする
    void    nextScan();

    //最大row数を取得する
    int maxRow();
    
    //スキャン結果を元にキーボード押下/未押下状態を更新する
    void    update(std::vector<keyboardButton>&, std::vector<keyboardButton>&);

    //スキャン結果を元にキーボード押下/未押下状態を更新する
    void    update();
    
    //新規に押下されたキーボードボタンを取得する
    bool    pressedButton(std::vector<keyboardButton>&);

    //新規に未押下になったキーボードボタンを取得する
    bool    releasedButton(std::vector<keyboardButton>&);

    //通常時:同時押しすると状態が変更するキー値を取得する
    uint8_t modifierKey(std::vector<keyboardButton>&);
        
    //ファンクションキーの押下状況を取得する
    bool    function(std::vector<keyboardButton>&);
        
    //vector<keyboardButton>間で登録されたkeyboardButtonクラスの差分をチェックする
    bool    changed(std::vector<keyboardButton>& , std::vector<keyboardButton>& );

protected:
    //スキャン回数初期値
    static const int KEYBORAD_JP53_INIT_SCAN = 0;

    //最大スキャン回数
    static const int KEYBORAD_JP53_MAX_SCAN = 3;

    //スキャン対象キーマップ Row:8 * Col:8 
    static const int KEYBORAD_JP53_ROW = 8;
    static const int KEYBORAD_JP53_COL = 8;

    //現在のスキャン回数
    int _scan;  

    //キーマップ
    keyboardButton *_map[KEYBORAD_JP53_ROW][KEYBORAD_JP53_COL];  

    //スキャン回数分のキー押下状態スナップショット
    bool _status[KEYBORAD_JP53_MAX_SCAN][KEYBORAD_JP53_ROW][KEYBORAD_JP53_COL];  

};



#endif

