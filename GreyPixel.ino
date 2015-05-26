#include <SPI.h>
#include "arduboy.h"
#include "greyTestBitmaps.h"

#define B_BUTTON 1
#define A_BUTTON 2
#define DOWN 4
#define RIGHT 8
#define UP 16
#define LEFT 32

Arduboy display;

uint8_t buttons;
uint8_t frame = 0;
uint8_t mode = 0;

void setup()
{
    SPI.begin();
    display.start();
    display.setTextSize(1);
    display.setCursor(0, 0);
    
    display.copyScreen(screen0,0); //copy screen0 to the first screen buffer
    display.copyScreen(screen1,1); //copy screen1 to the second screen buffer (this is super wasteful of RAM!)
}

void loop()
{   
    
    if(frame % 2 == 0) 
    {
      display.display(0); //I modified display() to take a number indicating which screen buffer to copy to the screen, this shows screen0
      display.display(1);
    }
    if(frame% 2 == 1) 
    {
      display.display(1); //this shows screen1
    }    
    
    frame++;    
}
