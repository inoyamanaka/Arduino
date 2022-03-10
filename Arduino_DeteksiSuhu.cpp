#include <LiquidCrystal_I2C.h>;
const float BETA = 3950;
LiquidCrystal_I2C lcd(0x27, 20, 4);


void setup() {
  // put your setup code here, to run once:
   // should match the Beta Coefficient of the thermistor
   Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);
   lcd.init();
   lcd.backlight();
   lcd.setCursor(1, 0);
   lcd.print("WELCOME");
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  lcd.setCursor(1, 0);
  lcd.print("Suhu :");
  lcd.print(celsius);
  lcd.print(" C");

  if (celsius >= 40){
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       
  }else{
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(1000); 
  }

  delay(100);

}
