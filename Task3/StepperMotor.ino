//https://www.instructables.com/Large-Stepper-Motor-Control-A4988/

const int EN = 2;         //ENABLE PIN
const int Step = 3;       // STEP PIN
const int dir = 4;        // DIRECTION PIN

void setup() 
{
    Serial.begin(9600);
    pinMode(EN,OUTPUT);     // ENABLE AS OUTPUT
    pinMode(dir,OUTPUT);    // DIRECTION AS OUTPUT
    pinMode(Step,OUTPUT);   // STEP AS OUTPUT
    digitalWrite(EN,LOW);   // SET ENABLE TO LOW
}

void loop() 
{
  digitalWrite(dir,LOW);        // SET DIRECTION LOW FOR FORWARD ROTATION
  for(int x = 0; x < 1000; x++) // LOOP 1000 TIMES FOR 1000 RISING EDGE ON STEP PIN
  {
    digitalWrite(Step,HIGH);    // STEP HIGH
    Serial.println("high");
    delay(1);                   // WAIT
    digitalWrite(Step,LOW);     // STEP LOW
    Serial.println("low");
    delay(1);                   // WAIT
     }
  delay(10);                    // DELAY BEFORE SWITCH DIRECTION
  digitalWrite(dir,HIGH);       // SET DIRECTION HIGH FOR BACKWARD ROTATION
  for(int x = 0; x < 1000; x++) // LOOP 1000 TIMES FOR 1000 RISING EDGE ON STEP PIN
  {
    digitalWrite(Step,HIGH);    // STEP HIGH
    Serial.println("high");
    delay(1);                   // WAIT
    digitalWrite(Step,LOW);     // STEP LOW
    Serial.println("low");
    delay(1);                   // WAIT
  }
  delay(10);                    // DELAY BEFOR SWITCH DIRECTION
}
