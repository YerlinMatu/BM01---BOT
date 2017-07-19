 
const int piezo = 6;
const int echo = 8;
const int trig = 9;
const int ledRed = 12; 
const int ledGreen = 13;

int motorA []= {10, 11};
int motorB [] = {4, 5};

unsigned int tiempo, distancia; 

int tonos [] = {26, 27, 29, 31, 33, 34, 37 };
int numTonos =  sizeof(tonos);

void setup() {
  
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);  
}


void loop() {
  
   UltraDetector();   
}

void ArrancarMotores(){
    digitalWrite(motorA[0], HIGH);
    digitalWrite(motorB[0], HIGH);
    LedBlink(ledGreen);     
}

void RetrocederMotores(){
    digitalWrite(motorA[1], HIGH);
    digitalWrite(motorB[1], HIGH);
    LedBlink(ledGreen); 
}

void UltraDetector(){
     digitalWrite(trig, LOW);
     delayMicroseconds(2);
     digitalWrite(trig, HIGH);
     delayMicroseconds(10);
     digitalWrite(trig, LOW);
     ArrancarMotores();
     tiempo = pulseIn(echo, HIGH);
     distancia = tiempo / 58;
     
     if(distancia <= 15){
        SoundBeep(200);
        LedON(ledRed);     
        delay(200);
      }
       else {
        noTone(piezo);
        RetrocederMotores();   
      }
      
}

void SoundBeep(unsigned int pausa){
    analogWrite(piezo, 40);
    delay(pausa);           // Esperar
    analogWrite(piezo, 0); // Apagar
    delay(pausa);   
 }

void SomeBeep(){
  for (int item = 0; item < numTonos; ++item){
        tone(piezo, tonos[item]);
        delay(500);
  }  
}

void LedON(unsigned int pinLed){
     digitalWrite(pinLed, HIGH);  
}

void LedOFF(unsigned int pinLed){
     digitalWrite(pinLed, LOW);  
}

void LedBlink(unsigned int pinLed){
     digitalWrite(pinLed, HIGH);
     delay(500);
     digitalWrite(pinLed, LOW);
}



