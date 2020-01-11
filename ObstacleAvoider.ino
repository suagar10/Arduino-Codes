const int vcc=A3;
const int trig=A2;
const int echo=A1;
const int gnd=A0;

int pin1=3;
int pin2=5;
int pin3=6;
int pin4=9;

long duration;
int distance;

void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(vcc,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(gnd,OUTPUT);

  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);

  digitalWrite(vcc,HIGH);
  digitalWrite(gnd,LOW);
  Serial.begin(9600);
}
void loop()
{
  while(Serial.available()==0)
  {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;

  if(distance<15)
  {
    right();
    Serial.print("Too Close!!      distance:");Serial.println(distance);
  }
  else
  {
    forward();
  }
  char val=Serial.read();
  if(val==' ')
  {
    Serial.println("Car stopped, Press Reset to Continue");
    finish();
  }
  }
}
void forward()
 {
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
 }
void right()
 {
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
 }
 void finish()
 {
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
 }
