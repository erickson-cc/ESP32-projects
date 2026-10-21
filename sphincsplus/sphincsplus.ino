#include <Arduino.h>

extern "C" {
  #include "src/api.h"
}

void sphincsTask(void *pvParameters) {
  uint8_t *pk = (uint8_t *)malloc(PQCLEAN_SPHINCSSHA2256SSIMPLE_CLEAN_CRYPTO_PUBLICKEYBYTES);
  uint8_t *sk = (uint8_t *)malloc(PQCLEAN_SPHINCSSHA2256SSIMPLE_CLEAN_CRYPTO_SECRETKEYBYTES);
  uint8_t *sig = (uint8_t *)malloc(PQCLEAN_SPHINCSSHA2256SSIMPLE_CLEAN_CRYPTO_BYTES);
  size_t sig_len;

  if (pk == NULL || sk == NULL || sig == NULL) {
    Serial.println("Erro: Falha na alocação de memória RAM.");
    vTaskDelete(NULL);
  }

  uint8_t msg[] = "Teste SPHINCS+ no ESP32";
  size_t msg_len = sizeof(msg) - 1;

  Serial.println("Gerando chaves...");
  unsigned long t0 = millis();
  PQCLEAN_SPHINCSSHA2256SSIMPLE_CLEAN_crypto_sign_keypair(pk, sk);
  unsigned long t1 = millis();
  Serial.printf("Sucesso! Chaves geradas em %lu ms\n", t1 - t0);


  Serial.println("Assinando mensagem...");
  PQCLEAN_SPHINCSSHA2256SSIMPLE_CLEAN_crypto_sign_signature(sig, &sig_len, msg, msg_len, sk);
  Serial.printf("Assinatura gerada: %zu bytes.\n", sig_len);

  Serial.println("Verificando assinatura...");
  if (PQCLEAN_SPHINCSSHA2256SSIMPLE_CLEAN_crypto_sign_verify(sig, sig_len, msg, msg_len, pk) == 0) {
    Serial.println("Status: Verificacao OK!");
  } else {
    Serial.println("Status: Verificacao FALHOU!");
  }

  free(pk); free(sk); free(sig);
  vTaskDelete(NULL); 
}

void setup() {
  Serial.begin(115200);
  // Inicia a tarefa no núcleo 1 com 81920 bytes (80 KB) de Stack
  xTaskCreatePinnedToCore(sphincsTask, "PQC_Task", 81920, NULL, 1, NULL, 1);
  // FreeRTOS: Cria uma thread para o sphincsTask, 80kb (loop tem teto de 8kb)
}

void loop() {}
