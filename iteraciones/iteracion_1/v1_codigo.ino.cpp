#include <Arduino.h>

// Pin ADC del sensor capacitivo de humedad v1.2
#define PIN_HUMEDAD 4

// Valores crudos iniciales de referencia (12 bits: 0 - 4095)
const int RAW_SECO   = 2965;  // Sensor al aire
const int RAW_MOJADO = 2300;  // Sensor en sustrato húmedo

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Prueba Iteracion 1 - Sensor Capacitivo de Humedad v1.2");
  Serial.println("------------------------------------------------------");
}

void loop() {
  int rawHumedad = analogRead(PIN_HUMEDAD);
  int pctHumedad = map(rawHumedad, RAW_SECO, RAW_MOJADO, 0, 100);
  pctHumedad = constrain(pctHumedad, 0, 100);

  Serial.print("ADC Raw Humedad: ");
  Serial.print(rawHumedad);
  Serial.print("  |  Humedad estimada: ");
  Serial.print(pctHumedad);
  Serial.println(" %");

  delay(2000);
}



#include <Arduino.h>

// Pin ADC del sensor fotorresistor KY-018
#define PIN_LUZ 5

// Valores crudos iniciales de referencia
const int RAW_LUZ_OSCURO = 3800;  // Oscuridad
const int RAW_LUZ_SOL    = 500;   // Luz intensa

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Prueba Iteracion 1 - Sensor de Luz KY-018");
  Serial.println("-----------------------------------------");
}

void loop() {
  int rawLuz = analogRead(PIN_LUZ);
  int pctLuz = map(rawLuz, RAW_LUZ_OSCURO, RAW_LUZ_SOL, 0, 100);
  pctLuz = constrain(pctLuz, 0, 100);

  Serial.print("ADC Raw Luz: ");
  Serial.print(rawLuz);
  Serial.print("  |  Luz ambiente: ");
  Serial.print(pctLuz);
  Serial.println(" %");

  delay(2000);
}
