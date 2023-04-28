#include <Keyboard.h>

#define keyCount 5
#define debounceDelay 20

uint8_t keys[keyCount] = {'a', 'b', 'c', 'd', 'e'};
int pins[keyCount] = {2,3,4,5,6};
bool down[keyCount] = {false,false,false,false};
unsigned long lastChange[keyCount] = {0,0,0,0,0};
void setup() {

for(int i = 0; i < keyCount; i++)
  pinMode(pins[i], INPUT_PULLUP);
}

void loop() {
  for(int i = 0; i < keyCount; i++)
  {
    // just ignore this button as long as the delay hasn't passed
    if ((lastChange[i]+debounceDelay) > millis())
      return; 

    if (!down[i] && digitalRead(pins[i]) == LOW)
    {
      Keyboard.press(keys[i]);
      lastChange[i] = millis();
      down[i] = true;
    }
    if (down[i] && digitalRead(pins[i]) == HIGH)
    {
      Keyboard.release(keys[i]);
      lastChange[i] = millis();
      down[i] = false;
    }
  }
}