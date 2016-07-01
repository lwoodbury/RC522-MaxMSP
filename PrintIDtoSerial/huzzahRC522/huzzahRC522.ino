/*
 * --------------------------------------------------------------------------------------------------------------------
 * Print the RFID tag ID to serial
 * --------------------------------------------------------------------------------------------------------------------
 * This sketch borrows from the MFRC522 library examples; 
 * for further details and other examples see: https://github.com/miguelbalboa/rfid
 *
 * Huzzah Pins
 * RST  - 4
 * SS   - 5 (SDA)
 * MOSI - 13 
 * MISO - 12 
 * SCK  - 14 
 * 3V to 3V and GND to GND!!!
 * 
 * Luke Woodbury 24th February 2016
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   4     // Configurable, see typical pin layout above
#define SS_PIN    5    // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

void setup() {
  Serial.begin(9600);  // Initialize serial communications with the PC
  while (!Serial);     // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();         // Init SPI bus
  mfrc522.PCD_Init();  // Init MFRC522 card
 }

void loop() {
  
  // Look for new cards, and select one if present
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  
  // Now a card is selected. The UID and SAK is in mfrc522.uid.
  // Dump UID
  //Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
 // Serial.println("I'm here!");
  Serial.println();
  

}
