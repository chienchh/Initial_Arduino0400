String input;
int ledPin = 13;
boolean ledState = LOW;
void _Servo();
void DC_pos();
void DC_vel();
void _Stepper();

//------------------------
// SERVO PARAMTER START
//------------------------
#include <Servo.h>
const int servoPin = 9;
Servo myservo;  // create servo object to control a servo
int servoPotPin = A2;  // analog pin used to connect the potentiometer
int servoPotPinVal;
//------------------------
// SERVO PARAMTER END
//------------------------




//------------------------
// STEPPER MOTOR PARAMTER START
//------------------------

// stepper variables
const int stepperButtonPin = 2;
const int stepperStepPin = 8;
const int stepperDirPin = 7;
const int stepperSlotPin = 4;

//state
int stepperButtonState = 0;
int stepperSlotState = 0;
int stepperButtonLastState = 0;

// counter
int stepperButtonPushCounter = 0;
int stepperStepsCounter = 500;

//------------------------
// STEPPER MOTOR PARAMTER END
//------------------------







//------------------------
// DC MOTOR PARAMTER START
//------------------------

const int irPin = A1;
const int channelA = 3;
int Afeed = 0;
const int channelB = 4;
int Bfeed = 0;
int DCRotPosition = 0;
const int TOTALPOSITION = 360;
const int motorChannel = 9;
const int L1 = 6;
const int L2 = 5;
const int thermistor = A0;
int tRead = 0;
float encSpeed = 0;
float lastTime = 0;
float thisTime = 1;
float Kp = 0;
float Kd = 0;
float Ki = 0;
int positionIR = 0;

//------------------------
// DC MOTOR PARAMTER END
//------------------------







void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  establishContact();


  //------------------------
  // SERVO SETUP START
  //------------------------
  myservo.attach(servoPin);
  //------------------------
  // SERVO SETUP END
  //------------------------





  //------------------------
  // STEPPER MOTOR SETUP START
  //------------------------
  pinMode(stepperButtonPin, INPUT);
  pinMode(stepperSlotPin, INPUT);
  pinMode(stepperSlotPin, INPUT);

  pinMode(stepperStepPin, OUTPUT);
  pinMode(stepperDirPin, OUTPUT);
  //------------------------
  // STEPPER MOTOR SETUP END
  //------------------------







  //------------------------
  // DC MOTOR SETUP START
  //------------------------

  // set inputIR to an input pin
  pinMode(irPin, INPUT);

  // set encoders to input pins
  pinMode(channelA, INPUT);
  pinMode(channelB, INPUT);

  //set encoder pins to interrupt pins
  attachInterrupt(digitalPinToInterrupt(channelA), chanA, CHANGE);


  //Set enable pin to PWM pin
  pinMode(motorChannel, OUTPUT);
  //set thermistor pin to analog read
  pinMode(thermistor, INPUT);

  //L 1High, L2 Low -> motor moves clockwise
  //L1 Low, L2 High, motor move counterclockwise
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);

  //Initialize serial communication for testing
  Serial.begin(9600);

  //------------------------
  // DC MOTOR SETUP END
  //------------------------


}

//int inputString ="";
int val = 0;
char s;
char x;
void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)
  {
    int val = Serial.read();
    //  inputString = serial.readString();
    Serial.println(val);
    s = val;
    Serial.println("The char is");
    Serial.println(s);
    if (isDigit(val)) {
      input += (char)val;
//      Serial.print("input is : ");
//      Serial.println(input);
    }

  }
  x = input.charAt(0);
  Serial.println("This is inpug : ");
  Serial.println(input);
  Serial.println("This is x : ");
  Serial.println(x);
  //  int x = val;
  if (x == 'u')
    String userval = input.substring(3);
  char ch = input.charAt(1);
  switch (ch)
  {
    case 'a':
      {
        //        _Servo(userval, x);
        //        break;
        Serial.println("Servo Port");


      }
    case 'b':
      {

        Serial.println("DC Infrared Light Port");
        //      if (x =='s') {
        //        sensorType = 'i'; // i stands for infra red; t stands for thermitor
        //        changeDCPosition(userval,'s',sensorType); // s stands for sensor runMode
        //      }
        //      else {
        //        changeDCPosition(userval,'u',' '); // s stands for sensor runMode
        //      }
        //      break;


      }
    case 'c':
      {
        Serial.println("DC Thermistor Port");
        //      if (x == 's') {
        //        sensorType = 'i'; // i stands for infra red; t stands for thermitor
        //        changeDCSpeed(userval,'s',sensorType); // s stands for sensor runMode
        //      }
        //      else {
        //        changeDCSpeed(userval,'u',' '); // s stands for sensor runMode
        //      }
        //      break;
      }
    case 'd':
      {

        Serial.println("Stepper Port");
        //        if (x == 'u') {
        //          val = stepperUserInput(int targetAngle)
        //        } else if(x == 's'){
        //          val = stepperSlot();
        //        } else{
        //        stepperButton();
        //        }

      }
  }
  //val = input.toInt();
  //      String send = val + "," + val + "," + val + "," + val + "," + val;
  String send = input + "," + input + "," + input + "," + input + "," + input;
  // Serial.println(send);//for IR sensor

  //      Serial.println("b, val");//for Pot sensor
  //
  //      Serial.println("c, val");//for Thermistor sensor
  //
  //      Serial.println("d, val");//for Slot sensor
  //
  //      Serial.println("e, val");//for Pushbutton

  //      ledState = !ledState;
  //      digitalWrite(ledPin, ledState);

  delay(100);
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("A");   // send a capital A
    delay(300);
  }
}

