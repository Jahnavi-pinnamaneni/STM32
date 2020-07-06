#include <SPI.h>
#define SS PA4
#define ledpin PC13
#define buttonpin PA0

void setup() {
  // put your setup code here, to run once:
  pinMode (SS,OUTPUT);
  pinMode (ledpin,OUTPUT);
  pinMode (buttonpin,INPUT);
  Serial.begin(9600);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  digitalWrite(SS,HIGH);
  digitalWrite(ledpin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int masterSend,masterReceive;
  masterSend=digitalRead(buttonpin);
  Serial.println(masterSend);
  digitalWrite(SS,LOW);

  masterReceive=SPI.transfer(masterSend);   //recieved value
  delay(500);
  digitalWrite(SS,HIGH);

  if(masterReceive==HIGH)
  {
    digitalWrite(ledpin,LOW);
  }
  else
  {
    digitalWrite(ledpin,HIGH);
  }
  
}
