#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
int slots=10;

int slotpins[slots]={3,4,5,12,13,14,15,16,17,18};
void setup() {
  // put your setup code here, to run once:
  Wire.begin(21,22);
  for(int i=0;i<slots;i++){
    pinMode(slotpins[i],INPUT);
  }
  lcd.init();//start lcd
  lcd.backlight();//turn on backlight
  lcd.clear();
  lcd.setCursor(0, 0); // column 0, row 0 set cursor position

}

void loop() {
  // put your main code here, to run repeatedly:
  int slots_free=slots;
  int y;
  for(int j=0;j<slots;j++){
    y=digitalRead(slotpins[j]);
    if(y==LOW){
      slots_free--;
    }
  }
  Serial.print("No of free slots= ");
  Serial.println(slots_free);
  lcd.clear();
  lcd.print("No of free slots= ");
  lcd.print(slots_free);


}
