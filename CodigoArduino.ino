#define TRIG_PIN 13    // Pino Trigger do sensor ultrassônico
#define ECHO_PIN 12    // Pino Echo do sensor ultrassônico
#define LED_PIN 8      // Pino do LED indicador

// Definindo os pinos dos motores
#define IN1_PIN 2
#define IN2_PIN 3
#define IN3_PIN 6
#define IN4_PIN 7

// Definindo constantes para a velocidade do som (em cm)
#define VELOCIDADE_SOM 0.034

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);
  
  Serial.begin(9600);
  
  digitalWrite(IN1_PIN, 0);
  digitalWrite(IN2_PIN, 1);
  digitalWrite(IN3_PIN, 1);
  digitalWrite(IN4_PIN, 0);
}

void loop()
{ 
  // Limpa o pino trigger antes de enviar o pulso
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2); 
  
  // Envia um pulso de 10 microsegundos para o pino trigger
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);  // 10 microsegundos de pulso
  digitalWrite(TRIG_PIN, LOW);

  // Lê a duração do pulso no pino echo
  long duracao = pulseIn(ECHO_PIN, HIGH);
  
  // Calculo da distância
  float dist;
  dist = duracao * VELOCIDADE_SOM / 2;

  // Verificação da distância e controle dos motores
  if (dist >= 100) 
  {
    digitalWrite(LED_PIN, 0);
    
    digitalWrite(IN1_PIN, 0);
    digitalWrite(IN2_PIN, 1);
    digitalWrite(IN3_PIN, 1);
    digitalWrite(IN4_PIN, 0);
  } 
  else if(dist >= 10)
  { 
    digitalWrite(LED_PIN, 1);
    
    digitalWrite(IN1_PIN, 1);
    digitalWrite(IN2_PIN, 0);
  }
  else
  {
    digitalWrite(IN1_PIN, 0);
    digitalWrite(IN2_PIN, 0);
    digitalWrite(IN3_PIN, 0);
    digitalWrite(IN4_PIN, 0);
  }
  
  Serial.println(dist);
  delay(100);
}
