const unsigned int pumpPin = 12;
const unsigned int powerPin = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode (pumpPin, OUTPUT);
  pinMode (powerPin, OUTPUT);

  digitalWrite(powerPin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pumpPin, LOW);
  delay(2000);
  digitalWrite(pumpPin, HIGH);
  delay(2000);
  
}
