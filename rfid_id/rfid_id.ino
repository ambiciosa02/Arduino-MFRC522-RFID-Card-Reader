#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10  // Pin de sélection du slave (SDA)
#define RST_PIN 9  // Pin de reset (RST)

MFRC522 mfrc522(SS_PIN, RST_PIN); // Création d'une instance du lecteur RFID

void setup() {
  Serial.begin(9600);  // Initialisation du moniteur série
  SPI.begin();         // Initialisation de la communication SPI
  mfrc522.PCD_Init();  // Initialisation du module MFRC522

  Serial.println("Approche une carte RFID...");
}

void loop() {
  // Vérifie si une nouvelle carte est présente
  if (mfrc522.PICC_IsNewCardPresent()) {
    // Si une carte est présente, lis son ID unique
    if (mfrc522.PICC_ReadCardSerial()) {
      Serial.print("ID de la carte : ");
      
      // Affiche l'ID de la carte
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      
      mfrc522.PICC_HaltA();   // Arrête la lecture de la carte
      mfrc522.PCD_StopCrypto1();  // Désactive la cryptographie
    }
  }
}
