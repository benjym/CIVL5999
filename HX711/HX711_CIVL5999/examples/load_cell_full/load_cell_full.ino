/* sample for digital weight scale of hx711
 * library design: Weihong Guan (@aguegu)
 * library host on
 *https://github.com/aguegu/ardulibs/tree/3cdb78f3727d9682f7fd22156604fc1e4edd75d1/hx711
 */

// Hx711.DOUT - pin #A2
// Hx711.SCK - pin #A3

#include <Hx711.h>
Hx711 scale(A2, A3);
long reading;
float voltage;
float mass;
float m; // slope of fitting curve
float b; // intercept of fitting curve
int N; // number of samples to average over

void setup() {
  Serial.begin(9600);
  m = 0.0006667; // put your own value here
  b = 0.06131649017; // put your own value here
  N = 100; // put your own value here
}

void loop() {
  reading = 0;
  for (int i=0; i<N; i++) {
    reading = reading + scale.getValue();
  }
  reading = reading/N; // divide by number of readings
  voltage = float(reading)/16777216*5; // 
  
  mass = (voltage - b)/m; // invert fitting curve
  Serial.print(mass, 10);
  Serial.println(" g");
  
  delay(200);
}

