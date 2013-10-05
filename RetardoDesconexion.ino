//Temporizador Retardo a la Desconexion con Reset

//tecla guardara el caracter pulsado en el teclado
char tecla;
//t_temporizacion es el tiempo base de la temporizacion
int t_temporizacion=1000;
//inicio_temporizacion valdra 1 cuando hayamos activado el temporizador
boolean inicio_temporizacion=false, impresion=false;
//En long t_referencia iremos guardando el valor que devuelve Millis() por eso lo hacemos long
long t_referencia;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  

  if (Serial.available()>0)
  {
    tecla=Serial.read();
    //el caracter 'a' arranca la temporizacion Y enciende el "bit" del temporizador
  if(tecla=='a')
   { 
    t_referencia=millis();
    inicio_temporizacion=true;
    digitalWrite(13, HIGH);
     if (impresion==false)
     {
       Serial.println("Pin 13 ON");
       impresion=true;
     }
   }

  }
  
 //Una vez el tiempo ha pasado, se cumple esta condicion y apaga el bit del temporizador
 if (t_referencia+t_temporizacion<millis()&&inicio_temporizacion==true)
 {
  
   digitalWrite(13, LOW);
   Serial.println("Pin 13 OFF");
   inicio_temporizacion=false;
   impresion=false;
 }
 
 
}
