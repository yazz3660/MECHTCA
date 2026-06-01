//keypad

#include <Keypad.h>

//constants for row and column
const byte ROWS = 4;
const byte COLS = 4;

//Array to represent keys on keypad
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//Connections to arduino
byte rowPins[ROWS] = {13,12,11,10};
byte colPins[COLS] = {9,8,7,6};

//create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS);

String number = "";

int encoderA = 2;   // interrupt pin
int potPin = A0;
volatile int pulseCount = 0;

int motorPWM = 3;

int targetRPM = 200;       // target RPM
float Kp;           // proportional gain
float potVal;

int lastTime = 0;
int measuredRPM = 0;

void countPulse() {
  pulseCount++;
}

void setup() {
  pinMode(encoderA, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderA), countPulse, RISING);

  pinMode(motorPWM, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //keypad
  //Get key value if pressed
  char customKey = customKeypad.getKey();
  
  if(customKey){
    //adds number to number string
    number = number + customKey;   
  }
  if(customKey == 'D'){
    targetRPM = number.toInt();
    number = "";
    Serial.print("TARGET: ");
    Serial.println(targetRPM);
    Serial.println("");
  }
  
  int now = millis();

  // Calculate RPM every 100 ms
  if (now - lastTime >= 100) {
    noInterrupts();
    int pulses = pulseCount;
    pulseCount = 0;
    interrupts();

    // Convert pulses to RPM
    measuredRPM = pulses * 10 * 60 / 20;  
    // (20 pulses per revolution)

    //reading potentiometer for Kp
   	potVal = analogRead(potPin);
	Kp = potVal * (1.0 / 1023.0);   // Kp range: 0.0 - 1.0

    Serial.println(Kp);
    
    // Closed-loop control
    int error = targetRPM - measuredRPM;
    int output = Kp * error;

    output = constrain(output, 0, 255);
    analogWrite(motorPWM, output);

    //Serial.print("RPM: ");
    //Serial.print(measuredRPM);
    //Serial.print("  PWM: ");
    //Serial.println(output);

    lastTime = now;
  }
}
