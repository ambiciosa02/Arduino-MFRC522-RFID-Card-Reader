# Arduino-MFRC522-RFID-Card-Reader
This Arduino sketch is a basic RFID card reader example using the MFRC522 module. It reads the unique ID (UID) of an RFID card and prints it to the Serial Monitor.

🔍 How it works
1️⃣ Hardware setup

MFRC522 RFID module:

SDA (SS) → pin 10

RST → pin 9

SCK, MOSI, MISO → Arduino SPI pins (typically 13, 11, 12 on Uno)

VCC & GND → 3.3V and GND

2️⃣ Program flow

Setup:

Start Serial Monitor at 9600 bps.

Initialize SPI communication with SPI.begin().

Initialize the MFRC522 module with mfrc522.PCD_Init().

Print "Approche une carte RFID..." to prompt the user.

Loop:

Check if a new card is present using mfrc522.PICC_IsNewCardPresent().

If present, read the card's UID with mfrc522.PICC_ReadCardSerial().

Print each byte of the UID in hexadecimal format to the Serial Monitor.

Stop reading the card with mfrc522.PICC_HaltA() and mfrc522.PCD_StopCrypto1().
