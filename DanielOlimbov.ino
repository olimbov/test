#define up      11
#define down     9
#define left    10
#define right    6

#define btnR    12
#define btnB     3
#define btnY     2
#define btnG     4

#define LEDS_AND_BTNS 4
int btns[LEDS_AND_BTNS]={btnR,btnB,btnY,btnG};
int leds[LEDS_AND_BTNS]={right,up,down,left};
bool LedIsOn[LEDS_AND_BTNS]={false,false,false,false};
bool BtnIsPressed[LEDS_AND_BTNS]={false,false,false,false};

void setup() {
  
for(byte k=0;k<LEDS_AND_BTNS;k++){
    pinMode(btns[k],INPUT_PULLUP);
    pinMode(leds[k],OUTPUT);
  }
}
void toggleLed(byte channel){
  if(LedIsOn[channel]){
    LedOff(channel);
  } else {
    LedOn(channel);
  }
}
void LedOn(byte channel){
  digitalWrite(leds[channel],HIGH);
  LedIsOn[channel]=true;
}
void LedOff(byte channel){
  digitalWrite(leds[channel],LOW);
  LedIsOn[channel]=false;
}

void loop() {
  for(byte channel=0;channel<LEDS_AND_BTNS;channel++){
    if(digitalRead(btns[channel])==LOW){
      if(! BtnIsPressed[channel]){
        BtnIsPressed[channel]=true;
        toggleLed(channel);
      }
    } else {
      BtnIsPressed[channel]=false;
    }
  }
  delay(20);
}
