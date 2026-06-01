int redPin= 2, greenPin=3, bluePin=4;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  RGB_output(255, 0, 0); //red 
  delay(1000);
  RGB_output(255, 127, 0); //orange
  delay(1000);
  RGB_output(255, 255, 0); //yellow
  delay(1000);
  RGB_output(0, 255, 0); //green
  delay(1000);
  RGB_output(0, 206, 209); //turquoise
  delay(1000);
  RGB_output(0, 0 , 255); //blue
  delay(1000);
  RGB_output(75, 0, 130); //indigo
  delay(1000);
  RGB_output(148, 0, 211); //violet
  delay(1000);
  RGB_output(255, 20, 147); //pink
  delay(1000);
  
}

void RGB_output(int redLight, int greenLight, int blueLight){
    analogWrite(redPin, redLight);
    analogWrite(greenPin, greenLight);
    analogWrite(bluePin, blueLight);
}