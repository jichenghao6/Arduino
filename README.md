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
* 直流马达是不可以直接插在Arduino的数字引脚上的，这回导致Arduino板芯片烧毁。电位器与第四个项目（旋钮控制 LED 亮度）接法一致。下一步将ULN2003驱动板的标注"+"的接口接入Arduino板的5V电压，标注"-"的接口接地。将`IN2`接口接入Arduino板带有`~`的数字引脚。下一步将马达一条线接到5V正极，另一条线接入ULN2003的输出端（步进电机接口）。  
DC motors should not be plugged directly into Arduino's digital pins — this will burn out the Arduino board's chip. The potentiometer wiring is the same as in the fourth project (knob controlling LED brightness). Next, connect the interface marked "+" on the ULN2003 driver board to the Arduino board's 5V, and the interface marked "−" to ground. Connect the `IN2` interface to a digital pin with `~` on the Arduino board. Next, connect one wire of the motor to the 5V positive terminal, and the other wire to the ULN2003's output terminal (stepper motor interface).

7.防盗倾斜报警系统 Anti-theft Tilt Alarm System
* 有源蜂鸣器的连接方式与第三个项目（智能光控报警）无异。倾斜开关也是模块，将两个引脚接入5V电压回路并将信号引脚接入Arduino板的数字引脚。  
The active buzzer is wired the same way as in the third project (smart light-controlled alarm). The tilt switch is also a module: connect its two pins to the 5V power circuit and its signal pin to a digital pin on the Arduino board.

8.自动化交通信号系统 Automated Traffic Signal System
* 将红绿蓝三个LED灯负极接地，像这种多线接地可以使用面包板电源轨，来防止GND不够的情况。然后将正极分别串联一个电阻并接入到Arduino的数字引脚上。  
Connect the negative terminals of the red, green, and blue LEDs to ground. For multiple ground connections like this, you can use the breadboard's power rails to prevent running out of GND pins. Then connect the positive terminals each in series with a resistor to the Arduino's digital pins.

9.工业环境温度监测 Industrial Ambient Temperature Monitoring
* 热敏电阻模块和有源蜂鸣器的接法完全可以借鉴参考第七个项目（防盗倾斜报警系统）。  
The wiring for the thermistor module and the active buzzer can be directly referenced from the seventh project (Anti-theft Tilt Alarm System).

10.四位数码管计时 Four-Digit Seven-Segment Display Timer
* 我的四位数码管的型号为5461AS，有12根引脚。下表为具体接法：  
My four-digit seven-segment display model is 5461AS, with 12 pins. The table below shows the specific wiring:

| 数码管引脚位置    | 引脚功能代表     | 连接到 Arduino 的位置 | 备注说明    |
| :--------- | :--------- | :-------------- | :------ |
| 引脚 1 (左下)  | E 段        | 数字引脚 6          | 段选线     |
| 引脚 2       | D 段        | 数字引脚 5          | 段选线     |
| 引脚 3       | DP (小数点)   | 数字引脚 9          | 段选线     |
| 引脚 4       | C 段        | 数字引脚 4          | 段选线     |
| 引脚 5       | G 段        | 数字引脚 8          | 段选线     |
| 引脚 6 (右下)  | D4 (第4个数字) | 数字引脚 13         | 需串联一个电阻 |
| 引脚 7 (右上)  | B 段        | 数字引脚 3          | 段选线     |
| 引脚 8       | D3 (第3个数字) | 数字引脚 12         | 需串联一个电阻 |
| 引脚 9       | D2 (第2个数字) | 数字引脚 11         | 需串联一个电阻 |
| 引脚 10      | F 段        | 数字引脚 7          | 段选线     |
| 引脚 11      | A 段        | 数字引脚 2          | 段选线     |
| 引脚 12 (左上) | D1 (第1个数字) | 数字引脚 10         | 需串联一个电阻 |

11.迷你“打地鼠”反应力测试仪 Mini "Whack-a-Mole" Reaction Tester
* 红绿蓝三个LED灯接线方式参考地八个项目（自动化交通信号系统）。将9V电池和9V电池扣连接到Arduino板上。现在它可以脱离电脑独立运作了！  
The wiring for the red, green, and blue LEDs follows the eighth project (Automated Traffic Signal System). Connect the 9V battery and 9V battery clip to the Arduino board. Now it can operate independently without a computer!
