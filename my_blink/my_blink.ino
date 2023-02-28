/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board

int canvas = B10000000;
int canvas_reverse = B00000001;
int counter = 0;
void setup() {
  DDRB = B11111111;
  PORTB = B01111111;
  
}

// the loop function runs over and over again forever
void loop() {
delay(500);
//  if (counter%16 <7) {
//    PORTB = PORTB>>1;
//    PORTB = PORTB|canvas;
//  }  else {
//    PORTB = PORTB<<1;
//    PORTB = PORTB|canvas_reverse;
//  }
  
//    PORTB = PORTB<<1;
//    PORTB = PORTB|canvas_reverse;
  
//  printf("counter: %d portb: %d \n", counter, PORTB);
  counter++;

   
  for(int i = 7; i>=0; i--) {
    PORTB = ~(1<<i);
    delay(200);
  }
  for(int i = 0; i<8; i++) {
    PORTB = ~(1<<i);
    delay(200);
  }

  
//  digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
// wait for a second
//  digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);              // wait for a second
}
