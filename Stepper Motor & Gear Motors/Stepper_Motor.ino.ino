//Ice Rotating Motor
// Define motor control pins
#define ENA 10
#define IN1 3
#define IN2 4

//Stepper motor 
const int stepPin = 9;    // Pin connected to PUL+ (Pulse)
const int dirPin = 8;     // Pin connected to DIR+ (Direction)
const int enablePin = 7;  // Pin connected to ENA+ (Enable) - Optional
const int buttonPin = 2;  // Pin connected to push button

int buttonState = 0;
int lastButtonState = 0;
bool isEnabled = false;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // Set initial state
  digitalWrite(dirPin, HIGH); // Set direction
  digitalWrite(enablePin, LOW); // Enable motor (optional)

  // Set all the motor control pins to outputs
  pinMode(ENA, OUTPUT);
   pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
 
  // Initialize motor speed (optional, can be controlled using analogWrite)
  analogWrite(ENA, 255); // Set speed of Motor 1 (0-255)
 }

void loop() {
  // Read the state of the push button
  buttonState = digitalRead(buttonPin);

  // Check if the push button is pressed
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Debounce delay
    delay(50);
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      // Enable the motor if not already enabled
      if (!isEnabled) {
        digitalWrite(enablePin, LOW); // Enable motor
        isEnabled = true;
      }

      // Rotate the motor one full revolution
      for (int i = 0; i < 200; i++) { // Assuming 200 steps per revolution
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000); // Adjust the delay for your motor's speed
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000); // Adjust the delay for your motor's speed
      }
    }
  }
  // Update the last button state
  lastButtonState = buttonState;

  // Rotate Motor 1 clockwise
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  

void enableMotor(bool enable) {
  if (enable) {
    digitalWrite(enablePin, LOW); // Enable motor
  } else {
    digitalWrite(enablePin, HIGH); // Disable motor
  }
}
