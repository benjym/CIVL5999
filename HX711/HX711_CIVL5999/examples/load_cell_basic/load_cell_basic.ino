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

void setup() {
  Serial.begin(9600);
}

void loop() {
  reading = scale.getValue();
//  Serial.println(reading); // show the raw value from the ADC

  voltage = float(reading)/16777216*5; // 24-bit ADC in 5V range after amplifier
  Serial.print(voltage, 10); // the second argument is the number of decimal places to print
  Serial.println(" V");

  delay(200);
}

