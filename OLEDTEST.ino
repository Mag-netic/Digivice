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
  if (button == 202) {
    buttonPressed = 'a';
  } else if (button == 408) {
    buttonPressed = 'b';
  } else if (button == 1021) {
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
  Serial.println(buttonRead);
  getButton(buttonRead);
  Serial.println();
  while(getButton(buttonRead) == 'a'){
    int screenState = 1;
    getScreenOne(screenState);
  }
  delay(600);
  //char buttonPressed = getButton(button);
  //Serial.println(buttonPressed);
  
  /*Serial.println(buttonRead);  //prints the previously read button value to console
  if (buttonRead < 300) {
    int buttonPressed = 1;
    return (buttonPressed);
  } else if (buttonRead < 500) {
    int buttonPressed = 2;
    return (buttonPressed);
  } else if (buttonRead < 1200) {
    int buttonPressed = 3;
    return (buttonPressed);
  }*/

  /*if (buttonPressed == 'a') {
    //display.begin();
    display.fillScreen(RED);
    display.setCursor(15, 15);
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.print("Menu");
    display.setCursor(15, 40);
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.print("ONE");
    //delay(3000);
  } else if (buttonPressed == 'b') {

    display.fillScreen(GREEN);
    display.setCursor(15, 15);
    display.setTextColor(CYAN);
    display.setTextSize(2);
    display.print("Menu");
    display.setCursor(15, 40);
    display.setTextColor(CYAN);
    display.setTextSize(2);
    display.print("TWO");
    //delay(3000);
  } else if (buttonPressed == 'c') {

    display.fillScreen(GREEN);
    display.setCursor(15, 15);
    display.setTextColor(BLACK);
    display.setTextSize(2);
    display.print("Menu");
    display.setCursor(15, 40);
    display.setTextColor(BLACK);
    display.setTextSize(2);
    display.print("THREE");
    //delay(3000);

  } else if (buttonPressed == '0'){
    display.fillScreen(BLUE);
    display.setCursor(15, 15);
    display.setTextColor(YELLOW);
    display.setTextSize(2);
    display.print("Main");
    display.setCursor(15, 40);
    display.setTextColor(YELLOW);
    display.setTextSize(2);
    display.print("Menu");
    //delay(3000);
  }*/
}
