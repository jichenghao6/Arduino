int sensorPin = 7;    // 传感器 DO 引脚接在数字 7
int buzzerPin = 8;    // 蜂鸣器接在数字 8

void setup() {
  pinMode(sensorPin, INPUT);   // 传感器作为输入
  pinMode(buzzerPin, OUTPUT);  // 蜂鸣器作为输出
  Serial.begin(9600);          // 开启串口监视器，方便我们观察
}

void loop() {
  // 读取模块传来的数字信号（只有 HIGH 或 LOW）
  int lightState = digitalRead(sensorPin); 
  
  // 打印到电脑屏幕上，1代表HIGH，0代表LOW
  Serial.println(lightState);

  // 大部分这种模块在光线“暗”时会输出 HIGH（1），光线“亮”时输出 LOW（0）
  // 但是我这个光传感器模块在光线“暗”时会输出 LOW（0），光线“亮”时输出 HIGH（1）
  if (lightState == LOW) {
    digitalWrite(buzzerPin, HIGH);  // 蜂鸣器响
  } else {
    digitalWrite(buzzerPin, LOW);   // 蜂鸣器不响
  }
  
  delay(100); 
}
