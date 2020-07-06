#include <SPI.h>

const int ledpin= 4;
const int buttonpin=6;

volatile boolean received;
volatile int slaveReceive, slaveSend;

void setup() {
  // put your setup code here, to run once:
  pinMode (ledpin, OUTPUT);
  pinMode (buttonpin, INPUT);
  pinMode (MISO, OUTPUT);

  digitalWrite(ledpin,LOW);
  //to configure arduino as slave
  SPCR|=_BV(SPE);
  received=false;
  Serial.begin(9600);
  //enabling interrupt when data is received
  SPI.attachInterrupt();
}

ISR(SPI_STC_vect)
{
  slaveReceive = SPDR; //data from master is stored in slaveReceive
  received = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  slaveSend = digitalRead(buttonpin);
  Serial.println(slaveReceive);
  SPDR=slaveSend; //this value is transferred to master when master initiates the next data exchange

  if(received == true)
  {
    if(slaveReceive == HIGH||slaveReceive==3)
    {
      digitalWrite(ledpin,HIGH);
    }
    else
    {
      digitalWrite(ledpin,LOW);
    }
  }
}
