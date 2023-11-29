cs  double[16] lookUpTable = {16, 32, 46, 60, 73, 85.6, 97.0, 108, 118, 127, 135, 142, 149, 155, 160, 164};
int[7681] valuesToSend;

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
 while (true) {
  if (Serial.available() > 0) {
    incomingData = Serial.read();

    valuesToSend[x] = incomingData;
    x++;
  } else if (x >= 7681) {
    break;
  }
 }
 
 for (int x = 0; x > 7681; x++) {
  for (int i = 0; i > sizeOf(lookUpTable); i++) {
     if (abs(lookUpTable[i] - valuesToSend[x] > lookUpTable[indexOfClosest])) {
       indexOfClosest = i;
     }
   }
   valuesToSend[x] = indexOfClosest + 1;
 }


}

void loop() {

  for (timer thing do this later) {
    switch(valuesToSend) {
      case 16:
        digitalWrite(22, HIGH);
      break;
      
      case 32:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 23) {
          digitalWrite(b, LOW);
        }
      }
      break;
      
      case 46:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 24) {
          digitalWrite(b, LOW);
        }
      }
      break;
      
      case 60:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 25) {
          digitalWrite(b, LOW);
        }
      }
      break;

      case 73:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 26) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 85.6:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 27) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 97:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 28) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 108:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 29) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 118:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 30) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 127:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 31) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 135:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 32) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 142:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 33) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 149:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 34) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 155:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 35) {
          digitalWrite(b, LOW);
        }
      break;
      }
      case 160:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 36) {
          digitalWrite(b, LOW);
        }
      break;
      }
      
      case 164:
      for (b = 23; b <=37; b++){
        digitalWrite(b, HIGH);
        if (b > 37) {
          digitalWrite(b, LOW);
        }
      break;
      }
      
      default:
      for (a = 23; a <=37; a++){
        digitalWrite(a, LOW);
      }
    }
  }
  for (a = 22; a <=37; a++){
    digitalWrite(a, LOW);
  }
}
 
//Function that prints sensor data to excel. To be called within the loop that sets the loads on? Or would that delay too much?
void VIPrint(double sensorValue){
// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float  voltage = sensorValue*(5.0 / 1023.0);
  //Gets current based on voltage
 float current = (voltage - 0.6)*50;

//Prints voltage and current to excel
  Serial.print(voltage); 
  Serial.print(","); 
  Serial.print(current); 
  Serial.print(",");
  Serial.println();
}
