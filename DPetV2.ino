
#include <Adafruit_GFX.h>          // Core graphics library
#include <Adafruit_SSD1331.h>      // Hardware-specific library
#include <SdFat.h>                 // SD card & FAT filesystem library
#include <Adafruit_SPIFlash.h>     // SPI / QSPI flash library
#include <Adafruit_ImageReader.h>  // Image-reading functions

// Comment out the next line to load from SPI/QSPI flash instead of SD card:
#define USE_SD_CARD

// Color definitions
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

#define TFT_CS 10       // TFT select pin
#define TFT_RST 9       // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8        // TFT display/command pin
#define SD_CS 4         // SD card select pin
const int BUTTONA = 7;  //Sets Button A to pin 7
const int BUTTONB = 6;  // Sets Button B to Pin 6
const int BUTTONC = 5;  // Sets Button C to Pin 5


#if defined(USE_SD_CARD)
SdFat SD;                         // SD card filesystem
Adafruit_ImageReader reader(SD);  // Image-reader object, pass in SD filesys
#endif


Adafruit_SSD1331 tft = Adafruit_SSD1331(&SPI, TFT_CS, TFT_DC, TFT_RST);
Adafruit_Image img;  // An image loaded into RAM
int32_t width = 0,   // BMP image dimensions
  height = 0;

char getButton() {
  char buttonPressed;                      //empty variable for button character
  int buttonARead = digitalRead(BUTTONA);  // variable that reads input from pin
  int buttonBRead = digitalRead(BUTTONB);
  int buttonCRead = digitalRead(BUTTONC);
  int buttonState;
  int lastButtonState;
  int buttonReadOld = 0;  //variable set to default button state
  if (buttonARead != buttonReadOld) {
    delay(180);
    buttonState = 1;
    if (buttonState == 1) {
      buttonPressed = 'a';
      Serial.println(buttonPressed);
    }
    return buttonPressed;
  }

  if (buttonBRead != buttonReadOld) {
    delay(180);
    buttonState = 1;
    if (buttonState == 1) {
      buttonPressed = 'b';
      Serial.println(buttonPressed);
    }
    return buttonPressed;
  }

  if (buttonCRead != buttonReadOld) {
    delay(160);
    buttonState = 1;
    if (buttonState == 1) {
      buttonPressed = 'c';
      Serial.println(buttonPressed);
    }
    return buttonPressed;
  }
}

void getFrame(int frame) {
  switch (frame) {
  case 0:
    reader.drawBMP("/scratch1.bmp", tft, 0, 0);
    Serial.println("Frame1");
    frame = 1;
    return frame;
    break;
  case 1:
    reader.drawBMP("/scratch2.bmp", tft, 0, 0);
    Serial.println("Frame2");
    frame = 2;
    return frame;
    break; }
}

int screenState = 0;
int characterScreenLoaded = 0;
unsigned long previousTime;
int frame = 0;

void setup(void) {

  ImageReturnCode stat;  // Status from image-reading functions

  Serial.begin(9600);
#if !defined(ESP32)
  while (!Serial)
    ;  // Wait for Serial Monitor before continuing
#endif

  tft.begin();  // Initialize screen

  // The Adafruit_ImageReader constructor call (above, before setup())
  // accepts an uninitialized SdFat or FatVolume object. This MUST
  // BE INITIALIZED before using any of the image reader functions!
  Serial.print(F("Initializing filesystem..."));
#if defined(USE_SD_CARD)
  // SD card is pretty straightforward, a single call...
  if (!SD.begin(SD_CS, SD_SCK_MHZ(10))) {  // Breakouts require 10 MHz limit due to longer wires
    Serial.println(F("SD begin() failed"));
    for (;;)
      ;  // Fatal error, do not continue
  }
#endif
  Serial.println(F("OK!"));
  stat = reader.drawBMP("/scratch1.bmp", tft, 0, 0);
}

void loop() {

  const unsigned long nextFrame = 1000;
  unsigned long currentTime = millis();
  int frame = 0;
  pinMode(BUTTONA, INPUT);  //set button as input
  pinMode(BUTTONB, INPUT);
  pinMode(BUTTONC, INPUT);
  if (screenState == 0) {
    Serial.println("state");
    Serial.println(currentTime);
    Serial.println(previousTime);
    Serial.println(nextFrame);
    if (currentTime - previousTime >= nextFrame) {
      getFrame(frame);
      previousTime = currentTime;
    }
    Serial.println("current Frame");
    Serial.println(frame);
  }
}
