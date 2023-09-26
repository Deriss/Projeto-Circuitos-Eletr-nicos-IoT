// C++ code
//

# define RED_LED 12
# define TRANSISTOR_MOTOR 9
# define BUZINA 7
int leitura_temp;
int frequencia =440;
float temperatura = 0.0;
void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(TRANSISTOR_MOTOR, OUTPUT); 
  Serial.begin(9600);
  
}

void loop()
{
  leitura_temp = analogRead(0);
  //Calcular temperatura a partir da medição
  temperatura = (( leitura_temp * (5 / 1024.0) ) - 0.5)*100; 
	
  //ativar motor do ventilador se a temperatura for maior a 30º
  if (temperatura>30.){
    digitalWrite(TRANSISTOR_MOTOR,HIGH);
  }
  else{
  //desligar motor do ventilador se a temperatura for menor a 30º
  	digitalWrite(TRANSISTOR_MOTOR,LOW);
  }
  // 
  if (temperatura>50.){
    //ligar led alarme
    digitalWrite(RED_LED, HIGH);
    // tocar buzina
    tone(BUZINA,frequencia);
    // esperar 1s
    delay(1000); 
    //desligar led alarme (piscar)
    digitalWrite(RED_LED, LOW);
    // tocar buzina em outra frequência
    tone(BUZINA,frequencia/2*1.5);
    delay(1000); 
  }
  
  
}