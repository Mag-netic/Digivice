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

// Color definitions
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

char getButton(int buttonRead) {
  char buttonPressed = '0';
  if (button <= 300 && button > 5) {
    buttonPressed = 'a';
  } else if (button > 300 && button <= 500) {
    buttonPressed = 'b';
  } else if (button > 500) {
    buttonPressed = 'c';
  }
  return buttonPressed;
}

Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, rst);
void setup() {
  // put your setup code here, to run once:
  display.begin();
  display.fillScreen(BLUE);
  display.setCursor(15, 15);
  display.setTextColor(YELLOW);
  display.setTextSize(2);
  display.print("Main");
  display.setCursor(15, 40);
  display.setTextColor(YELLOW);
  display.setTextSize(2);
  display.print("Menu");
  Serial.begin(9600);  //sets the arduino to communicate with serial we set the range of 9600
}

void loop() {
  // put your main code here, to run repeatedly:

  int buttonRead = analogRead(button);  //create an int to read the value of the button press
  char buttonPressed = getButton(button);

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

  if (buttonPressed = 'a') {
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
    delay(3000);
  } else if (buttonPressed = 'b') {

    display.fillScreen(GREEN);
    display.setCursor(15, 15);
    display.setTextColor(CYAN);
    display.setTextSize(2);
    display.print("Menu");
    display.setCursor(15, 40);
    display.setTextColor(CYAN);
    display.setTextSize(2);
    display.print("TWO");
    delay(3000);
  } else if (buttonPressed = 'c') {

    display.fillScreen(GREEN);
    display.setCursor(15, 15);
    display.setTextColor(BLACK);
    display.setTextSize(2);
    display.print("Menu");
    display.setCursor(15, 40);
    display.setTextColor(BLACK);
    display.setTextSize(2);
    display.print("THREE");
    delay(3000);

  } else if (buttonPressed = '0'){
    display.fillScreen(BLUE);
    display.setCursor(15, 15);
    display.setTextColor(YELLOW);
    display.setTextSize(2);
    display.print("Main");
    display.setCursor(15, 40);
    display.setTextColor(YELLOW);
    display.setTextSize(2);
    display.print("Menu");
    delay(3000);
  }
}
