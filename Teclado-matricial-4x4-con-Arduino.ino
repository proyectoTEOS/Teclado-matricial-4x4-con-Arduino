/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

#include <Keypad.h>

const byte rowsT = 4;
const byte colsT = 4;
char charactersT[rowsT][colsT] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPinsT[rowsT] = {9, 8, 7, 6};
byte columnsPinsT[colsT] = {5, 4, 3, 2};

boolean repriseT = true;
String storageStringT, readCharacterT, resultSerialT;
char keyT;

Keypad keypadT = Keypad( makeKeymap(charactersT), rowPinsT, columnsPinsT, rowsT, colsT);

void setup() {
  Serial.begin(9600);
  keypadT.addEventListener(keypadEventT);
}

void loop() {
  if (repriseT)
    Serial.println("Presine una o varias teclas, depues, presione '*' para finalizar y mostrar el texto.");
  repriseT = false;
  keyT = keypadT.getKey();
  if (keyT) {
    if (keyT == '*') {
      keyT = "";
    } else {
      Serial.print(keyT);
      Serial.print(" ");
      readCharacterT = keyT;
      storageStringT += readCharacterT;
    }
  }
}

void keypadEventT(KeypadEvent keyT) {
  switch (keypadT.getState()) {
    case PRESSED:
      switch (keyT) {
        case '*':
          resultSerialT = "\r\nTu texto fue: \"" + String(storageStringT) + "\", con un total de " + String(storageStringT.length()) + " caracteres.\r\n";
          Serial.println(resultSerialT);
          storageStringT = "";
          repriseT = true;
          break;
        default:;
      }
  }
}
