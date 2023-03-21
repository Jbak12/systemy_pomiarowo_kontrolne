#define trigPin 12
#define echoPin 11
#define soundConstant 58

byte tab[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};
byte loop_values[] = {B11110111,B11111011,B11111101,B11111110};
int digits[] = {0,0,0,0} ;
int dist; 
int n = 0;
byte digit_counter = 0;
void setup() {
  
  TCNT1H = 255;
  TCNT1L = 150;
  
  //ustawianie setupu do przerwan
  TCCR1A = 0;
  TCCR1B = 1;
  // dla tccrib 2, n zwiekszane 15 razy na sek, dla 4- 1, dla 5- 0, dla 3- 2, dla 1- 122
  TIMSK = (1<<TOIE1)|TIMSK;
  SREG = SREG|128;
  
  //ustawianie portow wyjscia i data direction
  DDRB = 255;
  DDRA = 255;
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //Pin, do ktĂłrego podĹ‚Ä…czymy trig jako wyjĹ›cie
  pinMode(echoPin, INPUT); //a echo, jako wejĹ›cie
}
 
void loop() {

  dist = zmierzOdleglosc();
  Serial.print(dist);
  convert_to_array(digits, 4, dist);
  Serial.println(" cm");
  delay(100);
    
} 

int zmierzOdleglosc() {
  long czas, dystans;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas *0.034 / 2;
 
  return dystans;
}


void convert_to_array(int *tab, int size, int num) {
    for (int i = 0; i < size; ++i, num /= 10)
        tab[(size - 1) - i] = num % 10;
}

ISR(TIMER1_OVF_vect) {
  PORTA = loop_values[digit_counter%4];
  PORTB = ~tab[digits[digit_counter%4]];
  digit_counter++;
  TCNT1H = 255;
  TCNT1L = 150;
}

