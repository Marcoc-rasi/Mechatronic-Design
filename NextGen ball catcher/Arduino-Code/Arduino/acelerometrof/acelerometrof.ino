#include <math.h>
#include <Time.h>
int push=7;
int var=0;
int g=4;
int var2=0;
int xVal = 0;
int yVal = 0;
int zVal = 0;
int Tf=0;
int Tf1=0;
int vi=0;
int vf=0;
int posA=0;


void setup() {
  analogReference(EXTERNAL);
  Serial.begin(9600);
  pinMode(push,INPUT);
  pinMode(g,INPUT);
} 
void loop() {
xVal = analogRead(0);
yVal = analogRead(1);
zVal = analogRead(2);
xVal = map(xVal, 0, 1023, -14.715,14.715);
yVal = map(yVal, 0, 1023,-14.715, 14.71);
zVal = map(zVal, 0, 1023, -14.715, 14.71);
var2=digitalRead(g);
var= digitalRead(push);
 if(var==HIGH){
  time_t T= now();
  Serial.print(T);
  Serial.write("eje x\n");
  Serial.print(xVal);
  Serial.write("\neje y\n");
  Serial.print(yVal);
  Serial.write(" \neje z\n");
  Serial.print(zVal);
  Serial.write("\n");
  if(var2==HIGH){
    Tf=T;
    Serial.print("\n\tLa aceleracion del inicio hasta el punto mas alto es");
    Serial.print("-9.81");
    Serial.print("\n\el tiempo que tardo en llegar al punto mas alto fue");
    Serial.print(Tf);
    Serial.print("\n");
    vi=9.81*Tf;
    Serial.print("la velocidad inicial fue ");
    Serial.print(vi);
    Serial.print("\n\tla ecuacion de la velocidad es -9.81t + ");
    Serial.print(vi);
    Serial.print("\n");
    Serial.print("la ecuacion de la posicion es (-9.81/2)t^2 + "),
    Serial.print(vi);
    Serial.print("t\n");
    posA=(-9.81*Tf*Tf) + (vi*Tf);
    Serial.print("\n\tla altura maxima alcanzada en el movimiento fue ");
    Serial.print(posA);
    Serial.print("\n");
    Tf1=(-2*vi)/(2*-9.81);
    Serial.print("el tiempo que tardo en llegar al suelo fue ");
    Serial.print(Tf);
    vf=-9.81*(Tf1) + vi;
    Serial.print("la velocidad final fue ");
    Serial.print(vf);
    delay(60000);
  } 
  }
 else{
  Serial.print("\napagado\n");
 }

}

