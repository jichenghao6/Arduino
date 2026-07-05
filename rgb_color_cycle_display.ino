// 定义三个颜色控制引脚
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  // 将三个引脚都设置为输出模式
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // 纯红色
  setColor(255, 0, 0);  // 参数分别是 (红, 绿, 蓝) 的亮度，范围 0-255
  delay(1000);
  
  // 纯绿色
  setColor(0, 255, 0);
  delay(1000);
  
  // 纯蓝色
  setColor(0, 0, 255);
  delay(1000);
  
  // 混合色：紫色 (红+蓝)
  setColor(255, 0, 255);
  delay(1000);
  
  // 混合色：黄色 (红+绿)
  setColor(255, 255, 0);
  delay(1000);
  
  // 混合色：青色 (绿+蓝)
  setColor(0, 255, 255);
  delay(1000);
  
  // 混合色：白色 (红+绿+蓝全开)
  setColor(255, 255, 255);
  delay(1000);

  // 自己调制的神秘颜色 
  setColor(167,98,56);
  delay(1000);
}

// 这是一个我们自己创建的“魔法咒语”（自定义函数）
// 每次调用 setColor 时，它就会自动帮我们把三个数值分别发给三个引脚
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
