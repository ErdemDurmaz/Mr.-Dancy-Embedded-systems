#include <Servo.h>
#include <Oscillator.h>
#include <EEPROM.h>

#define N_SERVOS 4
#define EEPROM_TRIM false //Activate for calibration

#define TRIM_RR 18
#define TRIM_RL 18
#define TRIM_YR 26
#define TRIM_YL 18

#define PIN_RR 3
#define PIN_RL 2
#define PIN_YR 4
#define PIN_YL 5

#define INTERVALTIME 10.0 

Oscillator servo[N_SERVOS];

void drunk (int tempo);
void kickLeft(int tempo);
void kickRight(int tempo);
void pasitos(int steps, int tempo);
void run(int steps, int T=500);
void walk(int steps, int T=1000);
void backyard(int steps, int T=3000);
void moonWalkLeft(int steps, int T=1000);
void moonWalkRight(int steps, int T=1000);
void crusaito(int steps, int T=1000);
void swing(int steps, int T=1000);
void upDown(int steps, int tempo);
void flapping(int steps, int T=1000);

void setup()
{
  Serial.begin(19200);
  
  servo[0].attach(PIN_RR);
  servo[1].attach(PIN_RL);
  servo[2].attach(PIN_YR);
  servo[3].attach(PIN_YL);
  
  int trim;
  
  if(EEPROM_TRIM){
    for(int x=0;x<4;x++){
      trim=EEPROM.read(x);
      if(trim>128)trim=trim-256;
      Serial.print("TRIM ");
      Serial.print(x);
      Serial.print(" en ");
      Serial.println(trim);
      servo[x].SetTrim(trim);
    }
  }
  else{
    servo[0].SetTrim(TRIM_RR);
    servo[1].SetTrim(TRIM_RL);
    servo[2].SetTrim(TRIM_YR);
    servo[3].SetTrim(TRIM_YL);
  }
  
  for(int i=0;i<4;i++) servo[i].SetPosition(90);

}

// TEMPO: 97 BPM
int t=620;
double pause=0;

void loop() {
  
  pasitos(8,t*2);
  crusaito(1,t);
  patada(t);
  delay(t);
  twist(2,t);
  twist(3,t/2);
  upDown(1,t*2);
  patada(t*2);
  drunk(t*2);
  flapping(1,t*2);
  walk(2,t);
  walk(1,t*2);
  backyard(2,t);
  patada(t*2);
  flapping(1,t*2);
  patada(t*2);
  twist(8,t/2);
  moonWalkLeft(2,t);
  crusaito(1,t*2);
  
  for(int i=0; i<2 ;i++){
    lateral_fuerte(0,t);
    lateral_fuerte(1,t);
    upDown(1,t*2);
  }
  
  saludo(1,t*2);
  saludo(1,t);
  delay(t);
  swing(3,t);
  for(int i=0;i<4;i++) servo[i].SetPosition(90);
  delay(t);
  
  lateral_fuerte(0,t);
  lateral_fuerte(1,t);
  lateral_fuerte(0,t/2);
  lateral_fuerte(1,t/2);
  lateral_fuerte(0,t/2);
  delay(t/2);
  lateral_fuerte(0,t);
  lateral_fuerte(1,t);
  lateral_fuerte(0,t/2);
  lateral_fuerte(1,t/2);
  delay(t);
  
  pasitos(1,t*2);
  pasitos(1,t);
  delay(t/2);
  pasitos(1,t*2);
  pasitos(1,t);
  delay(t/2);
     
  crusaito(2,t);
  crusaito(1,t*2);
  crusaito(2,t);
  crusaito(1,t*2);
  crusaito(2,t);
  crusaito(1,t*2);
  
  upDown(2,t);
  crusaito(1,t*2);
  for(int i=0;i<4;i++) servo[i].SetPosition(90);
  delay(t/2);
  pasitos(2,t*2);
  pasitos(2,t);
  flapping(1,t*2);
  upDown(2,t);
  upDown(1,t*2);
  
  for (int i=0; i<4; i++){
    pasitos(1,t);
    delay(t);
  }
  reverencia1(1,t*4);
  reverencia2(1,t*4);
  upDown(1,t);
  run(2,t/2);
  patada(t*2);

  lateral_fuerte(0,t);
  lateral_fuerte(1,t);
  upDown(2,t);
  lateral_fuerte(0,t);
  lateral_fuerte(1,t);
  upDown(2,t);
  pasitos(4,t);
  lateral_fuerte(0,t);
  lateral_fuerte(1,t);
  upDown(2,t);
  
  patada(t*2);
  pasitos(2,t);
  patada(t*2);
  pasitos(2,t);
  swing(2,t*2);
  pasitos(4,t);
  
  for (int i=0; i<4; i++){
    lateral_fuerte(0,t);
    lateral_fuerte(1,t);
    lateral_fuerte(0,t/2);
    lateral_fuerte(1,t/2);
    lateral_fuerte(0,t/2);
  delay(t/2);
  }
  
  pasitos(6,t);
  delay(t);
  pasitos(1,t);
  delay(t/2);
  pasitos(3,t);
  delay(t/2);
  swing(4,t);
  
  twist(2,t/2);
  delay(t/2);
  twist(2,t/2);
  delay(t/2);
  
  drunk(t*2);
  drunk(t/2);
  drunk(t*2);
  delay(t/2);
  walk(1,t);
  backyard(1,t);
  
  servo[0].SetPosition(110);
  servo[1].SetPosition(130);
  delay(t);
  
  crusaito(3,t);
  crusaito(1,2*t);
  upDown(1,t*2);
  upDown(2,t/2);
  
  kickLeft(t/2);
  kickRight(t/2);
  moonWalkLeft(1,t*2);
  moonWalkLeft(2,t);
  moonWalkRight(1,t*2);
  moonWalkRight(2,t);
  
  walk(4,t);
  backyard(4,t);
  
  lateral_fuerte(0,t);
  lateral_fuerte(0,t);
  lateral_fuerte(1,t);
  lateral_fuerte(1,t);
  walk(2,t);
  backyard(2,t);
  
  pasitos(6,t*2);
  swing(1,t);
  upDown(1,t);
  delay(t);
  upDown(6,t);
  delay(t);
  
  for (int i=0;i<4;i++){
    lateral_fuerte(0,t);
    lateral_fuerte(1,t);
  }
  
  delay(t);
  for (int i=0;i<7;i++){
    pasitos(2,t);
    swing(2,t);
  }
  
  pasitos(1,t);
  crusaito(1,t*2);
  upDown(1,t);
  
  delay(2000);
  

}