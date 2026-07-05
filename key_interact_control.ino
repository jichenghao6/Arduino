int buttonPin = 2; // 给 2 号引脚起个名字叫 buttonPin（按键引脚）
int ledPin = 13;   // 给 13 号引脚起个名字叫 ledPin（LED引脚）

void setup() {
  // 告诉 Arduino，13 号引脚是用来输出的 (控制灯)
  pinMode(ledPin, OUTPUT);
  
  // 魔法指令！告诉 Arduino，2 号引脚用来输入，并且激活内部上拉电阻
  // 这样按键没按下时，Arduino 会读到 HIGH；按下按键接地时，会读到 LOW
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // 找个变量存起来：读取 2 号引脚现在的状态是 HIGH 还是 LOW
  int buttonState = digitalRead(buttonPin); 

  // 如果状态是 LOW（说明按键被按下了）
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH); // 开灯
  } 
  // 否则（说明按键没被按下）
  else {
    digitalWrite(ledPin, LOW);  // 关灯
  }
}
