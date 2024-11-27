#include <stdint.h>

int valor = 1;
uint64_t intervalo = 1000;
uint64_t lastTime = 0;
bool running = false;
bool modoAlternativo = false;

void setup() {
  Serial.begin(9600);
    while (!Serial) {
    ;
  }
  delay(1000);
  mostrarMenu();
}

void loop() {
  if (Serial.available() > 0) {
    String comando = Serial.readString();

    comando.trim();
    comando.toUpperCase();

    if (comando == "H") {
      mostrarMenu();
    } else if (comando == "START") {
      start();
    } else if (comando == "TIME") {
      cambiarTiempo();
    } else if (comando == "MODE") {
      cambiarModo();
    } else if (comando == "STOP") {
      stop();
    } else {
      Serial.println("Comando no reconocido. Usa 'H' para ayuda.");
    }
  }

  if (running) {
    uint64_t currentMillis = millis();
    if (currentMillis - lastTime >= intervalo) {
      lastTime = currentMillis;

      if (modoAlternativo) {
        valor = (valor == 0) ? 1 : 0;
      }
      Serial.println(valor); 
    }
  }
}

void mostrarMenu() {
  Serial.println("Menu de ayuda:");
  Serial.println("H o h (help): Muestra este menu de ayuda.");
  Serial.println("START o start: Comienza a publicar el valor cada segundo.");
  Serial.println("STOP o stop: Detiene la publicacion del valor.");
  Serial.println("T o t (time): Cambia el periodo de publicacion de la señal entre 1 y 10 veces por segundo.");
  Serial.println("M o m (mode): Cambia el modo de fijo a alternativo.");
  Serial.println("Por defecto, el modo es fijo y el valor inicial es 1.");
}

void start() {
  running = true;
  Serial.println("Publicacion iniciada.");
}

void stop() {
  running = false;
  Serial.println("Publicacion detenida.");
}

void cambiarTiempo() {
  Serial.println("Ingrese el nuevo tiempo (1-10):");

  while (Serial.available() == 0);

  int nuevoTiempo = Serial.parseInt();

  if (nuevoTiempo >= 1 && nuevoTiempo <= 10) {
    intervalo = 1000 / nuevoTiempo;
    Serial.print("Nuevo intervalo: ");
    Serial.print(nuevoTiempo);
    Serial.println(" veces por segundo.");
  } else {
    Serial.println("Valor invalido. El intervalo debe estar entre 1 y 10.");
  }
}

void cambiarModo() {
  if (modoAlternativo) {
    modoAlternativo = false;
    Serial.println("Modo cambiado a Fijo. El valor es siempre 1.");
  } else {
    modoAlternativo = true;
    Serial.println("Modo cambiado a Alternativo. El valor alternará entre 0 y 1.");
  }
}
