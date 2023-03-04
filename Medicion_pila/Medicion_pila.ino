
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  medirVoltajePila();
}
void medirVoltajePila(){
  int pila = analogRead(A0);
  int pilaM = map(pila,520,1023,0,1023);
  analogWrite(11,pilaM);
  Serial.print(pila);
  Serial.print("\t");
  Serial.print(pilaM);
  Serial.print("\n");
}
