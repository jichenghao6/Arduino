// 我们的第一个程序：点亮并闪烁一盏灯

void setup() {
  // setup() 里的代码在开发板通电或复位时只运行一次
  // 这里是告诉 Arduino：我们要把 13 号引脚当作“输出 (OUTPUT)”端口来用
  pinMode(13, OUTPUT);
}

void loop() {
  // loop() 里的代码会不断地循环运行，直到断电
  digitalWrite(13, HIGH);  // 给 13 号引脚通电（高电平），LED 亮起
  delay(1000);             // 保持现状等待 1000 毫秒（即 1 秒）
  digitalWrite(13, LOW);   // 给 13 号引脚断电（低电平），LED 熄灭
  delay(1000);             // 保持现状等待 1000 毫秒（即 1 秒）
}
