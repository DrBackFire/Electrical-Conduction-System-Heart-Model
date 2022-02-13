#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIXEL_PIN    8  // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 24  // Number of NeoPixels

const int Pins[6] = {2, 3, 4, 5, 6};

const int upperChamber[5] = {5, 4, 0, 14};

const int bundleOfHis[9] = {1, 2, 3, 6, 7, 8, 9, 10};

const int leftBranch[4] = {11, 12, 13};

const int rightBranch[4] = {15, 16, 17};


// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

boolean newState = HIGH;

boolean isNormalSpeed = true;

int button;


void setup() {
  setupPins();

  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'
}

void loop() {
  newState = HIGH;
   readInput();
 
    if(newState == LOW) {
        if (button == 2) {
           // Toggle delay
          toggleSpeed();
          }

         if (button == 3) {
           runNormalSinus();
          }

          if (button == 4) {
            run1stDBlock();
          }

          if (button == 5) {
             //run2ndDBlockT2();
             run3rdDBlock();
          }

          if (button == 6) {
            run3rdDBlock();
          }
    }
}

void setupPins() {
   int buttonsNbr = 6;

 for (int i = 0; i < buttonsNbr; i++) {
        pinMode(Pins[i], INPUT_PULLUP);
    }
}

void readInput() {
   // Loop to read buttons increase the number in the Pins list and below var if you add more buttons
  int buttonNbr = 6;
  
   for (int i = 0; i < buttonNbr && newState == HIGH; i++) {
       button = Pins[i];
       newState = digitalRead(Pins[i]);
   }
}

void toggleSpeed() {
  isNormalSpeed = !isNormalSpeed;
}

void runBundleOfHis(int delayNbr, int color[4]) {
  for(int a= 0; a<=7; a++) {
    showLight(bundleOfHis[a], delayNbr, color);
  }  
}

void runUpperChamber(int delayNbr, int color[4]) {
  for(int a= 0; a<=3; a++) {
    showLight(upperChamber[a], delayNbr, color);
  } 
}

void runLeftBranch(int delayNbr, int color[4]) {
   for(int a= 0; a<=2; a++) {
    showLight(leftBranch[a], delayNbr, color);
  }
}

void runRightBranch(int delayNbr, int color[4]) {
   for(int a= 0; a<=2; a++) {
    showLight(rightBranch[a], delayNbr, color);
  }
}

void runfBothBranches(int delayNbr, int color[4]) {
   for (int b=0; b<=2; b++) {
     strip.setPixelColor(leftBranch[b], strip.Color(color[0],   color[1],   color[2]));
     strip.setPixelColor(rightBranch[b], strip.Color(color[0],   color[1],   color[2]));
     strip.show();
     delay(delayNbr);
     strip.setPixelColor(leftBranch[b], strip.Color(0,   0,   0));
     strip.setPixelColor(rightBranch[b], strip.Color(0,   0,   0));
     strip.show();
     delay(delayNbr);                  
  }
}

void showLight(int lightColorNbr, int delayNbr, int color[4]) {
   strip.setPixelColor(lightColorNbr, strip.Color(color[0],   color[1],   color[2]));
   strip.show();
   delay(delayNbr);
   strip.setPixelColor(lightColorNbr, strip.Color(0,   0,   0));
   strip.show();
   delay(delayNbr);
}

void runNormalSinus() {
   // SA/AV Node Flashing white LED
  int lightColor[4] = {255, 255, 255};

  // Speed
  int delayNbr;

  if (isNormalSpeed == false) {
      delayNbr = 120;
   } else {
      delayNbr = 40;
    }


  for(int a=0; a<=2; a++) {
    showLight(a, delayNbr, lightColor);
  }

  int blue[4] = { 0, 0, 255 };

  runBundleOfHis(delayNbr, blue);
  runfBothBranches(delayNbr, blue);
}

void runPAC() {
  // SA/AV Node Flashing white LED
  int lightColor[4] = {255, 255, 255};

  // Speed
  int delayNbr;

  if (isNormalSpeed == false) {
      delayNbr = 120;
   } else {
      delayNbr = 40;
    }


  for(int a=0; a<=1; a++) {
    showLight(0, delayNbr, lightColor);
  }

  int blue[4] = { 0, 0, 255 };

  runBundleOfHis(delayNbr, blue);
  runfBothBranches(delayNbr, blue);
}

