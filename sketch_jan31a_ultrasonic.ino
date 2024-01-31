const int trigPin = 2;
const int echoPin = 3;
const int relayPin = 13;
const int relayPin2 = 12;
const int relayPin3 = 11;
const int relayPin4 = 10;
const int relayPin5 = 9;
const int relayPin6 = 8;
float cm;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
  pinMode(relayPin5, OUTPUT);
  pinMode(relayPin6, OUTPUT);
}

void loop() {
  // Send a 10ms pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  cm = pulseIn(echoPin, HIGH) / 58.0; // Convert pulse duration to centimeters
  cm = (int(cm * 100.0)) / 100.0; // Round to two decimal places
  Serial.println(cm);

  if (cm < 5.00) {
    digitalWrite(relayPin, HIGH); // Turn on Relay 1 when distance is less than 5cm
    digitalWrite(relayPin2, HIGH); // Turn off Relay 2 when distance is less than 5cm，relay 2 and 3 have opposite switches
    digitalWrite(relayPin3, HIGH);
    digitalWrite(relayPin4, LOW);
    digitalWrite(relayPin5, LOW);
    digitalWrite(relayPin6, LOW);
  } else if (cm >= 5.00 && cm < 10.00) {
    digitalWrite(relayPin, LOW); // Turn off Relay 1 when distance is between 5cm and 15cm
    digitalWrite(relayPin2, LOW); // Turn on Relay 2 when distance is between 5cm and 15cm
    digitalWrite(relayPin3, HIGH);
    digitalWrite(relayPin4, LOW);
    digitalWrite(relayPin5, LOW);
    digitalWrite(relayPin6, LOW);
  } else if (cm >= 10.00 && cm < 15.00) {
    digitalWrite(relayPin, LOW); // Turn off Relay 1 when distance is 15cm or more
    digitalWrite(relayPin2, HIGH); // Turn off Relay 2 when distance is 15cm or more
    digitalWrite(relayPin3, LOW);
    digitalWrite(relayPin4, LOW);
    digitalWrite(relayPin5, LOW);
    digitalWrite(relayPin6, LOW);
  }
  else if (cm >= 15.00 && cm < 20.00) {
    digitalWrite(relayPin, LOW); // Turn off Relay 1 when distance is 15cm or more
    digitalWrite(relayPin2, HIGH); // Turn off Relay 2 when distance is 15cm or more
    digitalWrite(relayPin3, HIGH);
    digitalWrite(relayPin4, HIGH);
    digitalWrite(relayPin5, LOW);
    digitalWrite(relayPin6, LOW);
  }
  else if (cm >= 20.00 && cm < 25.00) {
    digitalWrite(relayPin, LOW); 
    digitalWrite(relayPin2, HIGH); 
    digitalWrite(relayPin3, HIGH);
    digitalWrite(relayPin4, LOW);
    digitalWrite(relayPin5, HIGH);
    digitalWrite(relayPin6, LOW);
  }
  else if (cm >= 25.00 && cm < 30.00) {
    digitalWrite(relayPin, LOW); 
    digitalWrite(relayPin2, HIGH); 
    digitalWrite(relayPin3, HIGH);
    digitalWrite(relayPin4, LOW);
    digitalWrite(relayPin5, LOW);
    digitalWrite(relayPin6, HIGH);
  }
  else {
    digitalWrite(relayPin, LOW);  // Turn off Relay 1
    digitalWrite(relayPin2, HIGH);  // Turn off Relay 2
    digitalWrite(relayPin3, HIGH);  // Turn off Relay 3 when distance is outside of specified ranges
    digitalWrite(relayPin4, LOW);
    digitalWrite(relayPin5, LOW);
    digitalWrite(relayPin6, LOW);
  }

  delay(1000);
}