int potPin = A0;      // 电位器连接在 A0
int motorPin = 9;     // 控制马达的 PWM 信号连接在 9 号引脚

void setup() {
  // 设置马达控制引脚为输出模式
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); // 开启串口监视器查看数据
}

void loop() {
  // 1. 读取电位器的值 (0 到 1023)
  int potValue = analogRead(potPin);
  
  // 2. 将 0-1023 的数值等比例缩小到 0-255，作为 PWM 的调速值
  int speed = potValue / 4;
  
  // 3. 有些马达在极低电压下（比如 speed 小于 50）带不动风扇叶，会发出嗡嗡声
  // 我们可以加一个简单的判断：如果转速太低，干脆让它停下
  if (speed < 50) {
    speed = 0; 
  }

  // 4. 将计算好的速度值输出给马达驱动
  analogWrite(motorPin, speed);

  // 5. 打印当前数值到屏幕上
  Serial.print("电位器输入: ");
  Serial.print(potValue);
  Serial.print("  |  电机输出速度: ");
  Serial.println(speed);
  
  delay(50); // 短暂延时，保持系统稳定运行
}
