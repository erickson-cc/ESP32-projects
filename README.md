# ESP32-projects
Projetos para estudo da arquitetura do microcontrolador ESP-32U utilizando a ferramenta arduino-cli.

# Installation

[x] Instalar a ferramenta arduino-cli
```
sudo pacman -Syu arduino-cli
```

[x] Configurar o repositório da placa
```
arduino-cli config init
arduino-cli config add board_manager.additional_urls https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
arduino-cli core update-index
arduino-cli core install esp32:esp32
```
[x] Adicionar permissões de acesso serial ao usuário
```
sudo usermod -aG uucp $USER
sudo usermod -aG lock $USER
```
[x] Indentificar a porta conectada (reiniciar o computador caso não identifique)
```
arduino-cli board list
```
[x] Rodar o comando de *permissions* de upload para a placa.
```
sudo chmod 666 /dev/ttyUSB0
```
[x] Iniciar o projeto
```
arduino-cli sketch new <nome-do-projeto>
```

# Código

Alterar o arquivo .ino conforme a seguinte interface
```
void setup() {
  Serial.begin(115200);
}

void loop() {
}
```
# Compilação
[x] executar os comandos de *compile* e *upload*
```
arduino-cli compile --fqbn esp32:esp32:esp32 <nome-do-projeto>
arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 <nome-do-projeto>
```

# Monitoramento
Rodar o código com o seguinte código
```
arduino-cli monitor -p /dev/ttyUSB0 --config baudrate=115200
```
