#define pir 2
#define led 8

boolean sensorStatus;

void setup() {
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  sensorStatus = digitalRead(pir);
  if (sensorStatus == HIGH) {
    Serial.println("Movement detected");
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
    Serial.print("");
  }
  delay(1000);
}