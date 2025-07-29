
#include <Wire.h>
#include <TEA5767N.h>
#include <LiquidCrystal_I2C.h>

int NB = 11;
int M = 10;
int P1 = 12;
int B2 = 13;
float freq = 92.0;
int flag =2;
bool lightstate = 0;
bool mutestate = 0;
bool modestate = 0;
float searchArr[50];
float storeArr[50];
int i=0,j=0;
int currentstation=0;
#define  LED_PIN 3

LiquidCrystal_I2C lcd(0x27, 16, 2);
TEA5767N Radio = TEA5767N();

void MANsetup() {
  //Init
  lcd.init();
  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, 50); 
  lcd.setCursor(0, 1);
  lcd.print("MANUAL");
  lcd.setCursor(13, 0);
  lcd.print("MHz");
  lcd.setCursor(0, 0);
  lcd.print("FREQ:");
  lcd.setCursor(6,  0);
  lcd.print(freq); 
  Radio.selectFrequency(freq);
  Radio.turnTheSoundBackOn();
}

void AUTOsetup() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    SCANNING    ");
  lcd.setCursor(0, 1);
  lcd.print("    STARTED...  ");
  delay(2000);
  lcd.init();
  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, 1000); 
  byte isBandLimitReached = 0;

  lcd.setCursor(0, 0);
  if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.print("SEARCHING UP....");
  if(digitalRead(M)!=HIGH){goto stopScan;}
  Radio.setSearchMidStopLevel();
  if(digitalRead(M)!=HIGH){goto stopScan;}
  isBandLimitReached = Radio.startsSearchMutingFromBeginning();
    if(digitalRead(M)!=HIGH){goto stopScan;}
  delay(2000);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.setCursor(0, 1);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  float freq = Radio.readFrequencyInMHz();
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.print("STATION: ");
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.print(freq);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  searchArr[i] = freq;
    if(digitalRead(M)!=HIGH){goto stopScan;}
  i++;
    if(digitalRead(M)!=HIGH){goto stopScan;}
  delay(2000);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  
  while (!isBandLimitReached) {
      if(digitalRead(M)!=HIGH){goto stopScan;}
    lcd.setCursor(0, 0);
      if(digitalRead(M)!=HIGH){goto stopScan;}
    lcd.print("SEARCHING UP....");
      if(digitalRead(M)!=HIGH){goto stopScan;}
    isBandLimitReached = Radio.searchNextMuting();
      if(digitalRead(M)!=HIGH){goto stopScan;}
    delay(2000);
      if(digitalRead(M)!=HIGH){goto stopScan;}
    lcd.setCursor(0, 1);
      if(digitalRead(M)!=HIGH){goto stopScan;}
    freq = Radio.readFrequencyInMHz();
      if(digitalRead(M)!=HIGH){goto stopScan;}
    lcd.print("STATION: ");
      if(digitalRead(M)!=HIGH){goto stopScan;}
    lcd.print(freq);
      if(digitalRead(M)!=HIGH){goto stopScan;}
    searchArr[i] = freq;
      if(digitalRead(M)!=HIGH){goto stopScan;}
    i++;
      if(digitalRead(M)!=HIGH){goto stopScan;}
    delay(2000);
      if(digitalRead(M)!=HIGH){goto stopScan;}
  }
  
  lcd.setCursor(0, 0);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.print("BAND END REACHED");
    if(digitalRead(M)!=HIGH){goto stopScan;}
  delay(2000);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.setCursor(0, 1);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.print("SEARCHING DOWN..");
    if(digitalRead(M)!=HIGH){goto stopScan;}
  Radio.setSearchDown();
    if(digitalRead(M)!=HIGH){goto stopScan;}
  Radio.setSearchMidStopLevel();
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.setCursor(0, 0);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.println("SEARCHING DOWN..");
    if(digitalRead(M)!=HIGH){goto stopScan;}
  isBandLimitReached = Radio.searchNextMuting();
    if(digitalRead(M)!=HIGH){goto stopScan;}
  delay(2000);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.setCursor(0, 1);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  freq = Radio.readFrequencyInMHz();
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.println("STATION: ");
    if(digitalRead(M)!=HIGH){goto stopScan;}
  lcd.print(freq);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  searchArr[i] = freq;
    if(digitalRead(M)!=HIGH){goto stopScan;}
  i++;
    if(digitalRead(M)!=HIGH){goto stopScan;}
  delay(2000);
    if(digitalRead(M)!=HIGH){goto stopScan;}
  
  while (!isBandLimitReached) {
      if(digitalRead(M)!=HIGH){goto stopScan;}
   lcd.setCursor(0, 0);
     if(digitalRead(M)!=HIGH){goto stopScan;}
   lcd.print("SEARCHING DOWN..");
     if(digitalRead(M)!=HIGH){goto stopScan;}
    isBandLimitReached = Radio.searchNextMuting();
      if(digitalRead(M)!=HIGH){goto stopScan;}
    delay(2000);
      if(digitalRead(M)!=HIGH){goto stopScan;}
    lcd.setCursor(0, 1);
      if(digitalRead(M)!=HIGH){goto stopScan;}
    freq = Radio.readFrequencyInMHz();
      if(digitalRead(M)!=HIGH){goto stopScan;}
    lcd.print("STATION: ");
      if(digitalRead(M)!=HIGH){goto stopScan;}
    lcd.print(freq);
      if(digitalRead(M)!=HIGH){goto stopScan;}
    searchArr[i] = freq;
      if(digitalRead(M)!=HIGH){goto stopScan;}
    i++;
      if(digitalRead(M)!=HIGH){goto stopScan;}
    delay(2000);
      if(digitalRead(M)!=HIGH){goto stopScan;}
  }
    lcd.setCursor(0, 1);
      if(digitalRead(M)!=HIGH){goto stopScan;}
    lcd.print("BAND END REACHED");
      if(digitalRead(M)!=HIGH){goto stopScan;}
