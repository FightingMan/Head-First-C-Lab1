const short LED_PIN    = 13;
const short THRESHOLD = 800;
const short INTERVAL   = 10000;
const short SERIAL_BAUD_RATE = 9600;

boolean needs_water() {  
  short moisture = analogRead(A0);
  Serial.print(moisture);
  Serial.print(":\t");
  if (moisture < THRESHOLD) {
    return true;
  } else {
    return false;
  }
}
void indicate_dry()
{
  digitalWrite(LED_PIN, HIGH);
  Serial.println("Feed Me!"); 
}
void indicate_moist()
{
  digitalWrite(LED_PIN, LOW);
  Serial.println("Thank You, FightingMan!"); 
}

void setup()
{
  Serial.begin(SERIAL_BAUD_RATE);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  if (needs_water()) {
    indicate_dry();
  } else {
    indicate_moist();
  }

  delay(INTERVAL);
}
