/*
*******************************************************************************
* Copyright (c) 2023 by M5Stack
*                  Equipped with M5Core sample source code
*                          配套  M5Core 示例源代码
* Visit for more information: https://docs.m5stack.com/en/core/gray
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/core/gray
*
* Describe: RFID.
* Date: 2021/8/19
*******************************************************************************
  Please connect to Port A(22、21),Use the RFID Unit to read the Fudan card ID
and display the ID on the screen. 请连接端口A(22、21),使用RFID Unit
读取ID卡并在屏幕上显示。
*/


#include "MFRC522_I2C.h"

MFRC522 mfrc522(0x28);  // Create MFRC522 instance.  创建MFRC522实例

MFRC522::MIFARE_Key key;


void setup() 
{
    pinMode(D1, OUTPUT);
    pinMode(D0, OUTPUT);
    digitalWrite(D1, HIGH);

    pinMode(WIO_KEY_A, INPUT_PULLUP);
    pinMode(WIO_KEY_B, INPUT_PULLUP);
    pinMode(WIO_KEY_C, INPUT_PULLUP);

    Wire.begin();  // Wire init, adding the I2C bus.  Wire初始化, 加入i2c总线
    Serial.begin(115200);
    mfrc522.PCD_Init();  // Init MFRC522.  初始化 MFRC522
}

void loop() 
{

  
//    if (!mfrc522.PICC_IsNewCardPresent() ||
//        !mfrc522.PICC_ReadCardSerial()) {  //如果没有读取到新的卡片
//        delay(200);
//        return;
//    }
//
//    for (byte i = 0; i < mfrc522.uid.size;
//         i++) 
//    {  // Output the stored UID data.  将存储的UID数据输出
//        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//        Serial.print(mfrc522.uid.uidByte[i], HEX);
//    }
//    Serial.println("");


  if (digitalRead(WIO_KEY_C) == LOW) 
  {
  Serial.println("A Key pressed");
  digitalWrite(D0, HIGH);
  delay(200);
  digitalWrite(D0, LOW);
  delay(200);
  digitalWrite(D0, HIGH);
  delay(200);
  digitalWrite(D0, LOW);
  digitalWrite(D1, HIGH);
  delay(2000);
  digitalWrite(D1, LOW);
  }
  else
  {
    
  }

  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();

  if (content.substring(1) == "A6 B9 1A 3F") //Gulshan IITD ID
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  if (content.substring(1) == "A7 B7 5D 7B") //Gulshan Keychain
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }
  
  else if (content.substring(1) == "D7 2B 71 7B") //Harshit Keychain
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "D7 5F 52 7B") //Master Access QL
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "04 85 3B 7A 68 19 90") //Saran Sticker
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "04 85 36 7A 68 19 90") //Bavath Sticker
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "04 85 46 7A 68 19 90") //Prasannaa Sticker
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "29 E5 12 E5") 
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "47 7C 72 7A") 
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "F9 10 1C B4") 
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }
  
  else if (content.substring(1) == "09 B2 D8 B3") 
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }
  
  else if (content.substring(1) == "79 A8 E1 B3") 
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "A9 FC 10 B4") 
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "C9 9B F1 B3") 
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "04 85 85 7A 68 19 90") 
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }

  else if (content.substring(1) == "04 85 82 7A 68 19 90") 
  {
    Serial.println("Access Granted");
    Serial.println();
    openAccess();
  }
    
  else
  {
  digitalWrite(D0, HIGH);
  delay(100);
  digitalWrite(D0, LOW);  
  delay(100);
  digitalWrite(D0, HIGH);
  delay(100);
  digitalWrite(D0, LOW);  
  delay(100);  
  digitalWrite(D0, HIGH);
  delay(100);
  digitalWrite(D0, LOW);  
  delay(100);  
  }

}

void openAccess()
{
  digitalWrite(D0, HIGH);
  delay(1000);
  digitalWrite(D0, LOW);
  
  digitalWrite(D1, HIGH);
  delay(2000);
  digitalWrite(D1, LOW);  
}
