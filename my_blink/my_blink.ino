/*
Program symulujacy odbijanie pileczki na osmiu diodach,
zakomentowana wersja dziala tylko w jedna strone, na razie nie wiem jak wypisac output do terminala, ale prawdopodobnie wartosc portb przy koncu
podrozy pileczki w prawa strone jest nieprawidlowa. wyizolowana wersja odbijania w lewa strone dziala prawidlowo, ale w polaczeniu z odbijaniem w prawo
i uzywaniem countera cos sie psuje. Mam wrazenie ze counter powinien byz zainicjalizowany jako 1(jednak nie)

pamietaj: 0/low  - lampka zapalona
          1/high = lapmpka zgaszona
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
//  if (counter%16 <8) {
//    PORTB = PORTB>>1;
//    PORTB = PORTB|canvas;
//  }  else {
//    PORTB = PORTB<<1;
//    PORTB = PORTB|canvas_reverse;
//  }
  
  
//  printf("counter: %d portb: %d \n", counter, PORTB);
//  counter++;
//  Serial.print(counter);

   
  for(int i = 7; i>=0; i--) {
    PORTB = ~(1<<i);
    delay(200);
  }
  for(int i = 0; i<8; i++) {
    PORTB = ~(1<<i);
    delay(200);
  }

  
}
