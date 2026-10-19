const int LED_PIN = 16;
const int DOT_DURATION = 200;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void dot() {
  digitalWrite(LED_PIN, HIGH);
  delay(DOT_DURATION);
  digitalWrite(LED_PIN, LOW);
  delay(DOT_DURATION);
}

void dash() {
  digitalWrite(LED_PIN, HIGH);
  delay(DOT_DURATION * 3);
  digitalWrite(LED_PIN, LOW);
  delay(DOT_DURATION);
}

void letterSpace(){
  delay(DOT_DURATION * 2);
}

void wordSpace(){
  delay(DOT_DURATION * 6);
}

void playMorse(const char *sequence){
  for (int i=0; sequence[i] != '\0'; i++){
    if(sequence[i]=='.') dot(); 
    else if(sequence[i]=='-') dash(); 
    else if(sequence[i]==' ') letterSpace();
    else if(sequence[i]=='/') wordSpace();
  }
}

void loop() {
  //playMorse(".... . .-.. .-.. --- / .-- --- .-. .-.. -..");

  delay(2000);
  Serial.println("Pin Down");
  digitalWrite(LED_PIN, LOW);
  delay(2000);
  Serial.println("Pin Up");
  digitalWrite(LED_PIN, HIGH);

  for (int i =0; i < 200; i++){
    digitalWrite(i, LOW);
    delay(10);

  }
}