//void _Servo(val, x)
//{
//  if(x == 's')
//}
//
//void DC_pos()
//{
//}
//
//void DC_vel()
//{
//}
//
//int _Stepper()
//{
//  take sensor data
//  move motor
//  return sensor data
//}



//------------------------
// SERVO CONTROL START
//------------------------


int servoPot() {
  servoPotPinVal = analogRead(servoPotPin);
  servoPotPinVal = map(servoPotPinVal, 0, 1023, 0, 180);
  myservo.write(servoPotPinVal);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  return servoPotPinVal;
}


int servoPotUserInput(int targetAngle) {
  servoPotPinVal = analogRead(servoPotPin);
  servoPotPinVal = map(servoPotPinVal, 0, 1023, 0, 180);
  int angle = 0;
  for ( angle = 0; angle < targetAngle; angle += 1)   // command to move from 0 degrees to 180 degrees
  {
    myservo.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);
  }
  delay(15);
  return servoPotPinVal;

}

//------------------------
// SERVO CONTROL END
//------------------------













//------------------------
// STEPPER CONTROL START
//------------------------

void stepperSlot() {
  stepperSlotState = digitalRead(stepperSlotPin);
  //  Serial.println("Slot State");
  //  Serial.println(stepperSlotState);

  if (stepperSlotState == 1) {
    Serial.println("Slot Open");

  } else if (stepperSlotState == 0) {
    Serial.println("Slot Closed");
    digitalWrite(stepperStepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepperStepPin, LOW);
    delayMicroseconds(500);
  }

}

void stepperUserInput(int targetAngle) {
  stepperSlotState = digitalRead(stepperSlotPin);
  //  Serial.println("Slot State");
  //  Serial.println(stepperSlotState);
  for (int i = 0; i < targetAngle; i++) {
    Serial.println("Slot Closed");
    digitalWrite(stepperStepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepperStepPin, LOW);
    delayMicroseconds(500);
  }

}




void stepperButton() {

  stepperButtonState = digitalRead(stepperButtonPin);


  //Serial.println("Push button0");
  //stepperButtonState: pushdown -> 0    pushup -> 1
  //Serial.println(stepperButtonState);
  //Serial.println("Slot State");
  //Serial.println(stepperSlotState);

  if (stepperButtonState != stepperButtonLastState)
  {
    Serial.println("Push button0");
    delay(150);
    stepperButtonPushCounter++;
  }

  if (stepperButtonPushCounter % 4 == 0 || stepperButtonPushCounter % 4 == 1) {

    Serial.println(" State ---------------------------0");
    // stepperDirPin : digital HIGH for counterclock, LOW for clockwise
    digitalWrite(stepperDirPin, HIGH);

  } else if (stepperButtonPushCounter % 4 == 2 || stepperButtonPushCounter % 4 == 3) {

    Serial.println(" State ---------------------------1");
    digitalWrite(stepperStepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepperStepPin, LOW);
    delayMicroseconds(500);
    //    stepperStepsCounter--;
    Serial.println("stepperStepsCounter:");
  }

  stepperButtonLastState = stepperButtonState;


}



//------------------------
// STEPPER CONTROL END
//------------------------







//------------------------
// DC MOTOR CONTROL START
//------------------------
int getPosError(float desPos) {
  int posError = desPos - DCRotPosition;
  posError = posError % TOTALPOSITION;
  if (posError < 0) {
    posError = posError + 360;
  }
  return posError;
}

//Interrupt function for channelA
void chanA() {
  thisTime = micros();
  Afeed = digitalRead(channelA);
  Bfeed = digitalRead(channelB);
  if (Afeed == Bfeed) {
    DCRotPosition++;
    encSpeed = 140 + 300000 / (thisTime - lastTime);
  } else {
    DCRotPosition--;
    encSpeed = -140 - 300000 / (thisTime - lastTime);
  }
  //encDerivative = 1000*(encSpeed - lastEncSpeed)/(thisTime-lastTime);
  DCRotPosition = DCRotPosition % TOTALPOSITION;
  lastTime = thisTime;
  //lastEncSpeed = encSpeed;
}

float mapToDCSpeed(float minRange, float maxRange, float current)
{
  current = max(minRange, current);
  current = min(maxRange, current);
  current = (current - minRange) / (maxRange - minRange) * 100;
  return 100 + current * (155.0 / 100.0);
}

float mapToDCPosition(float minRange, float maxRange, float current)
{
  current = max(minRange, current);
  current = min(maxRange, current);
  return (current - minRange) / (maxRange - minRange) * 360;
}

