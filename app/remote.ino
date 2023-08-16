// Define the pins for the LEDs and buzzer
const int LED_R1 = 2;
const int LED_R2 = 3;
const int LED_G = 4;
const int LED_R3 = 5;
const int LED_R4 = 6;
const int BUZZER = 7;

// Define the variables to keep track of the LED position
int ledPosition = 4;

void setup() {
  // Set the LED and buzzer pins to output mode
  pinMode(LED_R1, OUTPUT);
  pinMode(LED_R2, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R3, OUTPUT);
  pinMode(LED_R4, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Start the serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Check if there is any data available on the serial port
  if (Serial.available() > 0) {
    // Read the incoming byte
    char incomingByte = Serial.read();

    // Check the value of the incoming byte and perform the corresponding action
    switch (incomingByte) {
      case '1':
		digitalWrite(BUZZER, LOW);
        // Move the LED position to the left
        ledPosition--;
        
        if (ledPosition < 2) {
          ledPosition = 2;
          // Turn on the buzzer to indicate that the LED has reached the left end
          digitalWrite(BUZZER, HIGH);
        }
        break;
      case '3':
		digitalWrite(BUZZER, LOW);
        // Move the LED position to the right
        ledPosition++;
        if (ledPosition > 6) {
          ledPosition = 6;
          // Turn on the buzzer to indicate that the LED has reached the right end
          digitalWrite(BUZZER, HIGH);
        }
        break;
      case '2':
		digitalWrite(BUZZER, LOW);
        //if(incomingByte=='2'){
        //  digitalWrite(LED_R1, LOW);
        //  digitalWrite(LED_R2, LOW);
        //  digitalWrite(LED_G, HIGH);
        //  digitalWrite(LED_R3, LOW);
        //  digitalWrite(LED_R4, LOW);
        //  digitalWrite(BUZZER, HIGH);
        //}else{
        //  break;
        //}
        // Return to power-on reset
        //asm volatile ("  jmp 0");
        //break;
      //default:
        ledPosition = 4;
        digitalWrite(BUZZER, LOW);
        break;
    }

    // Update the LED position based on the current value of ledPosition
    switch (ledPosition) {
      case 2:
        digitalWrite(LED_R1, HIGH);
        digitalWrite(LED_R2, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_R3, LOW);
        digitalWrite(LED_R4, LOW);
        break;
      case 3:
        digitalWrite(LED_R1, LOW);
        digitalWrite(LED_R2, HIGH);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_R3, LOW);
        digitalWrite(LED_R4, LOW);
        break;
      case 4:
        digitalWrite(LED_R1, LOW);
        digitalWrite(LED_R2, LOW);
        digitalWrite(LED_G, HIGH);
        digitalWrite(LED_R3, LOW);
        digitalWrite(LED_R4, LOW);
        break;
      case 5:
        digitalWrite(LED_R1, LOW);
        digitalWrite(LED_R2, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_R3, HIGH);
        digitalWrite(LED_R4, LOW);
        break;
      case 6:
        digitalWrite(LED_R1, LOW);
        digitalWrite(LED_R2, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_R3, LOW);
        digitalWrite(LED_R4, HIGH);
        break;
      default:
        break;
    }
  }
}