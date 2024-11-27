#include <stdint.h>

uint64_t tiempoAnteriorCtr1 = 0;
uint64_t tiempoAnteriorCtr2 = 0;
int ctr1 = 0;
int ctr2 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  uint64_t tiempoActual = micros();

  if (tiempoActual - tiempoAnteriorCtr1 >= 100000) {
    tiempoAnteriorCtr1 = tiempoActual;
    ctr1++;
    Serial.print("C1: ");
    Serial.print(ctr1);
    Serial.print(" C2: ");
    Serial.println(ctr2);
  }

  if (tiempoActual - tiempoAnteriorCtr2 >= 2000000) {
    tiempoAnteriorCtr2 = tiempoActual;
    ctr2++;
    ctr1 -= ctr2;
    Serial.print("C1: ");
    Serial.print(ctr1);
    Serial.print(" C2: ");
    Serial.println(ctr2);
  }
}
