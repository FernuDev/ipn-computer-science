
int LED = 10;
int Trigger = 2;
int Echo = 3;
int Speaker = 5;
int MotorA = 22;
int MotorB = 23;
int ENA = 40;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(Speaker, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(MotorA, OUTPUT);
  pinMode(MotorB, OUTPUT);
  digitalWrite(Trigger, LOW);
  pinMode(ENA, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long t;//Tiempo que demora en llegar la señal echo
  long d;//Distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH);
  d = t/59;

  digitalWrite(MotorA, HIGH);
  digitalWrite(MotorB, LOW);

  if(d<=20)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(Speaker, HIGH);
    
    for(int i=255;i>=0;i-=25){
      analogWrite(ENA, i);
    }

    analogWrite(ENA, 0);
    
  }
  else
  {
    digitalWrite(LED, LOW);
    digitalWrite(Speaker, LOW);

    for(int i=0;i<256;i+=25){
      analogWrite(ENA, i);
    }
  }

  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.print("cm");
  Serial.println();
  delay(100);

}