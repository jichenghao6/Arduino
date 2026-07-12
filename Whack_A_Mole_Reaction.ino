// 定义灯和按键的引脚数组
int leds[3] = {12, 11, 10}; // 0:红, 1:黄, 2:绿
int btns[3] = {7, 6, 5};    // 0:红按键, 1:黄按键, 2:绿按键

void setup() {
  Serial.begin(9600);
  
  // 初始化引脚模式
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(btns[i], INPUT_PULLUP);
  }

  // 这一步非常关键：利用悬空模拟引脚的底噪，生成真正的随机数种子
  randomSeed(analogRead(A0)); 
  
  Serial.println("游戏开始！准备好你的手指！");
  delay(2000);
}

void loop() {
  // 1. 随机挑选一盏灯 (生成 0, 1, 2 中的一个随机数)
  int targetIndex = random(3); 
  
  // 2. 点亮这盏灯
  digitalWrite(leds[targetIndex], HIGH);
  unsigned long startTime = millis(); // 记录亮灯的瞬间时间
  
  bool isPressed = false;

  // 3. 进入“等待按键”的死循环，直到有人按下正确的按键
  while (!isPressed) {
    // 检查对应的按键是否被按下 (LOW代表按下)
    if (digitalRead(btns[targetIndex]) == LOW) {
      unsigned long reactionTime = millis() - startTime; // 计算反应时间
      
      Serial.print("击中目标！反应时间: ");
      Serial.print(reactionTime);
      Serial.println(" 毫秒");
      
      // 闪烁三次作为奖励反馈
      for(int j=0; j<3; j++){
        digitalWrite(leds[targetIndex], LOW);
        delay(100);
        digitalWrite(leds[targetIndex], HIGH);
        delay(100);
      }
      
      digitalWrite(leds[targetIndex], LOW); // 彻底熄灭
      isPressed = true; // 退出循环
    }
    
    // 如果按错了其他两个键，可以加一点惩罚逻辑（这里暂时留白，保持简单）
  }
  
  // 4. 随机等待 1 到 3 秒，再次出击
  delay(random(1000, 3000)); 
}
