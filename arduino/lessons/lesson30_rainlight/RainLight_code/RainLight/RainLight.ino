#include <Servo.h>

Servo myServo;  // 创建舵机控制对象

const int servoPin = 13;  // 舵机控制引脚
const int waterSensorPin = 2;  // 水位传感器引脚
const int lightSensorPin = A0;  // 光敏电阻引脚
const int lightThreshold = 900;  // 光线阈值
const int ledPin = 9; // LED引脚
bool isAtNinetyDegrees = false; // 状态标志，初始时舵机不在90度位置
void setup() {
  myServo.attach(servoPin);  // 将舵机与引脚连接
  pinMode(waterSensorPin, INPUT);  // 设置水位传感器引脚为输入模式
  pinMode(lightSensorPin, INPUT);  // 设置光敏电阻引脚为输入模式
  pinMode(ledPin, OUTPUT);  // 设置LED引脚为输出模式
  Serial.begin(9600);  // 启动串行通信
}

void loop() {
  int waterLevel = digitalRead(waterSensorPin);  // 读取水位传感器状态
  int lightLevel = analogRead(lightSensorPin);  // 读取光敏电阻的值

  // 打印光敏电阻的值
  Serial.print("Light Sensor Value: ");
  Serial.println(lightLevel);
  delay(1000); // 延迟一段时间，让舵机转动

  // 检查光敏电阻的值，点亮LED
  if (lightLevel < 720) {
    digitalWrite(ledPin, HIGH); // 点亮LED
  } else {
    digitalWrite(ledPin, LOW); // 关闭LED
  }

  // 检查水位传感器的状态，根据条件调整舵机
 if (waterLevel == HIGH&& !isAtNinetyDegrees) {
    // 当水位为HIGH时，舵机以10度增量旋转90度
    for (int angle = 0; angle <= 160; angle += 20) {
      myServo.write(angle);
      delay(500); // 延迟一段时间，让舵机转动
    }
     isAtNinetyDegrees = true; // 更新状态标志，舵机已旋转到90度
  } else if (waterLevel != HIGH && isAtNinetyDegrees) {
    // 当水位不为HIGH时，舵机以10度增量旋转回到0度
    for (int angle = myServo.read(); angle >= 0; angle -= 10) {
      myServo.write(angle);
      delay(500); // 延迟一段时间，让舵机转动
    }
    isAtNinetyDegrees = false; // 更新状态标志，舵机已回到0度
  }
}
