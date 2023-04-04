#include <LiquidCrystal.h>
#define days_diode_pin 21
#define hours_diode_pin 22
#define minutes_diode_pin 23

#define days_programming_click_pin 18
#define hours_programming_click_pin 19
#define minutes_programming_click_pin 20

#define increase_click 16
#define decrease_click 17

#define minutes_mode 0
#define hours_mode 1
#define working_mode 2

//ustawianie lcd
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char date[8] = {'0','0','.','0','0','.','0','0'};
int last_millis = 2;
int mode = working_mode;
void setup() {
  DDRC = B11100000;
  PORTC = 255;
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("04.04.2023");
  digitalWrite(23,LOW);
}
int hours = 0;
int minutes = 0;
float seconds = 0;
int current_mode = 2;
void loop() {
  
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:    lcd.print(date);
    if(digitalRead(minutes_programming_click_pin) == LOW) {
       if(mode == working_mode) {
         digitalWrite(minutes_diode_pin,LOW);
         mode = minutes_mode;
       }else if (mode == minutes_mode) {
          digitalWrite(minutes_diode_pin,HIGH);
          mode = working_mode;
       }
    }
    if(digitalRead(hours_programming_click_pin) == LOW) {
       if(mode == working_mode) {
         digitalWrite(hours_diode_pin,LOW);
         mode = hours_mode;
       }else if (mode == minutes_mode) {
          digitalWrite(hours_diode_pin,HIGH);
          mode = working_mode;
       }
    }  
    
    if (mode = working_mode) {
      lcd.print(String(hours));
      seconds += 0.1;
    }
    delay(100);
  //lcd.print(millis() / 1000);
}
