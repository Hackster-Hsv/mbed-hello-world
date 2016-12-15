#include "mbed.h"

Ticker toggle_led_ticker;
 
DigitalIn mybutton(USER_BUTTON);
DigitalOut led1(LED1);

void toggle_led() {
    led1 = !led1;
}

double totalTime = 0;
 
int main() {
  while(1) {
    if (mybutton == 0) {
        while( mybutton == 0) {
            wait(0.1);
            totalTime+=0.1;
        }
        toggle_led_ticker.attach(&toggle_led, totalTime);
        led1 = !led1;
        totalTime = 0.0;
    }
  }
}
 
