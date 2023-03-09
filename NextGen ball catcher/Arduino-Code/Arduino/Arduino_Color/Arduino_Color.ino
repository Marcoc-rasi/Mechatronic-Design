#define S0 4    // S0 a pin 4
#define S1 5    // S1 a pin 5
#define S2 6    // S2 a pin 6
#define S3 7    // S3 a pin 7
#define salidaTCS 8 // salidaTCS a pin 8
#define Boton 3

int rva[3] = {0,0,0};
int rvaExterior[3] = {0,0,0};
int rvaInterior[3] = {0,0,0};
int rvaLineas[3] = {0,0,0};
int rvaRed[3] = {0,0,0};


void setup() {
  pinMode(Boton, INPUT); // pin 3 como entrada
  
  pinMode(S0, OUTPUT);    // pin 4 como salida
  pinMode(S1, OUTPUT);    // pin 5 como salida
  pinMode(S2, OUTPUT);    // pin 6 como salida
  pinMode(S3, OUTPUT);    // pin 7 como salida
  pinMode(salidaTCS, INPUT);  // pin 8 como salida
  
  digitalWrite(S0,HIGH);  // establece frecuencia de salida
  digitalWrite(S1,LOW);   // del modulo al 20 por ciento
  
  Serial.begin(9600);   // inicializa monitor serie a 9600 bps
}

void loop() {

  reconocerCancha();
  Serial.print("Con las muestras ya podemos distinguir la cancha \n");
  Serial.print("Coloca el sensor donde prefieras y te diremos su posicion actual");
  while(leerEstadoBoton()==1){
  distinguirPosicion();
  }
  
}
void LecturaSensorColor(int RVA[])
{
  digitalWrite(S2,LOW);     // establece fotodiodos
  digitalWrite(S3,LOW);     // con filtro rojo
  RVA[0] = pulseIn(salidaTCS, LOW); // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  digitalWrite(S2,HIGH);    // establece fotodiodos
  digitalWrite(S3,HIGH);    // con filtro verde
  RVA[1] = pulseIn(salidaTCS, LOW);  // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  digitalWrite(S2,LOW);     // establece fotodiodos
  digitalWrite(S3,HIGH);    // con filtro azul
  RVA[2] = pulseIn(salidaTCS, LOW); // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg       
}
void imprimirValoresSensorColor(int RVA[])
{  
  //Imprime rojo
  Serial.print("R:");     // muestra texto
  Serial.print(RVA[0]);     // muestra valor de variable rojo
  Serial.print("\t"); // salto de linea
  //Imprime verde
  Serial.print("V:");     // muestra texto
  Serial.print(RVA[1]);      // muestra valor de variable verde
  Serial.print("\t"); // espacio de tabulacion
  Serial.print("\t");     // espacio de tabulacion
  //imprime azul
  Serial.print("A:");     // muestra texto
  Serial.println(RVA[2]);     // muestra valor de variable azul         
}
int leerEstadoBoton()
{
  int Botton = digitalRead(Boton);
  return Botton;
}
void reconocerCancha()
{
  Serial.print("Hola, para reconocer la cancha nececitamos muestras de 4 colores");
  Serial.print("\n"); 
  Serial.print("El primer color es el del exterior de la cancha");
  Serial.print("\n"); // Salto de linea
  Serial.print("Por favor coloca el sensor en el exterior de la cancha y presiona el boton para empezar");
  Serial.print("\n");
  tomarMuestras(rvaExterior);
  Serial.print("Hemos tomado las muestras del exterior de la cancha");
  Serial.print("\n");
  Serial.print("Por favor coloca el sensor en el interior de la cancha y presiona el boton para empezar");
  Serial.print("\n");
  tomarMuestras(rvaInterior);
  Serial.print("Hemos tomado las muestras del interior de la cancha");
  Serial.print("\n");
  Serial.print("Por favor coloca el sensor sobre una linea que conforma la cancha y presiona el boton para empezar");
  Serial.print("\n");
  tomarMuestras(rvaLineas);
  Serial.print("Hemos tomado las muestras de las lineas de la cancha");
  Serial.print("\n");
  Serial.print("Por favor coloca el sensor en la marca debajo de la red de la cancha y presiona el boton para empezar");
  Serial.print("\n");
  tomarMuestras(rvaRed);
  Serial.print("Hemos tomado las muestras de la red de la cancha");
  Serial.print("\n");
}
void tomarMuestras(int RVA[])
{
  int PromedioR = 0;
  int PromedioV = 0;
  int PromedioA = 0;
  while(leerEstadoBoton()== 1); //Esperamos que presione el boton sin hacer nada
  for(int i=0;i<10;i++)
  {
    LecturaSensorColor(rva);
    PromedioR += rva[0];
    PromedioV += rva[1];
    PromedioA += rva[2];
    imprimirValoresSensorColor(rva);
  }
  RVA[0] = PromedioR/10;
  RVA[1] = PromedioV/10;
  RVA[2] = PromedioA/10;
  Serial.print(RVA[0]);
  Serial.print("\t");
  Serial.print(RVA[1]);
  Serial.print("\t");
  Serial.print(RVA[2]);
  Serial.print("\n");
}
void distinguirPosicion()
{
   LecturaSensorColor(rva);
   if(compararRVA(rva,rvaExterior)==1)
   {
    Serial.print("Estas en Exterior de la cancha \n");
   }
   else
   {
    if(compararRVA(rva,rvaInterior)==1)
    {
     Serial.print("Estas en interior de la cancha \n");
    }
    else
    {
      if(compararRVA(rva,rvaLineas)==1)
      {
       Serial.print("Estas sobre una linea de la cancha \n");
      }
      else
      {
        if(compararRVA(rva,rvaRed)==1)
          {
           Serial.print("Estas en la red de la cancha \n");
          }
        else
        {
          Serial.print("Color no reconocido muevete un poco \n");
        }
      }
    }
   }
}
int compararRVA(int RVA1[],int RVA2[])
{
  if(RVA1[0]<=(RVA2[0]+15) && RVA1[0]>=(RVA2[0]-15))
   {
    if(RVA1[1]<=(RVA2[1]+15) && RVA1[1]>=(RVA2[1]-15))
    {
      if(RVA1[2]<=(RVA2[2]+15) && RVA1[2]>=(RVA2[2]-15))
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 0;
    }
   }
   else
   {
    return 0;
   }
}
