#include <Adafruit_GFX.h>      //gfx library for the oled display
#include <Adafruit_SSD1331.h>  //library for the ssd1331 oled display
#include <SPI.h>               //dont know exactly what kind of library this is

// This is a 96w x 64L display
// You can use any (4 or) 5 pins
// pins 13,11,10,9 & 8 is connected to OLED display
#define sclk 13         //sclk is clock connected to output pin 13
#define mosi 11         //
#define cs 10           //cs is chip select connected to output pin 10
#define rst 9           //res is Reset connected to output pin 9
#define dc 8            //dc is data connected to output pin 8
const int BUTTONA = 7;  //Sets Button A to pin 7
const int BUTTONB = 4;  // Sets Button B to Pin 8
const int BUTTONC = 5;  // Sets Button C to Pin 9

// Color definitions
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, rst);

char getButton() {
  char buttonPressed;                      //empty variable for button character
  int buttonARead = digitalRead(BUTTONA);  // variable that reads input from pin
  int buttonBRead = digitalRead(BUTTONB);
  int buttonCRead = digitalRead(BUTTONC);
  int buttonState;
  int lastButtonState;
  int buttonReadOld = 0;  //variable set to default button state
  if (buttonARead != buttonReadOld) {
    delay(150);
    buttonState = 1;
    if (buttonState = 1) {
      buttonPressed = 'a';
      Serial.println(buttonPressed);
    }
    return buttonPressed;
  }

    if (buttonBRead != buttonReadOld) {
    delay(150);
    buttonState = 1;
    if (buttonState = 1) {
      buttonPressed = 'b';
      Serial.println(buttonPressed);
    }
    return buttonPressed;
  }

    if (buttonCRead != buttonReadOld) {
    delay(150);
    buttonState = 1;
    if (buttonState = 1) {
      buttonPressed = 'c';
      Serial.println(buttonPressed);
    }
    return buttonPressed;
  }
}

/*char getButtonA() {
  char buttonPressed;
  int BUTTONANEW = digitalRead(BUTTONA);
  int BUTTONBNEW = digitalRead(BUTTONA);
  int BUTTONCNEW = digitalRead(BUTTONA);
  int BUTTONAOLD;
  int BUTTONBOLD;
  int BUTTONCOLD;
  if (BUTTONAOLD == 0 && BUTTONANEW == 1) {
    buttonPressed = 'a';
    BUTTONAOLD = BUTTONANEW;
    delay(500);
    return buttonPressed;
  } else if (BUTTONBOLD == 0 && BUTTONBNEW == 1) {
    buttonPressed = 'b';
    BUTTONBOLD = BUTTONBNEW;
    delay(500);
    return buttonPressed;
  } else if (BUTTONCOLD == 0 && BUTTONCNEW == 1) {
    buttonPressed = 'c';
    BUTTONCOLD = BUTTONCNEW;
    delay(500);
    return buttonPressed;
  }
}*/

void getCharacterScreen(int screenState) {
  int state;
  if (state == 0) {
    display.fillScreen(BLUE);
    display.setCursor(15, 15);
    display.setTextColor(YELLOW);
    display.setTextSize(1);
    display.print("Character");
    display.setCursor(15, 40);
    display.setTextColor(YELLOW);
    display.setTextSize(1);
    display.print("Screen");

    //prints the value of buttonRead
    getButton();
    switch (getButton()) {
      case 'a':
        while (int screenState = 2) {
          getStatScreen(screenState);
        }
        break;
      case 'b':
        while (int screenState = 14) {
          getConnectScreen(screenState);
        }
        break;
    }
  }
}

void getStatScreen(int screenState) {
  int state = screenState;
  while (state == 2) {
    display.fillScreen(RED);
    display.setCursor(15, 15);
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.print("Stats");
    display.setCursor(15, 40);
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.print("Screen");
    getButton();
    switch (getButton()) {
      case 'a':
        while (int screenState = 4) {
          getTrainingScreen(screenState);
          getButton();
        }
        break;
      case 'b':
        while (int screenState = 0) {
          getCharacterScreen(screenState);
          getButton();
        }
        break;
    }
  }
}

void getTrainingScreen(int screenState) {
  int state = screenState;
  while (state == 4) {
    display.fillScreen(WHITE);
    display.setCursor(15, 15);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Training");
    display.setCursor(15, 40);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Screen");
    getButton();
    switch (getButton()) {
      case 'a':
        while (int screenState = 6) {
          getFoodScreen(screenState);
          getButton();
        }
        break;
      case 'b':
        while (int screenState = 2) {
          getStatScreen(screenState);
          getButton();
        }
        break;
    }
  }
}

void getFoodScreen(int screenState) {
  int state = screenState;
  while (state == 6) {
    display.fillScreen(GREEN);
    display.setCursor(15, 15);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Food");
    display.setCursor(15, 40);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Screen");
    getButton();
    switch (getButton()) {
      case 'a':
        while (int screenState = 8) {
          getBattleScreen(screenState);
          getButton();
        }
        break;
      case 'b':
        while (int screenState = 4) {
          getTrainingScreen(screenState);
          getButton();
        }
        break;
    }
  }
}

void getBattleScreen(int screenState) {
  int state = screenState;
  while (state == 8) {
    display.fillScreen(GREEN);
    display.setCursor(15, 15);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Battle");
    display.setCursor(15, 40);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Screen");
    getButton();
    switch (getButton()) {
      case 'a':
        while (int screenState = 10) {
          getRestScreen(screenState);
          getButton();
        }
        break;
      case 'b':
        while (int screenState = 6) {
          getFoodScreen(screenState);
          getButton();
        }
        break;
    }
  }
}

void getRestScreen(int screenState) {
  int state = screenState;
  while (state == 10) {
    display.fillScreen(GREEN);
    display.setCursor(15, 15);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Rest");
    display.setCursor(15, 40);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Screen");
    getButton();
    switch (getButton()) {
      case 'a':
        while (int screenState = 12) {
          getHealScreen(screenState);
          getButton();
        }
        break;
      case 'b':
        while (int screenState = 8) {
          getBattleScreen(screenState);
          getButton();
        }
        break;
    }
  }
}

void getHealScreen(int screenState) {
  int state = screenState;
  while (state == 12) {
    display.fillScreen(GREEN);
    display.setCursor(15, 15);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Heal");
    display.setCursor(15, 40);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Screen");
    getButton();
    switch (getButton()) {
      case 'a':
        while (int screenState = 14) {
          getConnectScreen(screenState);
          getButton();
        }
        break;
      case 'b':
        while (int screenState = 10) {
          getRestScreen(screenState);
          getButton();
        }
        break;
    }
  }
}

void getConnectScreen(int screenState) {
  int state = screenState;
  while (state == 14) {
    display.fillScreen(GREEN);
    display.setCursor(15, 15);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Connect");
    display.setCursor(15, 40);
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.print("Screen");
    getButton();
    switch (getButton()) {
      case 'a':
        while (int screenState = 0) {
          getCharacterScreen(screenState);
          getButton();
        }
        break;
      case 'b':
        while (int screenState = 12) {
          getHealScreen(screenState);
          getButton();
        }
        break;
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTONA, INPUT);  //set button as input
  pinMode(BUTTONB, INPUT);
  pinMode(BUTTONC, INPUT);
  display.begin();
  Serial.begin(9600);  //sets the arduino to communicate with serial port
}

void loop() {
  int screenState = 0;
  getCharacterScreen(screenState);
}
