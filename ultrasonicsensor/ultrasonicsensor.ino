/* Uso del sensor ultrasónico HC-SR04
 *  Este Programa utiliza un sensor ultrasónico para medir distancias a un objeto
 *  y muestra la distancia en un rango de 2 cm a 400 cm encontrada en el monitor serie de Arduino
 *  NOTA: El canal trigger está conectado al pin 6 y el canal echo al pin 7
 *
 */

// Declaración de la variable TRIG que almacena el pin al que está conectado el canal TRIGGER del sensor
int TRIG = 3;
// Declaración de la variable ECHO que almacena el pin al que está conectado el canal ECHO del sensor
int ECHO = 7;
// Declaración de variables
long distance = 0;
long time = 0;

void setup() {
  Serial.begin(9600);
  // Activación del pin TRIG como salida
  pinMode(TRIG, OUTPUT);
  // Activación del pin ECHO como entrada
  pinMode(ECHO, INPUT);
  // Garantizar que la señal trigger inicie en bajo
  digitalWrite(TRIG, LOW);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  // Se envía un pulso de 10 microsegundos
  digitalWrite(TRIG, LOW);
  // Activación de la señal ultrasónica
  /* pulseIn es la función que mide la longitud del pulso entrante.
      Mide el tiempo que transcurre entre el envío del pulso ultrasónico del pin TRIG
      y la recepción de la señal de rebote por el pin ECHO
  */
  time = pulseIn(ECHO, HIGH);
  // Cálculo de la distancia (número entero)
  distance = int(0.01716 * time);
  /* Impresión de la distancia en el monitor serial*/
  Serial.print("Distance ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();
  // Pausa de 100 milisegundos
  delay(100);
}