// 这里将完成红绿灯项目

void setup() {
  // setup() 里的代码在开发板通电或复位时只运行一次
  // 这里是告诉 Arduino：我们要把 10、11、12 号引脚当作“输出 (OUTPUT)”端口来用
  pinMode(10, OUTPUT); // 对应绿灯
  pinMode(11, OUTPUT); // 对应黄灯
  pinMode(12, OUTPUT); // 对应红灯
}

void loop() {
  // loop() 里的代码会不断地循环运行，直到断电
  digitalWrite(10, HIGH);  // 给 10 号引脚通电（高电平），绿灯亮起
  delay(5000);             // 保持现状等待 5000 毫秒（即 5 秒）
  digitalWrite(10, LOW);   // 给 13 号引脚断电（低电平），绿灯熄灭

  digitalWrite(11, HIGH);  // 给 11 号引脚通电（高电平），黄灯亮起
  delay(1000);             // 保持现状等待 1000 毫秒（即 1 秒）
  digitalWrite(11, LOW);   // 给 11 号引脚断电（低电平），黄灯熄灭

  digitalWrite(12, HIGH);  // 给 13 号引脚通电（高电平），红灯亮起
  delay(5000);             // 保持现状等待 5000 毫秒（即 5 秒）
  digitalWrite(12, LOW);   // 给 13 号引脚断电（低电平），红灯熄灭
}
