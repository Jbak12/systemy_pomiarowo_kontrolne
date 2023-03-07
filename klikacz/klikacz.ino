/*
program pobierajacy dane z przycisku, ktory jest polaczaony z pinem nr 8,
nacisniety przycisk ustawia na pinie wartosc low, wtedy zwieksza licznik ustawiony poczatkowo na 0,
i wyswietla licznik w binarnej reprezentacji na 8 diodach

pamietaj: pin ustawiony na 0/low - dioda sie swieci
pin ustawiony na 1/high - dioda pozostaje zgaszona
*/

int val = 0;
int counter = 0;
int click_pin = 8;
// the setup function runs once when you press reset or power the board
void setup() {
  //data direection
  DDRB = B11111111;
  PORTB = B11111111;
  pinMode(click_pin,INPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  val = digitalRead(click_pin);
  if(val == LOW) {
    counter++;
    PORTB = ~counter;

    delay(300);
  }

}
