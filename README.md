# Arduino
这里存储了我初步学习Arduino项目时用到的代码  
This stores the codes I used when learning Arduino projects.  

## 项目说明  
以下是我在入门Arduino时所学习的项目：  
Here are the projects I worked on when I was first getting started with Arduino:  
1.点亮第一盏灯 Lighting Up the First LED
* 在这个项目中，我点亮了我的第一盏灯，这相当于学习编程语言的Print("Hello, World!")，这意味着我正式踏入了硬件学习之旅。我想这只需要给LED灯串联一个电阻，并接入一个数字信号输出口，就可以完成这一个项目了。  
In this project, I lit up my first LED — the hardware equivalent of a print("Hello, World!") in programming. It marks my official first step into the world of hardware. As I understand it, all it takes is wiring a resistor in series with the LED and plugging it into a digital output pin, and the project is done.

2.按键交互控制 Interactive Button Control
* 在这个项目中，我学习了使用按键来控制LED灯是否亮起。在第一个项目（点亮第一盏灯）的基础上，我们需要给按键接入数字引脚回路，来作为数字控制信号的输入口。代码中变量存储输入引脚的电位状态，并以变量状态决定输出电位状态。这样就实现了按键交互控制。  
In this project, I learned how to use a button to control whether an LED lights up. Building on the first project (Lighting Up the First LED), we needed to connect the button to a digital pin circuit to serve as an input for digital control signals. In the code, a variable stores the voltage state of the input pin, and the output voltage state is determined by that variable's value. This is how interactive button control is achieved.

3.智能光控报警 Smart Light-Controlled Alarm
* 在这个项目中，我手上的是光敏传感器模块，而不是单纯的裸露光敏电阻元件，模块有DO（数字输出）引脚，输出数字信号，而不是输出连续模拟信号。将模块接入5V电压回路中并将DO引脚与数字引脚相连，得以传输控制信号。有源蜂鸣器也是模块，不完全依赖于信号引脚的微弱电流。将此模块也接入5V电压回路中并将信号引脚与另一数字引脚相连。当环境光度低于传感器阈值时，蜂鸣器响起。  
In this project, I worked with a light sensor module rather than a bare photoresistor component. The module has a DO (Digital Output) pin that outputs a digital signal instead of a continuous analog signal. I connected the module to a 5V circuit and wired the DO pin to a digital pin to transmit the control signal. The active buzzer was also a module, meaning it doesn't rely entirely on the weak current from the signal pin. I connected this module to the 5V circuit as well and wired its signal pin to another digital pin. When the ambient light level falls below the sensor's threshold, the buzzer sounds.

4.旋钮控制 LED 亮度 Knob-Controlled LED Brightness
* 将电位器 B10k接入5V电压回路中，并将信号引脚与Arduino板的模拟引脚相连。LED灯串联电阻后正极接入带`~`符号的数字引脚，负极接地。当旋动旋钮时，模拟引脚接受电位器的值（0-1023），转化为 0-255 的亮度值，并传输给LED。  
Connect the B10k potentiometer to the 5V circuit and wire its signal pin to an analog pin on the Arduino board. Connect the LED in series with a resistor: the anode (positive leg) goes to a digital pin marked with ~, and the cathode (negative leg) goes to ground. When you turn the knob, the analog pin reads the potentiometer value (0–1023), which is mapped to a brightness value of 0–255 and output to the LED.

5.全彩 RGB 调色大师 Full-Color RGB Color Mixing
* 将全彩RGB灯的接地端接地，将分别控制红绿蓝的三个引脚连接到Arduino的数字引脚，经过代码的调参，全彩RGB灯就可以点亮不同的颜色。  
Connect the common ground pin of the full-color RGB LED to ground, and wire the three pins controlling red, green, and blue to digital pins on the Arduino. By adjusting the parameters in the code, the RGB LED can light up in different colors.

6.无级变速智能风扇 Stepless Speed Control Smart Fan
* 1
