int ledPin_1 = 9;          // led for potentiometer pin
int pentiPin = A0;         // potentiometer pin
int buttonPin = 2;         // off / on button pin
int buttonState = 0;       // state of button, if it is on or off 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin_1, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // if button is pressed
  if (buttonState == HIGH) {
    int amountLight = analogRead(pentiPin) / 4; // potentiometer, values range from 0-255

    analogWrite(ledPin_1, amountLight);

    // display led level
    Serial.print("LED brightness level is: ");
    Serial.println(amountLight);

    delay(1);
  }

  delay(30);
}