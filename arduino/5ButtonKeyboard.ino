#include <Keyboard.h>

#define keyCount 5

uint8_t keys[keyCount] = {'a', 'b', 'c', 'd', 'e'};
int pins[keyCount] = {2,3,4,5,6};
bool down[keyCount] = {false,false,false,false};

void setup() {

for(int i = 0; i < keyCount; i++)
  pinMode(pins[i], INPUT_PULLUP);
}

void loop() {
  for(int i = 0; i < keyCount; i++)
  {
    if (!down[i] && digitalRead(pins[i]) == LOW)
    {
      Keyboard.press(keys[i]);
      down[i] = true;
    }
    if (down[i] && digitalRead(pins[i]) == HIGH)
    {
      Keyboard.release(keys[i]);
      down[i] = false;
    }
  }
}