stopScan:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    SCANNING    ");
  lcd.setCursor(0, 1);
  lcd.print("    STOPPED...  ");
  delay(1000);

    for(j=0;j<50;j++){
        if(searchArr[j]!=0){
          storeArr[j]=searchArr[j];
    }}

  lcd.clear();
  lcd.setCursor(13, 0);
  lcd.print("MHz");
  lcd.setCursor(0, 0);
  lcd.print("FREQ:");
  lcd.setCursor(0, 1);
  lcd.print("AUTO");
  lcd.setCursor(6, 1);
  lcd.print("NO:");
}



void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, 1000);
  pinMode(P1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(NB, INPUT_PULLUP);
  pinMode(M, INPUT_PULLUP);
  lcd.setCursor(0, 0);
  lcd.print(" LONG PRESS RED ");
  lcd.setCursor(0, 1);
  lcd.print("TO BEGIN SCAN...");
}

void loop() {
    if (digitalRead(NB)!=HIGH) {
    delay(1000);
    if (digitalRead(NB)!=HIGH) {
    lightstate = !lightstate;
    if (lightstate) {
      lcd.backlight();
    }else{
      lcd.noBacklight();
    }}}

  if (digitalRead(M)!=HIGH) {
    delay(500);
    if (digitalRead(M)!=HIGH) {
    modestate = !modestate;
    if (modestate){
      AUTOsetup();
      flag=1;
    }
    else if(!modestate)
    { MANsetup();
      flag=0;
    }
  }}

  if(flag==1){
    lcd.setCursor(6,  0);
    lcd.print(storeArr[currentstation]);
    lcd.setCursor(9, 1);
    lcd.print(currentstation+1);
    do{     
  if (digitalRead(P1)!=HIGH && digitalRead(B2)!=HIGH) {
    delay(500);
    if (digitalRead(P1)!=HIGH && digitalRead(B2)!=HIGH) {
    mutestate = !mutestate;
    if (mutestate) {
      lcd.setCursor(12, 1);
      lcd.print("MUTE");
      Radio.mute();
    }else{
      lcd.setCursor(11, 1);
      lcd.print("     ");
      Radio.turnTheSoundBackOn();
  }}}

    else if (digitalRead(NB)!=HIGH) {
    delay(1000);
    if (digitalRead(NB)!=HIGH) {
    lightstate = !lightstate;
    if (lightstate) {
      lcd.backlight();
    }else{
      lcd.noBacklight();
    }}}

    else if (digitalRead(P1)!=HIGH) {
    currentstation++;
      if(currentstation==i){currentstation=0;}
    Radio.selectFrequency(storeArr[currentstation]);
    lcd.setCursor(6,  0);
    lcd.print("      ");    
    lcd.setCursor(6,  0);
    lcd.print(storeArr[currentstation]);
    lcd.setCursor(9,  1);
    lcd.print("   ");  
    lcd.setCursor(9, 1);
    lcd.print(currentstation+1);
    }

    else if (digitalRead(B2)!=HIGH) {
    currentstation--;
      if(currentstation==-1){currentstation=(i-1);}
    Radio.selectFrequency(storeArr[currentstation]);
    lcd.setCursor(6,  0);
    lcd.print("      "); 
    lcd.setCursor(6,  0);
    lcd.print(storeArr[currentstation]);
    lcd.setCursor(9,  1);
    lcd.print("   ");
    lcd.setCursor(9, 1);
    lcd.print(currentstation+1);
    }}
    while(digitalRead(M)==HIGH);
  }

  else if(flag==0){
    lcd.setCursor(6, 0);
    lcd.print(freq);
    do{
  
  if (digitalRead(P1)!=HIGH && digitalRead(B2)!=HIGH) {
    delay(500);
    if (digitalRead(P1)!=HIGH && digitalRead(B2)!=HIGH) {
    mutestate = !mutestate;
    if (mutestate) {
      lcd.setCursor(11, 1);
      lcd.print("MUTED");
      Radio.mute();
    }else{
      lcd.setCursor(11, 1);
      lcd.print("     ");
      Radio.turnTheSoundBackOn();
    }}}

    if (digitalRead(NB)!=HIGH) {
    delay(1000);
    if (digitalRead(NB)!=HIGH) {
    lightstate = !lightstate;
    if (lightstate) {
      lcd.backlight();
    }else{
      lcd.noBacklight();
    }}}

  else if (digitalRead(P1)!=HIGH) {
    delay(300);
        if (digitalRead(P1)!=HIGH){ 
                if (freq<=107.9){freq+=1;}
                else{freq=76;}
                Radio.selectFrequency(freq);
                lcd.setCursor(6,  0);
                lcd.print(freq);}
    else{
    if (freq<=107.9) {freq+=0.1;}
    else{freq=76;}
    Radio.selectFrequency(freq);
    lcd.setCursor(6,  0);
    lcd.print(freq);}}
  
  else if(digitalRead(B2)!=HIGH)  {
        delay(300);
        if (digitalRead(B2)!=HIGH){ 
                if (freq>=76.1){freq-=1;}
                else{freq=108;}
                Radio.selectFrequency(freq);
                lcd.setCursor(6, 0);
                lcd.print(freq);}
    else{
    if (freq>=76.1) {freq-=0.1;}
    else{freq=108;}
    Radio.selectFrequency(freq);
    lcd.setCursor(6, 0);
    lcd.print(freq);}
  }

    }
    while(digitalRead(M)==HIGH);
  }
}
