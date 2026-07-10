// 1. 定义段选线引脚 (A-G, DP)
int segments[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// 2. 定义位选线引脚 (D1-D4)
int digits[4] = {10, 11, 12, 13};

// 3. 字模字典 (0-9)
byte numPattern[10][8] = {
  {1,1,1,1,1,1,0,0}, // 0
  {0,1,1,0,0,0,0,0}, // 1
  {1,1,0,1,1,0,1,0}, // 2
  {1,1,1,1,0,0,1,0}, // 3
  {0,1,1,0,0,1,1,0}, // 4
  {1,0,1,1,0,1,1,0}, // 5
  {1,0,1,1,1,1,1,0}, // 6
  {1,1,1,0,0,0,0,0}, // 7
  {1,1,1,1,1,1,1,0}, // 8
  {1,1,1,1,0,1,1,0}  // 9
};

// --- 新增的计数器变量 ---
int currentCount = 0;           // 当前的数字
unsigned long previousMillis = 0; // 上次更新数字的时间
const long interval = 100;      // 数字增加的时间间隔（毫秒）。设为 100 跑得快点方便观察，设为 1000 就是现实的1秒

void setup() {
  for(int i = 0; i < 8; i++) pinMode(segments[i], OUTPUT);
  for(int i = 0; i < 4; i++) {
    pinMode(digits[i], OUTPUT);
    digitalWrite(digits[i], HIGH);
  }
}

void loop() {
  // --- 任务 1：计时与数值更新（大脑逻辑） ---
  unsigned long currentMillis = millis(); // 看一眼现在的“系统时间”
  
  // 如果现在的时间减去上次更新的时间，大于等于我们设定的间隔
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // 记录下这次更新的时间
    currentCount++;                 // 数字加 1
    
    if (currentCount > 9999) {      // 如果超过 9999，就清零重来
      currentCount = 0;
    }
  }

  // --- 任务 2：数学拆解（把 4 位数拆成 4 个独立的数字） ---
  // 巧妙利用整数除法 (/) 和 取余数 (%)
  int qian = (currentCount / 1000) % 10; // 千位
  int bai  = (currentCount / 100) % 10;  // 百位
  int shi  = (currentCount / 10) % 10;   // 十位
  int ge   = currentCount % 10;          // 个位

  // --- 任务 3：动态扫描显示（视觉输出） ---
  // 注意这里没有 delay() 阻碍，屏幕会一直保持极速刷新
  displayDigit(0, qian);
  displayDigit(1, bai);
  displayDigit(2, shi);
  displayDigit(3, ge);
}

// 核心魔法函数：负责“点亮某一位的某个数字”
void displayDigit(int digitIndex, int number) {
  // 1. 消隐：全灭
  for(int i = 0; i < 4; i++) {
    digitalWrite(digits[i], HIGH);
  }
  // 2. 输送笔画
  for(int i = 0; i < 8; i++) {
    digitalWrite(segments[i], numPattern[number][i]);
  }
  // 3. 点亮指定位
  digitalWrite(digits[digitIndex], LOW);
  // 4. 极短停留骗过人眼
  delay(5); 
}
