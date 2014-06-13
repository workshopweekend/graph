// LED Matrix Graph
// by J.D. Zamfirescu
// Last update: June 2014
// graph.ino

#include "HT1632.h" // Get this library here: http://github.com/workshopweekend/HT1632

#define DATA 2
#define WR   3
#define CS   4

HT1632LEDMatrix matrix = HT1632LEDMatrix(DATA, WR, CS);

const int numSamples = 24;

int a_values[numSamples], b_values[numSamples];
int ptr = 0;

void setup() {
  matrix.begin(HT1632_COMMON_16NMOS);
  matrix.clearScreen();
  Serial.begin(9600);
}

void loop() {
  matrix.setScreen(0);
  for (int i = 0; i < numSamples; i++) {
    matrix.drawLine(i, b_values[(ptr+i)%numSamples], i, a_values[(ptr+i)%numSamples], 1);
  }
  matrix.writeScreen();
  a_values[ptr] = getAValue();
  b_values[ptr] = getBValue();
  ptr = (ptr + 1) % numSamples;
  delay(50);
}

int getAValue() {
  return analogRead(A0)/64;
}

int getBValue() {
  return analogRead(A1)/64;
}