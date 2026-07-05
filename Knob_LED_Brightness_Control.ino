int potPin = A0;   // 电位器接在 A0（模拟输入）
int ledPin = 9;    // LED 接在 9 号引脚（注意：必须是带 ~ 的 PWM 引脚）

void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600); // 开启串口监视器，方便我们观察数据变化
}

void loop() {
  // 1. 读取电位器的值（范围是 0 到 1023）
  int potValue = analogRead(potPin); 
  
  // 2. 将读取到的 0-1023 转换为 0-255 的亮度值
  // 因为 1024 正好是 256 的 4 倍，所以直接除以 4 就可以啦！
  int brightness = potValue / 4; 
  
  // 3. 将计算好的亮度值输出给 LED
  // 注意：这里用的是 analogWrite()，而不是之前的 digitalWrite()
  analogWrite(ledPin, brightness); 

  // 4. 打印数据看看
  Serial.print("电位器读数: ");
  Serial.print(potValue);
  Serial.print("  |  转换后的亮度: ");
  Serial.println(brightness);
  
  delay(50); // 稍微延时，让系统稳定
}
