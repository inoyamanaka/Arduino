// C++ code
//

// INTEGER
int ledpin = 13;
int mydelay = 500;

// FLOAT
float led = 12.2

void setup()
{
  // MEMBUAT LAMPU MENYALA SEBAGAI OUTPUT 
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  
  // Print something
  Serial.println(mydelay);
  
  // increment 
   Serial.println(mydelay++);
  
  // decrement
  Serial.println(mydelay--);
  
  // + Operator
  Serial.println(mydelay+ledpin);
  Serial.println(mydelay-ledpin);
  Serial.println(mydelay*ledpin);
  Serial.println(mydelay/ledpin);
}

void loop()
{
  digitalWrite(ledpin, HIGH);
  delay(mydelay); // Wait for 1000 millisecond(s)
  
  digitalWrite(ledpin, LOW);
  delay(mydelay); // Wait for 1000 millisecond(s)
}
