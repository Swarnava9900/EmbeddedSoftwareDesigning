#include <CryptoAES_CBC.h>
#include <AES.h>

AES128 aes; 
String key = "523647892340954";
String message = "Hey, How are you";
uint8_t keyArray[16] = {0};
unsigned char encrypted[16];
unsigned char decrypted[16];

void setup() {
  Serial.begin(115200);

  memcpy(keyArray, key.c_str(), key.length() > 16 ? 16 : key.length());
  
  aes.setKey(keyArray, 16);

  unsigned char original[16] = {0}; 
  memcpy(original, message.c_str(), message.length() > 16 ? 16 : message.length());

  // Encrypt
  aes.encryptBlock(encrypted, original);

  // Decrypt
  aes.decryptBlock(decrypted, encrypted);

  // Print results
  Serial.print("Original mssg : ");
  for(int i = 0; i < 16; i++) {
    Serial.printf("%02x ", original[i]);
  }
  Serial.println(message);
  
  Serial.print("Cypher text : ");
  for (int i = 0; i < 16; i++) {
    Serial.printf("%02x ", encrypted[i]);  // Print hex bytes
  }
  Serial.println();

  Serial.print("And final Text: ");
  Serial.println((char*)decrypted);  // Convert back to string
}

void loop() {
  // No need for a loop in this example
}
