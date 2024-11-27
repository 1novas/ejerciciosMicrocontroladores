int contador = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(contador);
  contador++;        
  delay(1000);
}
