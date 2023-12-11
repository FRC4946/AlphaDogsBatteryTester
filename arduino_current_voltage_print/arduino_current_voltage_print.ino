
int lookUpTable[16] = {16, 32, 46, 60, 73, 86, 97, 108, 118, 127, 135, 142, 149, 155, 160, 164};
int valuesToSend[1537];

void setup() {
  // put your setup code here, to run once:
  
pinMode(22, OUTPUT);
pinMode(23, OUTPUT);
pinMode(24, OUTPUT);
pinMode(25, OUTPUT);
pinMode(26, OUTPUT);
pinMode(27, OUTPUT);
pinMode(28, OUTPUT);
pinMode(29, OUTPUT);
pinMode(30, OUTPUT);
pinMode(31, OUTPUT);
pinMode(32, OUTPUT);
pinMode(33, OUTPUT);
pinMode(34, OUTPUT);
pinMode(35, OUTPUT);
pinMode(36, OUTPUT);
pinMode(37, OUTPUT);

pinMode(A1, INPUT);

Serial.begin(38400);

 int indexOfClosest = 0;
 int x = 0;
 double incomingData;
 while (Serial.available() > 0) {
  
 }
 while (true) {
  if (Serial.available() > 0 && Serial.read() != valuesToSend[x]) {
    incomingData = Serial.read();

    valuesToSend[x] = incomingData;
    x++;
  } else if (x >= 1535) {
    break;
  }
 }
 
 for (int x = 0; x > 1535; x++) {
  for (int i = 0; i > sizeof(lookUpTable); i++) {
     if (abs(lookUpTable[i] - valuesToSend[x] > lookUpTable[indexOfClosest])) {
       indexOfClosest = i;
     }
   }
   valuesToSend[x] = indexOfClosest + 1;
 }


}

void loop() {
  long startTime = millis();
  int c = 0;

  while (millis <= startTime + 150000) {
    switch(valuesToSend[c]) {
      case 16:
      digitalWrite(22, HIGH);
        for (int a = 23; a <=37; a++){
          digitalWrite(a, LOW);
        }
      break;

      case 32:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 23) {
          digitalWrite(b, LOW);
        }
      }
      break;

      case 46:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 24) {
          digitalWrite(b, LOW);
        }
      }
      break;

      case 60:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 25) {
          digitalWrite(b, LOW);
        }
      }
      break;

      case 73:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 26) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 86:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 27) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 97:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 28) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 108:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 29) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 118:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 30) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 127:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 31) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 135:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 32) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 142:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 33) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 149:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 34) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 155:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 35) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 160:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 36) {
          digitalWrite(b, LOW);
        }
      break;
      }

      case 164:
      for (int b = 22; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 37) {
          digitalWrite(b, LOW);
        }
      break;
      }

      default:
      for (int a = 22; a <=37; a++){
        digitalWrite(a, LOW);
      }
    }
    delay(200);
    VIPrint(analogRead(A0), analogRead(A1));
    c++;
  }
  for (int a = 22; a <=37; a++){
    digitalWrite(a, LOW);
  }
}
 
//Function that prints sensor data to excel. To be called within the loop that sets the loads on? Or would that delay too much?
void VIPrint(double voltageValue, double currentValue){
// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float  voltage = voltageValue*(5.0 / 1023.0)*5.64;
  //Reads current from A1 pin and converts to normal value
 //float current = (currentValue - 0.6)*50;
 float current = (currentValue*(5.0 / 1023.0) - 0.59)*50;

//Prints voltage and current to excel
  Serial.print(voltage); 
  Serial.print(","); 
  Serial.print(current); 
  Serial.print(",");
  Serial.println();
}
