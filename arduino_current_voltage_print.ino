void setup() {
  // put your setup code here, to run once:
  
pinMode(23, OUTPUT);
pinMode(25, OUTPUT);
pinMode(27, OUTPUT);
pinMode(29, OUTPUT);
pinMode(31, OUTPUT);
pinMode(33, OUTPUT);
pinMode(35, OUTPUT);
pinMode(37, OUTPUT);
pinMode(39, OUTPUT);
pinMode(41, OUTPUT);
pinMode(43, OUTPUT);
pinMode(45, OUTPUT);
pinMode(47, OUTPUT);
pinMode(49, OUTPUT);
pinMode(51, OUTPUT);
pinMode(53, OUTPUT);
pinMode(A0, INPUT);
pinMode(A1, INPUT);

Serial.begin(38400);
}

void loop() {
 /*for len of thing:
  if (abs(LUT[i]- input) > last closest)  {
    closest = lut[i]
  }
  */
 // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);

  float current = (voltage - 0.6)*50;

/*take in data from whatever format
 * probably json or csv
 * create new table that takes time values and numbers from look up table for amount of loads being fired and amps
 * plug in
*/

Serial.print(voltage); 
Serial.print(","); 
Serial.print(current); 
Serial.print(",");
Serial.println();

delay(500);
}
