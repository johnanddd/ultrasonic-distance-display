#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
// Constructor parameters: lcd(RS, E, D4, D5, D6, D7);

const int ultra_sensor_trig = 8;
const int ultra_sensor_echo = 9;


void setup() {
  lcd.print("Starting...");
  pinMode(ultra_sensor_trig, OUTPUT);
  pinMode(ultra_sensor_echo, INPUT);
  delay(1000);
  lcd.clear();
}

double first_distance = 0;
double second_distance = 0;
double third_distance = 0;
double fourth_distance = 0;
double fifth_distance = 0;
double filtered_distance = 0;

int loop_count = 0;

void loop() {
  loop_count += 1;

  digitalWrite(ultra_sensor_trig, HIGH);
  delayMicroseconds(10); // 10 microseconds!!
  digitalWrite(ultra_sensor_trig, LOW);


  while (digitalRead(ultra_sensor_echo) == false)
  {
       // do nothing
  }

  unsigned long start_time = micros();

  while (digitalRead(ultra_sensor_echo) == true)
  {
      //time started above, now we wait
  }

  unsigned long micro_time_taken = micros() - start_time;
  double current_centimeters = micro_time_taken / 1000000.00 * 343 / 2 * 100;

  if (loop_count % 5 == 0)
  {
    lcd.clear();
    lcd.print("Centimeters: ");
    filtered_distance = (first_distance + second_distance + third_distance + fourth_distance + fifth_distance) / 5; 
    lcd.print(filtered_distance);
  }

  fifth_distance = fourth_distance;
  fourth_distance = third_distance;
  third_distance = second_distance;
  second_distance = first_distance;
  first_distance = current_centimeters;

  delay(50);
}
