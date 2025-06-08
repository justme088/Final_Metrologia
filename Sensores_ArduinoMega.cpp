#include <Wire.h>
#include "SparkFun_SHTC3.h"
#include <Adafruit_MLX90614.h>

SHTC3 shtc3;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// Pines del HC-SR04
const int trigPin = 22;
const int echoPin = 23;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Inicializar SHTC3
  while (shtc3.begin() != SHTC3_Status_Nominal) {
    //Serial.println("Reintentando SHTC3...");
    delay(1000);
  }

  // Inicializar MLX90614
  if (!mlx.begin()) {
    //Serial.println("Error al iniciar GY-906 (MLX90614)");
    while (1); // Detener si falla
  }

  // Pines ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  leerSHTC3();
  leerMLX90614();
  leerUltrasonico();

  delay(1000); // Espera entre lecturas
}

void leerSHTC3() {
  if (shtc3.update() == SHTC3_Status_Nominal) {
    float tempC = shtc3.toDegC();
    float hum = shtc3.toPercent();
    //Serial.print("SHTC3 - Temp: "); Serial.print(tempC); Serial.print(" °C, Hum: "); Serial.print(hum); Serial.println(" %");
    Serial.print(hum); Serial.print(",");
  } else {
    //Serial.println("Error al leer SHTC3. Reintentando...");
    shtc3.begin(); // Intentar reconectar
  }
}

void leerMLX90614() {
  //float tempAmb = mlx.readAmbientTempC();
  float tempObj = mlx.readObjectTempC();
  //Serial.print("GY-906 - Ambiente: "); Serial.print(tempAmb); Serial.print(" °C, Objeto: "); Serial.print(tempObj); Serial.println(" °C");
  Serial.print(tempObj); Serial.print(",");
}

void leerUltrasonico() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracion = pulseIn(echoPin, HIGH);
  float distancia = duracion * 0.034 / 2; // cm
  //Serial.print("HC-SR04 - Distancia: "); Serial.print(distancia); Serial.println(" cm");
  Serial.println(distancia);
}
