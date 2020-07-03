
void setup() {
  // put your setup code here, to run once:
  //pinMode(PA3,INPUT);
  //pinMode(PA2,OUTPUT);
  pinMode(PC13,OUTPUT);
  Serial2.begin(9600);
  //Serial.begin(9600);
  //digitalWrite(PC13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  char i;
  //Serial2.println("inside loop");
  
  if(Serial2.available()>0)
  {
    Serial2.write("inside available");
    i=Serial2.read();
    Serial2.write(i);
    if(i=='1')
    {
      digitalWrite(PC13,LOW);
      Serial2.println("LED HIGH");
    }
    if(i=='0')
    {
      digitalWrite(PC13,HIGH);
      Serial2.println("LED LOW");
    }
  }
}
