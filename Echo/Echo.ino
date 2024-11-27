void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    char dato = Serial.read();

    if (dato >= 'a' && dato <= 'z') {
      dato = dato - 'a' + 'A';
    } else if (dato >= 'A' && dato <= 'Z') {
      dato = dato - 'A' + 'a';
    }

    Serial.print(dato);
  }
}

