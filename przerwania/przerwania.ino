void setup() {
  // put your setup code here, to run once:
  
  TCCR1A = 0;
  TCCRIB = 5;
  TIMSK = (1<<TO1E1)
  SREG = SREG|128

}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
