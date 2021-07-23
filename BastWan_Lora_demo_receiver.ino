#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  //while (!Serial);
  pinMode(RFM_SWITCH,OUTPUT);
  // RF switch 1 to Rx
  digitalWrite(RFM_SWITCH,1);  
  Serial.println("LoRa Receiver");
  LoRa.setPins(SS, RFM_RST, RFM_DIO0);
  if (!LoRa.begin(915E6)) {
  Serial.println("Starting LoRa failed!");
  while (1);
 }
}

void loop() {

// try to parse packet
    
    int packetSize = LoRa.parsePacket();
    
    if (packetSize) {
    Serial.print("");
    
    while (LoRa.available()) {
    Serial.print((char)LoRa.read()); // read packet
    }
  }
}