void runSinusBar(){
  // SA/AV Node Flashing white LED
  int lightColor[4] = {255, 255, 255};

  // Speed
  int delayNbr;

  if (isNormalSpeed == false) {
      delayNbr = 220;
   } else {
      delayNbr = 120;
    }


  for(int a=0; a<=2; a++) {
    showLight(a, delayNbr, lightColor);
  }

  runBundleOfHis(delayNbr, lightColor);
  runfBothBranches(delayNbr, lightColor);
}

void runSinusTac(){
  // SA/AV Node Flashing white LED
  int lightColor[4] = {255, 255, 255};

  // Speed
  int delayNbr;

  if (isNormalSpeed == false) {
      delayNbr = 120;
   } else {
      delayNbr = 30;
    }


  for(int a=0; a<=2; a++) {
    showLight(a, delayNbr, lightColor);
  }

  runBundleOfHis(delayNbr, lightColor);
  runfBothBranches(delayNbr, lightColor);
}

void run1stDBlock() {
  // SA/AV Node Flashing white LED
  int lightColor[4] = {255, 255, 255};
  
  // Speed
  int delayNbr;

  if (isNormalSpeed == false) {
      delayNbr = 120;
   } else {
      delayNbr = 40;
    }
  
  showLight(0, 300, lightColor);
  showLight(4, 150, lightColor);
   
  runBundleOfHis(delayNbr, lightColor);
  runfBothBranches(delayNbr, lightColor);
}

void run2ndDBlockT1() {
   // SA/AV Node Flashing white LED
   int lightColor[4] = {255, 255, 255};

   // Speed
   //int delayNbr;
   //if (isNormalSpeed == false) {
   //   delayNbr = 120;
   // } else {
   //   delayNbr = 40;
   //  }
    
   // Normal SA/VA trans.
   showLight(0, 120, lightColor);
   showLight(4, 120, lightColor);

   runBundleOfHis(40, lightColor);
   runfBothBranches(40, lightColor);

   // Delayed
   showLight(0, 200, lightColor);
   showLight(4, 200, lightColor);

   runBundleOfHis(50, lightColor);
   runfBothBranches(50, lightColor);

   // Delayed
   showLight(0, 250, lightColor);
   showLight(4, 250, lightColor);

   runBundleOfHis(70, lightColor);
   runfBothBranches(70, lightColor);

   // Last one does not go through
   showLight(0, 250, lightColor);
   showLight(4, 250, lightColor);
}

void run2ndDBlockT2() {
   // SA/AV Node Flashing white LED
   int lightColor[4] = {255, 255, 255};

  // Speed
  int delayNbr;

  if (isNormalSpeed == false) {
      delayNbr = 120;
   } else {
      delayNbr = 40;
    }
   
  for(int a=0; a<=2; a++) {
    showLight(0, 400, lightColor);
    showLight(4, 400, lightColor);
  }
  
  runBundleOfHis(delayNbr, lightColor);
  runfBothBranches(delayNbr, lightColor);
}

void run3rdDBlock() {
  // SA/AV Node Flashing white LED
  int lightColor[4] = {255, 255, 255};

  // Speed
  int delayNbr;

  if (isNormalSpeed == false) {
      delayNbr = 120;
   } else {
      delayNbr = 40;
    }
   
  showLight(0, 400, lightColor);
  showLight(4, 400, lightColor);

  delay(200);
  
  runBundleOfHis(delayNbr, lightColor);
  runfBothBranches(delayNbr, lightColor);
}

void runControlledAF() {
   // SA/AV Node Flashing white LED
  int lightColor[4] = {255, 255, 255};
  
  // Speed
  int delayNbr;

  if (isNormalSpeed == false) {
      delayNbr = 220;
   } else {
      delayNbr = 120;
    }

  int blue[4] = { 0, 0, 255 };
  
  for(int a=0; a<=2; a++) {
    showLight(0, delayNbr, lightColor);
  }
 
   
  runBundleOfHis(delayNbr, lightColor);
  runfBothBranches(delayNbr, lightColor);
}

void runUnControlledAF() {
   // SA/AV Node Flashing white LED
  int lightColor[4] = {255, 255, 255};
  
  // Speed
  int delayNbr;

  if (isNormalSpeed == false) {
      delayNbr = 220;
   } else {
      delayNbr = 30;
    }

  int blue[4] = { 0, 0, 255 };
  
  for(int a=0; a<=2; a++) {
    showLight(0, delayNbr, lightColor);
  }
 
   
  runBundleOfHis(delayNbr, lightColor);
  runfBothBranches(delayNbr, lightColor);
}
