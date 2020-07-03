HardwareTimer timer(1);
void setup() {
  // put your setup code here, to run once:
  pinMode(PA8,PWM);
  timer.setPrescaleFactor(7200);
  timer.setOverflow(2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  pwmWrite(PA8,1);
  Serial.println(PA8);
}
