void setup() {
  Serial.begin(9600);
}

void loop() {
  float V0 = analogRead(A0) * (5.0 / 1023.0); //to convert analog reading into volts
  float V1 =  analogRead(A1) * (5.0 / 1023.0);

  float voltage = V0 - V1;        // voltage drop across load

  Serial.print("VOltage (V): ");
  Serial.println(voltage);

  delay(200);
}
