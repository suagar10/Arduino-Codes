int pin1=3;
int pin2=5;
int pin3=6;
int pin4=9;
void setup()
{
  Serial.begin(9600);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
}
void loop()
{
  while(Serial.available()>0)
  {
    char input=Serial.read();
    if(input=='w'||input=='W')
    {
      forward();
      Serial.println("Forward");
    }
    else if(input=='a'||input=='A')
    {
      left();
      Serial.println("Leftward");
    }
    else if(input=='s'||input=='S')
    {
      backward();
      Serial.println("Backward");
    }
    else if(input=='d'||input=='D')
    {
      right();
      Serial.println("Rightward");
    }
    else if(input==' ')
    {
      finish();
      Serial.println("Stopped");
    }
  }
 }
 void backward()
 {
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
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
 void left()
 {
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
 }
 void finish()
 {
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
 }
