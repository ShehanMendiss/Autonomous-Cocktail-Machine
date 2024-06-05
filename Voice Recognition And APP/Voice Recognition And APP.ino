// In and Out
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int Led1 = 7;
int Led2 = 8;
int Led3 = 9;
int Led4 = 10;

// Variables
byte com = 0;
int ld1 = 0;
int ld2 = 0;
int ld3 = 0;
int ld4 = 0;
int ld5 = 0;

void setup() {
  // Initialize Serial0 (default) for communication with the computer
  Serial.begin(9600);
  // Initialize Serial1 for communication with another serial device
  Serial1.begin(9600);
  // Initialize Serial2 for communication with another serial device
  Serial2.begin(9600);
  // Initialize Serial3 for communication with another serial device
  Serial3.begin(9600);

  // Initialize LED pins as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);


  // Set all LEDs to LOW initially
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);

  // Initial Serial commands
  Serial1.write(0xAA);
  Serial1.write(0x00); // Waiting
  delay(100);
  Serial1.write(0xAA);
  Serial1.write(0x37); // Compact mode
  delay(100);
  Serial1.write(0xAA);
  Serial1.write(0x00); // Waiting
  delay(100);
  Serial1.write(0xAA);
  Serial1.write(0x21); // Import group 1

  // Initial message for testing the app
  Serial.println("Testing the APP");
}

void loop() {
  // Check if data is available on Serial0
  if (Serial.available()) {
    char input = Serial.read();
    Serial.println(input);

    // Process commands for LEDs based on input
    if (input == 'A') {
      digitalWrite(Led1, HIGH);
    } else if (input == 'E') {
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      digitalWrite(Led4, LOW);
    }

    if (input == 'B') {
      digitalWrite(Led2, HIGH);
    } else if (input == 'E') {
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      digitalWrite(Led4, LOW);
    }

    if (input == 'C') {
      digitalWrite(Led3, HIGH);
    } else if (input == 'E') {
       digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      digitalWrite(Led4, LOW);
    }

    if (input == 'D') {
      digitalWrite(Led4, HIGH);
    } else if (input == 'E') {
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      digitalWrite(Led4, LOW);
    }
  }

  // Check if data is available on Serial1
  if (Serial1.available()) {
    com = Serial1.read(); // We receive the voice command and save it in the com byte
    
    if (com == 0x11) { // LED1
      ld1 = !ld1;
      digitalWrite(led1, ld1);
    } else if (com == 0x12) { // LED2
      ld2 = !ld2;
      digitalWrite(led2, ld2);
    } else if (com == 0x13) { // LED3
      ld3 = !ld3;
      digitalWrite(led3, ld3);
    } else if (com == 0x14) { // LED4
      ld4 = !ld4;
      digitalWrite(led4, ld4);
    } else if (com == 0x15) { // LED5
      ld5 = !ld5;
      digitalWrite(led5, ld5);
    }
  }

  // Similarly, check and process data for Serial2 and Serial3 as needed
  if (Serial2.available()) {
    // Add your Serial2 processing code here
  }

  if (Serial3.available()) {
    // Add your Serial3 processing code here
  }
}
