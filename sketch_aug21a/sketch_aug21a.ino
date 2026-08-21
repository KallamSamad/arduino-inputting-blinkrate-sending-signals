#define LED_PIN 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

int blinkDelayValue(){
  int blinkDelay;
  bool valid=false;
  Serial.println("Input a number between 100 and 1000!");
      do{
        if(Serial.available()>0){
          blinkDelay = Serial.parseInt();
        }
        if(blinkDelay >= 100 && blinkDelay <= 1000){
          valid=true;
        }
      } while (valid==false);
      return blinkDelay;
}

void loop() {
  // put your main code here, to run repeatedly:
      int timeDelay=blinkDelayValue();
      Serial.println(timeDelay);
      digitalWrite(LED_PIN, HIGH);
      delay(timeDelay);
      digitalWrite(LED_PIN, LOW);
      delay(timeDelay);
}
