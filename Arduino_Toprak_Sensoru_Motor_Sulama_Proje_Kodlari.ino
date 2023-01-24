
#include<Wire.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float sensor = A0;
int motor = 6 ;

int veri;

void setup() {
  pinMode(sensor,INPUT);
  pinMode(motor,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Otomatik Sulama");
  delay(1000);
}

void loop() {
  veri=analogRead(sensor);
  Serial.println(veri);
delay(300);
if(veri>450)
{
  digitalWrite(motor,HIGH);
  delay(3000);
  digitalWrite(motor,LOW);
  delay(3000);
  veri=analogRead(sensor);
 Serial.println(":  iToprakdeal nem seviyesinin ustundedir, sulama sistemi devre-de..");  
 delay(300);
 lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sulama Yapiliyor");
  if(veri>450){
    digitalWrite(motor,HIGH);
    delay(2000);
    digitalWrite(motor,LOW);
    delay(5000);
    }
    else {
      digitalWrite(motor,LOW);
      }
      Serial.println(": Toprak ideal nem seviyesinin altindadir, sulama sistemi devre disi..");
      delay(300);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sulama Durdu");      
  }
  else
  {
    digitalWrite(motor,LOW);
    }

    lcd.setCursor(0,1);
  lcd.print(veri);
}