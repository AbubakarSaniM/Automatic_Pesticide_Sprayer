// Motor connections
int motorPin1 = 2;  // Connected to IN1 on the motor driver
int motorPin2 = 4;  // Connected to IN2 on the motor driver
int motorPin3 = 6;
int motorPin4 = 7;

void setup() {
  // Set the motor control pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
   pinMode(motorPin4, OUTPUT);
  pinMode(motorPin3, OUTPUT);
}

void loop() {
 
  // Run the motor in the opposite direction
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  

}
