#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 6, 8, 9, 10, 11);

const int trigPin = 13;
const int echoPin = 12;
const int buzzerPin = 3;

const int distanceThresholds[8] = {5, 8, 11, 14, 17, 20,23,26};
const int maxDistance = 70;
const int tones[8] = {1000, 900, 800, 700, 600, 500,400,300}; // 去掉了tones[6]，因为数组索引最大为5

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = (duration == 0) ? 0 : duration * 0.034 / 2; // 处理无回声的情况

  int toneIndex = 0; // 添加一个变量来存储音调索引
  for (int i = 0; i < 8; i++) {
    if (distance < distanceThresholds[i]) {
      tone(buzzerPin, tones[toneIndex]);
      break;
    }
    toneIndex++;
  }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.setCursor(0, 1);
  lcd.print("Tone: ");
  lcd.print(tones[toneIndex]);

  delay(500);
  noTone(buzzerPin); // 停止声音
}