#include "esp_random.h"
void setup() {
  Serial.begin(115200);
}

void loop() {
  uint8_t buf[32];
  esp_fill_random(buf, sizeof(buf));
  Serial.print("Seed: ");
  for (int i=0;i<sizeof(buf);i++){
    Serial.printf("%02X", buf[i]);
  }
  Serial.println();
  delay(1000);
}
