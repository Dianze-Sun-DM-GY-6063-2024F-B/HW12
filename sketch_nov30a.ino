const int potentiometerPin = A0; 
const int button1Pin = 2;       
const int button2Pin = 3;        
const int led1Pin = 13;         
const int led2Pin = 12;         

void setup() {
  pinMode(potentiometerPin, INPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potentiometerPin); 
  bool button1Pressed = digitalRead(button1Pin) == HIGH; 
  bool button2Pressed = digitalRead(button2Pin) == HIGH; 


  if (potValue > 1000) {

    if (button1Pressed && button2Pressed) {
      digitalWrite(led1Pin, HIGH); 
      digitalWrite(led2Pin, LOW); 
    }
    else if (button1Pressed || button2Pressed) {
      digitalWrite(led1Pin, LOW);  
      digitalWrite(led2Pin, HIGH); 
    }
    else {
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
    }
  } else {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
  }

  delay(200);
}
