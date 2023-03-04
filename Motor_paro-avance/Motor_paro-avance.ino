#define Pelota 2 // detectar pelota a pin 0
#define Aspa 3 //detectar aspa a pin 1
#define Motor 4 //encender motor a pin 2
void setup() {
  // put your setup code here, to run once:
  pinMode(Pelota, INPUT);
  pinMode(Aspa, INPUT);
  pinMode(Motor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  introducirPelota();
}
void encenderMotor() {
  digitalWrite(Motor, HIGH);    // establece fotodiodos
}
void apagarMotor() {
  digitalWrite(Motor, LOW);     // establece fotodiodos
}
bool detectarPelota(){
  if(digitalRead(Pelota)==HIGH){
    Serial.print("No hay pelota \n");
    return false;
  }
  else{
    Serial.print("Pelota detectada \n");
    return true;
  }
}
bool detectarAspa(){
  if(digitalRead(Aspa)==HIGH){
    Serial.print("No hay aspa \n");
    return false;
  }
  else{
    Serial.print("Aspa detectada \n");
    return true;
  }
}
void introducirPelota(){
  int suma= 0;
  if(detectarPelota()== true){
    encenderMotor();
    while(suma<2){
      if(detectarAspa()== true){
        suma++;
      } 
    }
      apagarMotor();
      delay(3000);
  }
}
