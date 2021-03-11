//control EM-2 stepper motor(P43G)
//Author:Yen-Shuo,Su
//Date:2020/9/2
//1.1

#define TIME 19800 //delay time with micro seconds
byte count = 0;
byte pin[5] = {0, 1, 2, 3, 4}; //Output 'Blue' 'White' 'Black' 'Yellow'

void setup() {
  for(int i = 0 ; i < 5 ; i++){
    pinMode(pin[i], OUTPUT);
  }
  //pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  while(1){
    digitalWrite(pin[0], HIGH);    
    digitalWrite(pin[1], LOW);
    delayMicroseconds(TIME);
    digitalWrite(pin[3], HIGH);
    digitalWrite(pin[2], LOW);
    delayMicroseconds(TIME);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[0], LOW);
    delayMicroseconds(TIME);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delayMicroseconds(TIME);
    count++;
    if(count == 25){
      digitalWrite(pin[4],!digitalRead(pin[4]));
      count = 0;
    }
  }
}
