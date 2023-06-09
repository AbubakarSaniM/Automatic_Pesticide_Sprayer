#include <L298N.h>


// Ultrasonic Pins
const int trigPin = 8;
const int echoPin = 9;

// Motor connections Pins
unsigned int IN1 = 2;  // Connected to IN1 on the motor driver
unsigned int IN2 = 4;  // Connected to IN2 on the motor driver
unsigned int ENA = 3;
unsigned int IN3 = 6;
unsigned int IN4 = 7;
unsigned int ENB = 5;

L298N motorA(ENA, IN1, IN2);
L298N motorB(ENB, IN3, IN4);

//Water Sprayer Pump Relay Pin
const unsigned int pumpPin = 10;
unsigned int sprayTimer = 0;
unsigned int sprayCount = 0;

// Variables for duration and distance
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  pinMode(pumpPin, OUTPUT); // PumpRelay Pin

  // Set the trigPin as an output and echoPin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set the motor speed
  motorA.setSpeed(120);
  motorB.setSpeed(120);


}

void loop() {
  // Run the motor in the Forward direction
  motorForward();
  distanceHC();
  sprayTimer = millis();

  //  if (distance <= 30){
  //    stopMotorTurn();
  //  }

  if (sprayTimer - sprayCount >= 5000) {
    digitalWrite(pumpPin, HIGH);
    sprayTimer = millis();
    sprayCount = millis();
    while (sprayTimer - sprayCount < 6000) {
      distanceHC();
      //		if (distance <= 30){
      //  			stopMotorTurn(); //5 seconds delay if tirggerd.
      //  			}
      sprayTimer = millis();
    }
    digitalWrite(pumpPin, LOW);
    sprayCount = millis();
    sprayTimer = millis();
  }


}
void motorForward() {
  motorA.forward();
  motorB.forward();
}

void distanceHC() {
  // Send a short pulse to the Trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse from Echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration / 58;

//  Print the distance to the Serial Monitor
  Serial.print(" Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Delay before the next measurement
  delay(500);
}

void stopMotorTurn() {
  motorA.stop();
  motorB.stop();
  delay(3000);

  motorA.forward();
  motorB.backward();

  delay(2000);

  digitalWrite(pumpPin, LOW);

  distanceHC();

  if (distance <= 30) {
    stopMotorTurn();
  } //else continue;

}
