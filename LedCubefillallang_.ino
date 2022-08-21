/* LedStripRainbow: Example Arduino sketch that shows
 * how to make a moving rainbow pattern on an
 * Addressable RGB LED Strip from Pololu.
 *
 * To use this, you will need to plug an Addressable RGB LED
 * strip from Pololu into pin 12.  After uploading the sketch,
 * you should see a moving rainbow.
 */

#include <PololuLedStrip.h>

// Create an ledStrip object and specify the pin it will use.
PololuLedStrip<12> ledStrip;

// Create a buffer for holding the colors (3 bytes per color).
#define LED_COUNT 512
rgb_color colors[LED_COUNT];

void setup()
{
    delay(5000);
}

int forward=1;
unsigned char brightness=20;

unsigned char rb=0;
unsigned char gb=0;
unsigned char bb=0;
unsigned char r=brightness;
unsigned char g=brightness;
unsigned char b=brightness;
unsigned char colour=0;
int no_to_display;
uint16_t i,k,m,n;
int layer, d,e,f;
int x, y, z;
static unsigned long lastTime;

void Change_Colour()
{
   if (colour<6) {
    colour++;
   }
   else {
    colour=1;
   }
   if (colour==0) {
      r=brightness;
      g=brightness;
      b=brightness;
   }         

   if (colour==1) {
      r=brightness;
      g=0;
      b=0;
   }         

   if (colour==2) {
      r=brightness;
      g=brightness;
      b=0;
   }         

   if (colour==3) {
      r=0;
      g=brightness;
      b=0;
   }         

   if (colour==4) {
      r=0;
      g=brightness;
      b=brightness;
   }         

   if (colour==5) {
      r=0;
      g=0;
      b=brightness;
   }         

   if (colour==6) {
      r=brightness;
      g=0;
      b=brightness;
   }
}
void loop()
{
   // Back left bottom corner to front right top corner
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 21; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + y + z <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + y + (7-z) <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 20; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + y + z <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + y + (7-z) <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Front right top corner to back left bottom corner
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 20; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + y + z >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + y + (7-z) >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer <= 21; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + y + z >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + y + (7-z) >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Back right bottom corner to front left top corner
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 21; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (((7-x) + y + z <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (((7-x) + y + (7-z) <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 20; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (((7-x) + y + z <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (((7-x) + y + (7-z) <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Front left top corner to back right bottom corner
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 20; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (((7-x)+ y + z >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (((7-x) + y + (7-z) >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer <= 21; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (((7-x) + y + z >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (((7-x) + y + (7-z) >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Front right bottom corner to back left top corner
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 20; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x+ y + (7-z) >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + y + z >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer <= 21; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + y + (7-z) >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + y + z >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Back left top corner to front right bottom corner
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 21; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + y + (7-z) <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + y + z <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 20; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + y + (7-z) <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + y + z <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Front left bottom corner to back right top corner
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 20; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (((7-x)+ y + (7-z) >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (((7-x) + y + z >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer <= 21; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (((7-x) + y + (7-z) >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (((7-x) + y + z >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Back right top corner to front left bottom corner
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 21; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (((7-x) + y + (7-z) <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (((7-x) + y + z <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 20; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (((7-x) + y + (7-z) <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (((7-x) + y + z <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Bottom left to top right
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + z <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + (7-z) <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + z <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + (7-z) <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Top right to bottom left
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + z >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + (7-z) >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + z >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + (7-z) >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
 
   Change_Colour();

   // Bottom back to top front
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((y + z <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((y + (7-z) <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((y + z <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((y + (7-z) <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Top front to bottom back
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((y + z >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((y + (7-z) >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((y + z >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((y + (7-z) >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Bottom right to top left
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + (7-z) >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + z >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + (7-z) >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + z >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Top left to bottom right
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + (7-z) <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + z <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((x + (7-z) <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((x + z <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Bottom front to top back
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((y + (7-z) >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((y + z >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((y + (7-z) >= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((y + z >= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Top back to bottom front
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((y + (7-z) <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((y + z <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( ((y + (7-z) <= layer)  && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             ((y + (z) <= layer)  && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Back left to front right
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( x + y <= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( x + y <= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Front right to back left 
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( x + y >= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( x + y >= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Back right to front left
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (7-x) + y <= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (7-x) + y <= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Front left to back right 
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 14; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (7-x) + y >= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer <= 15; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (7-x) + y >= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Back to front
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 8; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( y <= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 7; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( y <= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Front to back
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 7; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( y >= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer < 8; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( y >= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Left to right
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 8; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( x <= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 7; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( x <= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Right to left
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 7; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( x >= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer < 8; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( x >= layer) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   Change_Colour();

   // Bottom to top
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 0; layer <= 8; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (( z <= layer) && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (( (7-z) <= layer) && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 7; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (( z <= layer) && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (( (7-z) <= layer) && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }

   // Top to bottom
   // Blank
   for (d = 0; d < LED_COUNT; d++) {
    colors[d] = (rgb_color){rb, gb, bb};
   }
   // Write the colors to the LED strip.
   ledStrip.write(colors, LED_COUNT);
   delay(50);
   for (layer = 7; layer >= 0; layer--) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (( z >= layer) && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (( (7-z) >= layer) && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
   for (layer = 0; layer < 8; layer++) {
     for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
       for (z = 0; z < 8; z++) {
        if ( (( z >= layer) && ((x == 0) || (x == 2) || (x == 4) || (x == 6))) ||
             (( (7-z) >= layer) && ((x == 1) || (x == 3) || (x == 5) || (x == 7))) ) {
         colors[z+x*8+y*64] = (rgb_color){r, g, b};
        }
        else {
         colors[z+x*8+y*64] = (rgb_color){rb, gb, bb};
        }
       }
      }
     }
    // Write the colors to the LED strip.
    ledStrip.write(colors, LED_COUNT);
    delay(50);
   }
}
