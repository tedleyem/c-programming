#include <Servo.h>

const int trigPin = 12;
const int echoPin = 11;
const int ledRedPin = 7;   // 红灯LED的引脚
const int ledGreenPin = 6; // 绿灯LED的引脚
long duration;
int distance;
Servo myServo;

void setup() {
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);
    pinMode(ledRedPin, OUTPUT);   // 初始化红灯LED引脚
    pinMode(ledGreenPin, OUTPUT); // 初始化绿灯LED引脚
    Serial.begin(9600);
    myServo.attach(9);
}

void loop() {
    // 舵机转动
    for(int i=15; i<=165; i++){
        myServo.write(i);
        delay(30);
        distance = calculateDistance();
        Serial.print(i); 
        Serial.print(","); 
        Serial.print(distance);
        Serial.print(".");
        
        // 控制LED状态
        if(distance < 30){ // 假设30厘米内检测到物体为警告条件
            digitalWrite(ledRedPin, HIGH);   // 点亮红灯
            digitalWrite(ledGreenPin, LOW);  // 熄灭绿灯
        } else {
            digitalWrite(ledRedPin, LOW);    // 熄灭红灯
            digitalWrite(ledGreenPin, HIGH); // 点亮绿灯
        }
    }
    
    // 等待一段时间或进行其他操作
    delay(1000);
}

int calculateDistance(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
  
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    return distance;
}