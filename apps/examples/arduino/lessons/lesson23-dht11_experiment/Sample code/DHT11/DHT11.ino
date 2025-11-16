/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 8
void setup(void)
{
  Serial.begin(9600);
}
void loop(void)
{
  DHT11.read(DHT11PIN);
  Serial.print("TMEP=");
  Serial.print(DHT11.temperature);
  Serial.print(" C");
  Serial.print('\t');
  Serial.print("HUM=");
  Serial.print(DHT11.humidity);
  Serial.println(" %");
  delay(500);
}

