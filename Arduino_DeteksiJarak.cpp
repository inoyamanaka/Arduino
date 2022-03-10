// Sensor Jarak
// Kelompok 6:
// 5200411055 - Muhammad Annas Ma'ruf
// 5200411135 - Muhammad Naufal Alfa'iz Musthofa
// 5200411416 - Muhammad Ilham Triwibowo
// 5200411434 - Herlambang Kurniawan

// menambahkan library untuk lcd
#include <LiquidCrystal.h>

// pin
const int TRIG_PIN = 4;
const int ECHO_PIN = 2;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {

  // set trigger pin untuk memastikan jarak
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  // set echo pin
  pinMode(ECHO_PIN, INPUT);

  lcd.begin(20, 4);
  lcd.setCursor(5, 0);
  lcd.print("Kelompok 6");
  lcd.setCursor(2, 2);
  lcd.print("Jarak: ");
  lcd.setCursor(15, 2);
  lcd.print("cm");
}

void loop() {
  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;
  double cm;

  // memberikan delay 12ms untuk pin trigger
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(12);
  digitalWrite(TRIG_PIN, LOW);

  // menunggu tekanan dari pin echo
  while ( digitalRead(ECHO_PIN) == 0 );

  // menghitung berapa jauh jarak
  t1 = micros();
  while ( digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;
  cm = pulse_width / 58.0;

  lcd.setCursor(9, 2);
  lcd.print(cm);

  // memberikan delay 50ms untuk pengecekan berikutnya
  delay(50);
}
