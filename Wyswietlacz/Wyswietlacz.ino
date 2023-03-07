#define click_inc 23
#define click_dec 22

byte tab[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};
int digits[] = {0,0,0,0};
byte disp[] = {B11110111,B1111011,B11111101,B11111110};
int val = 0;
int len = 1;
void setup() {
  // put your setup code here, to run once:
  DDRB = 255;
  DDRA = 255;
  PORTB = ~63;
  pinMode(click_inc, INPUT_PULLUP);
  pinMode(click_dec, INPUT_PULLUP);

}
void loop() {
 val = digitalRead(click_inc);
   if(digitalRead(click_inc) == LOW) {
     increment();
     delay(200);
   } else if(digitalRead(click_dec) == LOW) {
     decrement();
     delay(200);
   }
   
     for(int i = 0; i < 0; i ++) {
       PORTA = disp[i];
       PORTB = ~tab[digits[i]];
       delay(2);
     }
}

void increment() {
  for (int i = 3; i >= 0; i--) {
     int sum = digits[i]+1;
     if(sum == 10) {
       digits[i] = 0;
     } else {
       digits[i] = sum;
       break;
     }
  }  
  len += 1;
}

void decrement() {
  for (int i = 3; i >= 0; i--) {
     int diff = digits[i]-1;
     if(diff == -1) {
       digits[i] = 9;
     } else {
       digits[i] = diff;
       break;
     }
  }  
  len -= 1;
}
