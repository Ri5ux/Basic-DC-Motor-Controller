static int PIN_PWM = 9;
static int PIN_CONTACTOR = 8;
static int PIN_POTENTIOMETER = 0;

int duty = 0;

void setup() {
  TCCR1B = (TCCR1B & 0b11111000) | 0x01;
  pinMode(PIN_PWM, OUTPUT);
  pinMode(PIN_CONTACTOR, OUTPUT);
  
  Serial.begin(9600);
  
  Serial.println("Precharge...");
  delay(1000);
  digitalWrite(PIN_CONTACTOR, 255);
  Serial.println("Ready.");
}

void loop() {
  int pot = analogRead(PIN_POTENTIOMETER);
  duty = map(pot, 0, 1023, 0, 100);

  if (duty < 10)
  {
    duty = 0;
  }

  analogWrite(PIN_PWM, map(duty, 0, 100, 0, 255));
}
