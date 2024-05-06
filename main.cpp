#include "mbed.h"
#include "keyboardJP53.h"

//2019/2/27 Ticker メモ
//https://github.com/ARMmbed/mbed-os/blob/master/drivers/Ticker.h　L87
//attach()第二引数の割込み間隔はfloafで、 (t * 1000000.0f )secとなるので少数表記で1秒以下も設定する

//秋月ＬＰＣ１１Ｕ３５マイコンボードキット http://akizukidenshi.com/catalog/g/gK-12144/

//pin定義
//.\USBKeyborad20190501_zip_lpc11u35_401\USBKeyborad20190501\mbed\TARGET_LPC11U35_401\TOOLCHAIN_ARM_MICRO\PinNames.h


//https://os.mbed.com/users/hsgw/code/MCP23017/
#include "MCP23017.h"

//mbed I2C
//https://os.mbed.com/users/okini3939/notebook/I2C_jp/


#include <bitset>
#include <vector>
#include <algorithm>


//LED1: NUM_LOCK
//LED2: CAPS_LOCK
//LED3: SCROLL_LOCK
//BusOut leds(LED1, LED2, LED3);

//USBKeyboard
//https://os.mbed.com/handbook/USBKeyboard
//Todo:keyCodeメソッドを改造して、USBKeyboardクラス内のキーマップを参照せず直接キーコードとモディファイフラグを指定出来るメソッドを作成する
#include "USBKeyboard.h"
USBKeyboard keyboard;

//Virtual serial port over USB
//https://os.mbed.com/handbook/USBSerial
//#include "USBSerial.h"
//USBSerial serial;

//MCP23017
I2C i2c(P0_5, P0_4); // LPC11U35 sda, scl
MCP23017::MCP23017 io(i2c,MCP23017_DEFAULT_ADDR);

//keyboardJP53クラス
//ToDo:shift,ctrl,altキーにを別途フラグ管理する updateメソッド実行時にフラグを更新する
//ToDo:キーコードをUSB HIDのキーマップに変更する
keyboardJP53 keyJP53;

//実行状態LED
DigitalOut myled(LED1);

//通常時:押下している「同時押しすると状態が変更するキー値」を取得する
uint8_t modifierKey;

//ファンクションキーの押下状況
bool function;
bool beforeFunction;



void sendKeyCodeNormal(std::vector<keyboardButton>& _keyboardButton) {

  uint8_t _keycode[4];
    int i;

    for ( i=0; i<4; i++)
    {
        _keycode[i]=keyJP53.SP_NULL;
    }
    
    for (int i = 0; i < _keyboardButton.size(); ++i)
    {
        if ( i >= 4 )
        {
            break;
        } 
        else if ( i <= 3 )
        {
            keyboardButton _button = _keyboardButton[i];
            _keycode[i]=_button.code();
        }
    }   
    
    keyboard.keyCodeAlternate(_keycode[0], _keycode[1], _keycode[2], _keycode[3], modifierKey);
}


void sendKeyCodeFunction(std::vector<keyboardButton>& _keyboardButton) {

  uint8_t _keycode;
  uint8_t _modifierKey;  

    keyboard.keyCodeAlternate(keyJP53.SP_NULL, keyJP53.SP_NULL, keyJP53.SP_NULL, keyJP53.SP_NULL, keyJP53.KEY_NONE);

    for (int i = 0; i < _keyboardButton.size(); ++i)
    {
    keyboardButton _button = _keyboardButton[i];
    _keycode        =   _button.funccode();
    _modifierKey    =   _button.funcmodifier();

    keyboard.keyCodeMomentary(_keycode,_modifierKey);
    }
}

int main()
{


  //押下中＆未押下Vector
  std::vector<keyboardButton> pressButton;
  std::vector<keyboardButton> releaseButton;
  std::vector<keyboardButton> holdButton;
  std::vector<keyboardButton> beforButton;

  //I2C初期化
  i2c.frequency(400000);
  io.init();
  io.setDirrection(MCP23017_PORTB, 0xFF);    // set all of the PORTB pins to input
  io.setDirrection(MCP23017_PORTA, 0x00);    // set all of the PORTA pins to output
  io.setPullUp(MCP23017_PORTB, 0x00);        // activate all of the PORTB pin pull-ups
  io.setInputPolarity(MCP23017_PORTB, 0x00); // invert all of the PORTB pins input polarity

  //keyboardJP53初期化
  keyJP53.reset();
  
  while(1) {

    myled = 0;

    //キー状態を指定回数分スキャンする
    for ( int scanCount=0x00; scanCount<keyJP53.maxScan(); scanCount++)  {
      //serial.printf("keyboardJP53 scanCount=%02x\r\n",scanCount);

      //指定行数分スキャンする
      for ( int rowCount=0x00; rowCount<keyJP53.maxRow(); rowCount++)  {
        unsigned char readport = 0xFF^(0x80>>rowCount);
        io.write(MCP23017_PORTA,readport);

        //受信したキー状態を格納する
        unsigned char revData= io.read(MCP23017_PORTB)^0xFF;
        keyJP53.scanRow( rowCount, revData);

        //serial.printf("           scan=%02x rowCount=%02x readport=%02x revData=%02x\r\n",keyJP53.scan(),rowCount,readport,revData);
        wait(0.001);
      }
      
      //スキャン回数をインクリメントする
      keyJP53.nextScan();
    }
    
    //スキャン結果を元にキーボード押下/未押下状態を更新する
    keyJP53.update(pressButton, releaseButton);

    //押下している「同時押しすると状態が変更するキー値」を取得する
    keyJP53.pressedButton(holdButton);
    modifierKey = keyJP53.modifierKey(holdButton);
    
    //ファンクションキーの押下状況を取得する
    function = keyJP53.function(holdButton);


    //キーコードを送信する
    if ( keyJP53.changed (beforButton, holdButton) )
    { 
    myled = 1;

      if ( !function )
      {
        sendKeyCodeNormal(holdButton);
      } 
      else if ( function ) 
      {
        sendKeyCodeFunction(holdButton);
      }
    }
    
    //前回holdButton,Functionをコピーする
    beforeFunction=function;
    beforButton.clear();
    std::swap(beforButton, holdButton);

    wait(0.005);
  }
}
