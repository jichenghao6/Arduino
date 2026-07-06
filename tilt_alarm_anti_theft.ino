int tiltPin = 2;    // 倾斜开关接在 2 号引脚
int buzzerPin = 8;  // 蜂鸣器接在 8 号引脚

void setup() {
  // 魔法咒语：设置为输入，并激活内部上拉电阻
  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int tiltState = digitalRead(tiltPin); // 读取倾斜开关的状态

  // 当开关倾斜导致内部小钢珠滚开、电路断开时，Arduino 会读到 LOW
  if (tiltState == LOW) {
    digitalWrite(buzzerPin, HIGH);  // 触发警报！
  } else {
    digitalWrite(buzzerPin, LOW);   // 安全状态，不响
  }
}
