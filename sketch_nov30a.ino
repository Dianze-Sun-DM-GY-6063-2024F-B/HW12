const int potentiometerPin = A0;  // 电位器连接到A0
const int button1Pin = 2;        // 按钮1连接到D2
const int button2Pin = 3;        // 按钮2连接到D3
const int led1Pin = 13;          // 灯1连接到D13（成功指示灯）
const int led2Pin = 12;          // 灯2连接到D12（失败指示灯）

void setup() {
  pinMode(potentiometerPin, INPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potentiometerPin); // 读取电位器的值（范围：0-1023）
  bool button1Pressed = digitalRead(button1Pin) == HIGH; // 检测按钮1是否按下
  bool button2Pressed = digitalRead(button2Pin) == HIGH; // 检测按钮2是否按下

  // 检测电位器是否调到最右（假设 >1000 为最右边）
  if (potValue > 1000) {
    Serial.println("Potentiometer is at maximum position.");

    // 如果两个按钮同时按下，点亮灯1（成功指示灯）
    if (button1Pressed && button2Pressed) {
      digitalWrite(led1Pin, HIGH); // 点亮灯1
      digitalWrite(led2Pin, LOW);  // 确保灯2熄灭
      Serial.println("Success: LED 1 is ON.");
    }
    // 如果只按下一个按钮，点亮灯2（失败指示灯）
    else if (button1Pressed || button2Pressed) {
      digitalWrite(led1Pin, LOW);  // 确保灯1熄灭
      digitalWrite(led2Pin, HIGH); // 点亮灯2
      Serial.println("Failure: LED 2 is ON.");
    }
    // 如果没有按钮按下，所有灯熄灭
    else {
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
      Serial.println("No buttons pressed. Both LEDs are OFF.");
    }
  } else {
    // 如果电位器未调到最右，所有灯熄灭
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    Serial.println("Potentiometer not at maximum. Both LEDs are OFF.");
  }

  delay(200); // 防止按钮抖动
}
