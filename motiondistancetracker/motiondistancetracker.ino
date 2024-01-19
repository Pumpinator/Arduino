#define pir 2
#define trig 3
#define echo 7
#define alert 8

boolean pirStatus;
long distance = 0;
long time = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(alert, OUTPUT);
}

void loop() {
  pirStatus = digitalRead(pir);
  if (pirStatus == HIGH) {
    Serial.print("MOTION DETECTED ");
    digitalWrite(alert, HIGH);
    digitalWrite(trig, LOW);
    time = pulseIn(echo, HIGH);
    distance = int(0.0176 * time);
    Serial.print(distance);
    Serial.println(" CM AWAY");
  } else {
    digitalWrite(alert, LOW);
  }
}
