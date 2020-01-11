int led=13;
int inp=12;
char inp1=0;
void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
void loop()
{ 
  int s=1;
  if(Serial.available()>0)
  {
    String inp1=Serial.readString();
    Serial.print("Decimal Number: ");
    Serial.println(inp1);
    inp=inp1.toInt();
    int a;
    while(inp!=0)
    {
      a=inp%2;
      s=s*10+a;
      inp=inp/2;
    }
    Serial.print("Converted Binary Number: ");
    int b;
    while(s>1)
    {
      b=s%10;
      s=s/10;
      if(b==1)
      {
        Serial.print(b);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(250);
      }
      if(b==0)
      {
        Serial.print(b);
        digitalWrite(led,HIGH);
        delay(1000);
        digitalWrite(led,LOW);
        delay(250);
      }
    }
    Serial.println();
 }
}
