int brightness=0;
int fadeamount=2;
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(9,brightness);
  if(brightness>=250)
  {
    fadeamount=-2;
  }
  else if(brightness<=5)
  {
    fadeamount=2;
  }
  brightness+=fadeamount;
  delay(30);
}
