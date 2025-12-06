#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#define ir_in 25 // make sure pin supports interrupt
#define ir_out 26
volatile bool entryflag=false;
volatile bool exitflag=false;
int slots_free=10;
void setup() {
  // put your setup code here, to run once:
  pinMode(ir_in,INPUT);
  pinMode(ir_out,INPUT);
  Serial.begin(9600);
  
  Wire.begin(21, 22);//to say which pin is SDA and SCL in esp
  lcd.init();//start lcd
  lcd.backlight();//turn on backlight
  lcd.clear();
  lcd.setCursor(0, 0); // column 0, row 0 set cursor position
  
  attachInterrupt(digitalPinToInterrupt(ir_in),isr_in,FALLING);//interrupt after lcd cause interrupt might fire before lcd is set
  attachInterrupt(digitalPinToInterrupt(ir_out),isr_out,FALLING);
  
}
void isr_in(){
  entryflag=true;
}
void isr_out(){
  exitflag=true;
}
void loop() {
  // put your main code here, to run repeatedly:


if (entryflag && (slots_free>0)){
  Serial.println("Car Entered");
  slots_free--;
  Serial.print("No of free slots= ");
  Serial.println(slots_free);
  lcd.clear();
  lcd.print("No of free slots= ");
  lcd.print(slots_free);
  entryflag=false;//reset flag
}
if (exitflag && (slots_free<10)){
  Serial.println("Car left");
  slots_free++;
  Serial.print("No of free slots= ");
  Serial.println(slots_free);
  lcd.clear();
  lcd.print("No of free slots= ");
  lcd.print(slots_free);
  exitflag=false;
}
if (entryflag && (slots_free==0)){
  
  Serial.print("No Entry, Slots filled");
  lcd.clear();
  lcd.print("No Entry, Slots Filled");
  
  entryflag=false;
  
}
if (exitflag && (slots_free==10)){
  Serial.print("No of free slots= 10");
  lcd.clear();
  lcd.print("No of free slots= 10");
  
  exitflag=false;
}
}
