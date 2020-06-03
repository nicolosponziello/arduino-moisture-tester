#include<LiquidCrystal.h>

#define MAX_COUNT 10
int pin = A0;
int value ;
int count = 0;
int values[10];
double avg;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
 Serial.begin(9600);
 lcd.begin(16, 2);
 lcd.print("Starting");
 delay(2000);
}

void loop() {
   
  value = analogRead(pin);
  value = map(value,550,0,0,100);
  if(value <= 100 && value >= 0){
    values[count] = value;
    count++;
  }
  if(count == MAX_COUNT){    
    for(int i = 0; i < MAX_COUNT; i++){
      avg += values[i];
    }
    avg /= MAX_COUNT;
    lcd.setCursor(0, 0);
    lcd.print("Moisture: ");
    lcd.print(avg);
    count = 0;
    avg = 0;
  }else{
    lcd.setCursor(0,0);
    lcd.print("Analyzing ");
    lcd.print(count*10);
    lcd.print("%");
  }
  delay(1000);
}
