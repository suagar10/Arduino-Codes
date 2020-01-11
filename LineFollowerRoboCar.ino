#define ls 2
#define rs 4
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
  pinMode(ls,INPUT);
  pinMode(rs,INPUT);
}
void loop()
{
  if(!digitalRead(ls)&&!digitalRead(rs))
  {
    forward();
  }
  else if(digitalRead(ls)&&!digitalRead(rs))
  {
    left();
  }
  else if(!digitalRead(ls)&&(digitalRead(rs)))
  {
    right();
  }
  else if((digitalRead(ls))&&(digitalRead(rs)))
  {
    finish();
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