void changeDCSpeed(float desSpeed, char runMode, char sensorType) {
  float aimForSpeed = 140;
  float desSign = 1;
  float desValue = 0;
  switch (runMode)
  {
    case 'u':
      Serial.print("user has specified value: ");
      Serial.println(desSpeed);

      //set speed to user inputted value between -100 and 100
      desValue = mapToDCSpeed(0, 100, abs(desSpeed));
      desSign = desSpeed / abs(desSpeed);

      Serial.print("Desired Speed: ");
      Serial.println(desValue);

      if (desSign < 0) {
        digitalWrite(L1, HIGH);
        digitalWrite(L2, LOW);
      } else {
        digitalWrite(L1, LOW);
        digitalWrite(L2, HIGH);
      }
      analogWrite(motorChannel, desValue);
      break;
    default:
      switch (sensorType)
      {
        case 'i': // infra-red
          positionIR = analogRead(irPin);
          Serial.print("Proximity Sensor reads: ");
          Serial.println(positionIR);

          desSpeed = mapToDCSpeed(0, 500, positionIR);
          Serial.print("Desired Speed: ");
          Serial.println(desSpeed);

          //set speed always positive
          digitalWrite(L1, LOW);
          digitalWrite(L2, HIGH);
          analogWrite(motorChannel, desSpeed);

          break;
        case 't': // thermistor
          tRead = analogRead(thermistor);
          Serial.print("Thermistor read: ");
          Serial.println(tRead);

          desSpeed = mapToDCSpeed(525, 560, tRead);
          Serial.print("Desired Speed: ");
          Serial.println(desSpeed);

          //set speed always positive
          digitalWrite(L1, LOW);
          digitalWrite(L2, HIGH);
          analogWrite(motorChannel, desSpeed);
          break;
      }
      break;
  }
}

void changeDCPosition(float desPos, char runMode, char sensorType) {
  float speedToPos = 255;
  int posError = 0;
  switch (runMode)
  {
    case 'u':
      //speed should be 145 if posError = 0 (+/-2 degrees to be safe)
      posError = getPosError(desPos);
      speedToPos = 255; //for first iteration
      Ki = 0;
      Kp = 0.85;
      Kd = 0;

      Serial.print("Desired position is: ");
      Serial.println(desPos);

      digitalWrite(L1, HIGH);
      digitalWrite(L2, LOW);

      while (min(posError, 360 - posError) > 2) {
        speedToPos = min(255, 145 + Kp * posError);
        analogWrite(motorChannel, speedToPos);
        posError = getPosError(desPos);
        //Serial.print("Error is: ");
        //Serial.println(posError);
        //Serial.print("Speed is: ");
        //Serial.println(speedToPos);

      }
      analogWrite(motorChannel, 0);
      Serial.print("Position is: ");
      Serial.println(DCRotPosition);
      break;
    default:
      switch (sensorType)
      {
        case 'i': // infra-red
          positionIR = analogRead(irPin);
          Serial.print("Proximity Sensor reads: ");
          Serial.println(positionIR);

          desPos = mapToDCPosition(0, 500, positionIR);
          Serial.print("Desired Position: ");
          Serial.println(desPos);

          //speed should be 145 if posError = 0 (+/-2 degrees to be safe)
          posError = getPosError(desPos);
          speedToPos = 255; //for first iteration
          Ki = 0;
          Kp = 0.85;
          Kd = 0;

          Serial.print("Desired position is: ");
          Serial.println(desPos);

          digitalWrite(L1, HIGH);
          digitalWrite(L2, LOW);

          while (min(posError, 360 - posError) > 2) {
            speedToPos = min(255, 145 + Kp * posError);
            analogWrite(motorChannel, speedToPos);
            posError = getPosError(desPos);
            //Serial.print("Error is: ");
            //Serial.println(posError);
            //Serial.print("Speed is: ");
            //Serial.println(speedToPos);

          }
          analogWrite(motorChannel, 0);
          Serial.print("Position is: ");
          Serial.println(DCRotPosition);
          break;
        case 't': // thermistor
          tRead = analogRead(thermistor);
          Serial.print("Thermistor read: ");
          Serial.println(tRead);

          desPos = mapToDCPosition(525, 560, tRead);
          Serial.print("Desired Position: ");
          Serial.println(desPos);

          //speed should be 145 if posError = 0 (+/-2 degrees to be safe)
          posError = getPosError(desPos);
          speedToPos = 255; //for first iteration
          Ki = 0;
          Kp = 0.85;
          Kd = 0;

          Serial.print("Desired position is: ");
          Serial.println(desPos);

          digitalWrite(L1, HIGH);
          digitalWrite(L2, LOW);

          while (min(posError, 360 - posError) > 2) {
            speedToPos = min(255, 145 + Kp * posError);
            analogWrite(motorChannel, speedToPos);
            posError = getPosError(desPos);
            //Serial.print("Error is: ");
            //Serial.println(posError);
            //Serial.print("Speed is: ");
            //Serial.println(speedToPos);

          }
          analogWrite(motorChannel, 0);
          Serial.print("Position is: ");
          Serial.println(DCRotPosition);
          break;
      }
      break;
  }
}

//------------------------
// DC MOTOR CONTROL END
//------------------------




