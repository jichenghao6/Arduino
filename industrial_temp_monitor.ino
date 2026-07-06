int tiltPin = 2;    // 温度传感器接在 2 号引脚
int buzzerPin = 8;  // 蜂鸣器接在 8 号引脚

void setup() {
  // 魔法咒语：设置为输入，并激活内部上拉电阻
  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int tiltState = digitalRead(tiltPin); // 读取温度传感器的状态

  // 当传感器检测温度大于阈值温度时，Arduino 会读到 HIGH
  if (tiltState == HIGH) {
    digitalWrite(buzzerPin, HIGH);  // 触发警报！
  } else {
    digitalWrite(buzzerPin, LOW);   // 不响
  }
}
