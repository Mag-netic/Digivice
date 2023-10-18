#include <Adafruit_GFX.h>      //gfx library for the oled display
#include <Adafruit_SSD1331.h>  //library for the ssd1331 oled display
#include <SPI.h>               //dont know exactly what kind of library this is

// This is a 96w x 64L display
// You can use any (4 or) 5 pins
// pins 13,11,10,9 & 8 is connected to OLED display
#define sclk 13   //sclk is clock connected to output pin 13
#define mosi 11   //
#define cs 10     //cs is chip select connected to output pin 10
#define rst 9     //res is Reset connected to output pin 9
#define dc 8      //dc is data connected to output pin 8
int button = A0;  //input pin Analog 0 is connected to 3 microswitches names button
int LED = A3;
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

char getButton(int button) {
  char buttonPressed = 'z';
  if (button >= 150 && button <= 250) {
    buttonPressed = 'a';
  } else if (button >= 300 && button <= 500) {
    buttonPressed = 'b';
  } else if (button >= 900 && button < 1200) {
    buttonPressed = 'c';
  }
  Serial.println(buttonPressed);
  return buttonPressed;
}

void getMainMenu (int screenState){ //gets the display setting for the Main Menu Screen
  int state;
  if(state == 0){
    display.fillScreen(BLUE);
  display.setCursor(15, 15);
  display.setTextColor(YELLOW);
  display.setTextSize(2);
  display.print("Main");
  display.setCursor(15, 40);
  display.setTextColor(YELLOW);
  display.setTextSize(2);
  display.print("Menu");
  }
}

void getScreenOne(int screenState){
  int state = screenState;
  while(state == 1){
    display.fillScreen(RED);
    display.setCursor(15, 15);
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.print("Menu");
    display.setCursor(15, 40);
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.print("ONE");
  }
}

void getScreenTwo(int screenState){
  int state = screenState;
  while(state == 2){
    display.fillScreen(WHITE);
    display.setCursor(15, 15);
    display.setTextColor(BLACK);
    display.setTextSize(2);
    display.print("Menu");
    display.setCursor(15, 40);
    display.setTextColor(BLACK);
    display.setTextSize(2);
    display.print("Two");
  }
}

void getScreenThree(int screenState){
  int state = screenState;
  while(state == 3){
    display.fillScreen(GREEN);
    display.setCursor(15, 15);
    display.setTextColor(BLACK);
    display.setTextSize(2);
    display.print("Menu");
    display.setCursor(15, 40);
    display.setTextColor(BLACK);
    display.setTextSize(2);
    display.print("THREE");
  }
}

void setup() {
  // put your setup code here, to run once:
  display.begin();
  int screenState = 0;
  getMainMenu(screenState);
  Serial.begin(9600);  //sets the arduino to communicate with serial we set the range of 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonRead = analogRead(button);  //create an int to read the value of the button press
  Serial.println(buttonRead); //prints the value of buttonRead
  getButton(buttonRead); //a function that takes the buttonRead int input and returns a char value
 
 switch (getButton(buttonRead)){
  case 'a':
  while (int screenState = 1){
  getScreenOne(screenState);
  getButton(buttonRead);
  }
  break;
  case 'b':
  while (int screenState = 2){
  getScreenTwo(screenState);
  getButton(buttonRead);
  }
  break;
  case 'c':
  while (int screenState = 3){
  getScreenThree(screenState);
  getButton(buttonRead);
  break;
  }
 }
  
  delay(600);

}
