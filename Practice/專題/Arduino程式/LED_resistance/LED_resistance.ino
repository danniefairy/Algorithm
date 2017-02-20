void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sv=analogRead(3);
  Serial.println(sv,DEC);
  sv=sv/4;
  analogWrite(9,sv);
  delay(150);
}
