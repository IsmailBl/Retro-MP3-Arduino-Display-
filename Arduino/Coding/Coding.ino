
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
  char SongTitle[20];            
  char codeBuff[10];   
  char TimeStamp[5];
  char *index;

  int charsRead;

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
 Serial.begin(9600);
 Serial1.begin(11500);
 display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  
  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
 
}

void loop() {
    if (Serial.available() > 0) {
      charsRead = Serial.readBytesUntil('\n', SongTitle, sizeof(SongTitle) - 1);
      SongTitle[charsRead] = '\0';  // Make it a string

      Serial1. print("  SongTitle = ");    // Debug statement
      Serial1.println(SongTitle);   
      
          display.clearDisplay();
        
          display.setTextSize(1);      // Normal 1:1 pixel scale
          display.setTextColor(SSD1306_WHITE); // Draw white text
          display.setCursor(0, 0);     // Start at top-left corner
          display.cp437(true);         // Use full 256 char 'Code Page 437' font
          display.write(SongTitle);

      index = strchr(SongTitle, ';');
      *index = '\0';                             //Make a string

      strcpy(codeBuff, SongTitle);
      strcpy(TimeStamp, index + 1);

      Serial1.print("Code = ");              // Debug statements
      Serial1.print(codeBuff);
      Serial1. print("  TimeStamp = ");
      Serial.println(TimeStamp);
      display.setCursor(0, 3); 
      display.write(TimeStamp);
      display.clearDisplay();

    }   
  
}
