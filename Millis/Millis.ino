#include <stdint.h>

uint64_t tiempoAnterior = 0;
int contador = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  uint64_t tiempoActual = millis();
  
  if (tiempoActual - tiempoAnterior >= 1000) {
    tiempoAnterior = tiempoActual;
    contador++;
    
    Serial.println(contador);
  }
}
