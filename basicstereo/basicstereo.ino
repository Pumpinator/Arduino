#include <SoftwareSerial.h> 
#include <DFRobotDFPlayerMini.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
String mensaje="";
int volumen=15;


SoftwareSerial serialMP3(9, 10); // RX, TX

DFRobotDFPlayerMini miMP3;
void setup() {
   Serial.begin(9600);
   serialMP3.begin(9600);
   lcd.begin(16,2); // inicializar lcd
  lcd.setCursor(0,0); //pos columna (C,R)
  lcd.print("Reproductor MP3");
  lcd.setCursor(0,1);
  lcd.print("  F o x ..");
  delay(5000);
  lcd.clear();
  Serial.println("Reproductor DFPlayer Mini 16P");
  Serial.println("-----------------------------");
  Serial.println(" 1.- Reproducir pista #1");
  Serial.println(" +.- Subir Volumen ");
  Serial.println(" -.- Bajar Volumen ");
  Serial.println(" 2.- Reproducir siguiente Pista");
  Serial.println(" 3.- Reproducir Pista Anterior");
  Serial.println(" r.- Equalizer Rock");
  Serial.println(" p.- Equalizer Pop");
  Serial.println(" j.- Equalizer Jazz");
  Serial.println(" n.- Equalizer Normal");
  Serial.println(" b.- Equalizer Blues");

}

void loop() {
  char v;
   if (Serial.available()>0){
      v=Serial.read();
      if(v=='1'){
        miMP3.begin(serialMP3); //Use softwareSerial para comunicarse con el MP3.
         miMP3.volume(15);  //nivel de volumen es de  0 to 30
         miMP3.play(1);  //Play para la primer pista mp3
         miMP3.EQ(DFPLAYER_EQ_NORMAL);
         lcd.clear();
         lcd.print("reproducir pista");
         for(int i=0;i<16;i++){
            lcd.scrollDisplayRight();
            delay(100);
         }
        
      }
      if(v=='+'){
        miMP3.volumeUp();
        volumen++;
        lcd.clear();
         mensaje="Volumne "+String(volumen);
        lcd.print(mensaje);
        for(int i=0;i<16;i++){
            lcd.scrollDisplayRight();
            delay(500);
         }
      }
      if(v=='-'){
        miMP3.volumeDown();
        volumen--;
        lcd.clear();
         mensaje="Volumne "+String(volumen);
        lcd.print(mensaje);
        for(int i=0;i<16;i++){
            lcd.scrollDisplayRight();
            delay(500);
         }
      }
      if(v=='2'){
         miMP3.next();
         lcd.clear();
         lcd.print("> Pista");
         delay(1000);
         lcd.clear();
         lcd.print("reproducir pista");
         for(int i=0;i<16;i++){
            lcd.scrollDisplayRight();
            delay(500);
         }
      }
      if(v=='3'){
        miMP3.previous();
         lcd.clear();
         lcd.print("< Pista");
         delay(1000);
         lcd.clear();
         lcd.print("reproducir pista");
         for(int i=0;i<16;i++){
           lcd.scrollDisplayRight();
           delay(500);
         }
      }
      if(v=='r'){
        miMP3.EQ(DFPLAYER_EQ_ROCK);
         lcd.clear();
         lcd.print("EQ_ROCK");
         delay(1000);
         lcd.clear();
         lcd.print("reproduciendo pista");
         for(int i=0;i<16;i++){
           lcd.scrollDisplayRight();
           delay(500);
         }
      }
      if(v=='p'){
        miMP3.EQ(DFPLAYER_EQ_POP);
         lcd.clear();
         lcd.print("EQ_POP");
         delay(1000);
         lcd.clear();
         lcd.print("reproduciendo pista");
         for(int i=0;i<16;i++){
           lcd.scrollDisplayRight();
           delay(500);
         }
      }
      if(v=='j'){
        miMP3.EQ(DFPLAYER_EQ_JAZZ);
         lcd.clear();
         lcd.print("EQ_JAZZ");
         delay(1000);
         lcd.clear();
         lcd.print("reproduciendo pista");
         for(int i=0;i<16;i++){
           lcd.scrollDisplayRight();
           delay(500);
         }
      }
      if(v=='c'){
        miMP3.EQ(DFPLAYER_EQ_CLASSIC);
         lcd.clear();
         lcd.print("EQ_CLASIC");
         delay(1000);
         lcd.clear();
         lcd.print("reproduciendo pista");
         for(int i=0;i<16;i++){
           lcd.scrollDisplayRight();
           delay(500);
         }
      }
      if(v=='B'){
        miMP3.EQ(DFPLAYER_EQ_BASS);
         lcd.clear();
         lcd.print("EQ_BASS");
         delay(1000);
         lcd.clear();
         lcd.print("reproduciendo pista");
         for(int i=0;i<16;i++){
           lcd.scrollDisplayRight();
           delay(500);
         }
      }
   }
}
