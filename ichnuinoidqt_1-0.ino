 //*************************************** 
 //***           ICHNUINO              ***
 //***  Iphone Display Quality Tester  ***
 //***                                 ***
 //***           ver. 1.0              ***
 //***    build_20190330fw0100hw011    ***
 //***                                 ***
 //***           by ichnoLab           ***
 //***         www.ichnolab.it         ***
 //****************************************************************
 //****************************************************************
 //**-Testing setup:                                            ***
 //**-sensor touching the glass (no glass protectors);          ***
 //**-display brigthness 100% (no night shift) ;                ***
 //**-open dialer screen, put the sensor on a white sector;     ***
 //****************************************************************
 //****************************************************************
   
 #include <Wire.h>
 #include "Adafruit_TCS34725.h"
 #include <Adafruit_SSD1306.h>
 #include <Adafruit_GFX.h>
 #include<Arduino.h>
 #include<Fonts/Org_01.h>

 #define SCREEN_WIDTH 128 // OLED display width, in pixels
 #define SCREEN_HEIGHT 64 // OLED display height, in pixels

 //TestingEngineDB(rev_2.1)
 //(make your own testings before modify, this one is based on >100 parts testing)
 
 //color temp levels
 int kMin = 8500;  
 int kBad = 7500;        
 int kAvg = 7000;
 int kGud = 6500;
 int kOem = 6000;
 int kOvr = 4750;
 //brightness levels 
 int lMin = 300;  
 int lBad = 400;
 int lAvg = 500;
 int lGud = 750;
 int lOem = 950;
 int lOvr = 1950;
 
 // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
 #define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
 Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

 /*don't touch (leave custom init settings)
 /* Initialise with default values (int time = 2.4ms, gain = 1x) */
 // Adafruit_TCS34725 tcs = Adafruit_TCS34725();
 
 /* Initialise with custom values (int time = 700ms, gain = 1x) */
 Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
 
 // ichnolab logo bmp (please don't remove, it's cute!)
const unsigned char ichnolab_logobmp9 [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1F, 0xC0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x1F, 0xC0, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x1F, 0xC0, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xF8, 0x1F, 0xC0, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xF8, 0x1F, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xF0, 0x1F, 0xC0, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xE0, 0x1F, 0xC0, 0x1F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xC0, 0x1F, 0xC0, 0x0F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x80, 0x1F, 0xC0, 0x07, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x1F, 0xC0, 0x03, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x1F, 0xC0, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x1F, 0xC0, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x1F, 0xC0, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x1F, 0xC0, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x1F, 0xC0, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x1F, 0xC0, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x1F, 0xE0, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x3F, 0xF0, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x7F, 0xF8, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0xFF, 0xF8, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0xFF, 0xFC, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0xF8, 0x7C, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x01, 0xF0, 0x3C, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x01, 0xE0, 0x3C, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0xE0, 0x3C, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0xE0, 0x3C, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0xE0, 0x38, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x60, 0x38, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x20, 0x30, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x03, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xC0, 0x00, 0x00, 0x0F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x1F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xF8, 0x00, 0x00, 0x7F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFE, 0x00, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xC0, 0x07, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
};

 void setup(void)
{
  Serial.begin(9600);
 
  pinMode(3, OUTPUT);  //buzzer
  pinMode(13, OUTPUT);  //led indicator

 // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
 if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
 Serial.println(F("SSD1306 allocation failed"));
 for(;;); // Don't proceed, loop forever
  } 
  else {
 //splash 
 display.display();
 display.clearDisplay();
 display.setFont(&Org_01);
 for(int16_t i=max(display.width(),display.height())/2; i>0; i-=3) {
 display.fillCircle(display.width() / 2, display.height() / 2, i, INVERSE);
 display.display(); 
 digitalWrite(3,HIGH);
 delay(1);
 digitalWrite(3,LOW);
 delay(1);
 digitalWrite(3,HIGH);
 delay(1);
 digitalWrite(3,LOW);
 delay(1);
  }
 //logo
 display.clearDisplay();
 display.drawBitmap(0, 0,  ichnolab_logobmp9, 128, 64, WHITE);
 display.display();
 delay(50);
 digitalWrite(3,HIGH);
 delay(100);
 digitalWrite(3,LOW);
 delay(50);
 digitalWrite(3,HIGH);
 delay(100);
 digitalWrite(3,LOW);
 //delay(50);
 //digitalWrite(3,HIGH);
 //delay(100);
 //digitalWrite(3,LOW);
 //delay(500);
 display.clearDisplay();
 //splash2
  for(int16_t i=0; i<max(display.width(),display.height())/2; i+=2) {
    display.drawCircle(display.width()/2, display.height()/2, i, WHITE);
    display.display();
    delay(1);
  }
 display.display();
 delay(1);
 //IDQT 
 display.clearDisplay();
 display.setTextSize(2);             
 display.setTextColor(WHITE);        
 display.setCursor(30,9);             
 display.println(F("ichnuino"));
 display.display();
 digitalWrite(3,HIGH);
 delay(50);
 digitalWrite(3,LOW);
 delay(100);
 display.drawLine(0, 15, 128, 15, WHITE); 
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(18,23);             
 display.println(F("DISPLAY QUALITY"));
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(44,32);             
 display.println(F("TESTER"));
 display.display();
 digitalWrite(3,HIGH);
 delay(50);
 digitalWrite(3,LOW);
 delay(100);
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(35,60);             
 display.println(F("by ichnolab"));
 display.display();
 digitalWrite(3,HIGH);
 delay(50);
 digitalWrite(3,LOW);
 delay(200);
 delay(750);
 display.clearDisplay();
 //boot
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(5,61);             
 display.println(F("sw=1.0            hw=1.1"));
 display.setTextSize(1);             
 display.setTextColor(WHITE);       
 display.setCursor(47,5);             
 display.println(F("...booting"));  
 display.display();
 delay(750);
 display.clearDisplay();
 //sens_check   
  if (tcs.begin()) {
    Serial.println("*** ichnuino_LCD_Quality_Tester v_1.0 *** Sensor check= PASSED; RGBC log starting:");
  } else {
    Serial.println("WARNING! No TCS34725 found! Check your RGB sensor or connections");
    while (1);
  }
 }
}

void loop(void) 

{
  uint16_t r, g, b, c, colorTemp, lux;
  int16_t i;

  //don't touch (bad temp readings w/out c)
  tcs.getRawData(&r, &g, &b, &c);
  // colorTemp = tcs.calculateColorTemperature(r, g, b);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  
//serial_log (RGBC)
  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" Kelvin "); Serial.print(" - ");
  Serial.print("Brigthness: "); Serial.print(lux, DEC); Serial.print(" Lux(cd/m2) "); Serial.print(" - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("Clear light: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");

//testing routine (A/AA/AAA/AAA+/TOP_Q/SLEEP)
 {
   if ((lux > lMin && lux <= lBad) and ((colorTemp < kMin && colorTemp >= kBad) or (colorTemp < kBad && colorTemp >= kAvg) or (colorTemp < kAvg && colorTemp >= kGud) or (colorTemp < kGud && colorTemp >= kOem) or (colorTemp < kOem && colorTemp >= kOvr))) {
 //show result A
 display.clearDisplay();
 display.setTextSize(2);             
 display.setTextColor(WHITE);
 display.setCursor(4,55); 
 display.print(" BAD!");
 //head**
 display.drawCircle(93,52, 10, WHITE);
 //eyes circle**
 display.fillCircle(89, 49, 2, WHITE);
 display.fillCircle(97, 49, 2, WHITE);  
 //smile bad** 
 display.drawLine(90, 55, 96, 55, WHITE); 
 display.drawPixel(89, 55, WHITE);
 display.drawPixel(88, 56, WHITE);
 display.drawPixel(87, 57, WHITE);    
 display.drawPixel(97, 55, WHITE);
 display.drawPixel(98, 56, WHITE);
 display.drawPixel(99, 57, WHITE);
 //txt**
 display.setTextSize(2);            
 display.setTextColor(WHITE);        
 display.setCursor(39,11);             
 display.println(F("  A"));  
 //baloon owh**
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(104,47);            
 display.println(F("owh!"));
 //buzz**
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(1000);
   }

   else if ((colorTemp < kMin && colorTemp >= kBad) and ((lux > lBad && lux <= lAvg) or (lux > lAvg && lux <= lGud) or (lux > lGud && lux <= lOem) or (lux > lOem && lux <= lOvr))) {
 //show result A
 display.clearDisplay();
 display.setTextSize(2);             
 display.setTextColor(WHITE);
 display.setCursor(4,55); 
 display.print(" BAD!");
 //head**
 display.drawCircle(93,52, 10, WHITE);
 //eyes circle**
 display.fillCircle(89, 49, 2, WHITE);
 display.fillCircle(97, 49, 2, WHITE);  
 //smile bad** 
 display.drawLine(90, 55, 96, 55, WHITE); 
 display.drawPixel(89, 55, WHITE);
 display.drawPixel(88, 56, WHITE);
 display.drawPixel(87, 57, WHITE);    
 display.drawPixel(97, 55, WHITE);
 display.drawPixel(98, 56, WHITE);
 display.drawPixel(99, 57, WHITE);
 //txt**
 display.setTextSize(2);            
 display.setTextColor(WHITE);        
 display.setCursor(39,11);             
 display.println(F("  A"));  
 //baloon owh**
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(104,47);            
 display.println(F("owh!"));
 //buzz**
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(1000);
   }

   else if ((lux > lBad && lux <= lAvg) and ((colorTemp < kBad && colorTemp >= kAvg) or (colorTemp < kAvg && colorTemp >= kGud) or (colorTemp < kGud && colorTemp >= kOem) or (colorTemp < kOem && colorTemp >= kOvr))) {
 //show result AA
 display.clearDisplay();
 display.setTextSize(2);             
 display.setTextColor(WHITE);
 display.setCursor(4,55); 
 display.print(" ...MEH!"); 
 //head**
 display.drawCircle(93,52, 10, WHITE);
 //eyes circle**
 display.fillCircle(89, 49, 2, WHITE);
 display.fillCircle(97, 49, 2, WHITE);  
 //smile meh** 
 display.drawLine(90, 55, 96, 55, WHITE);
 display.drawPixel(89, 55, WHITE);
 display.drawPixel(88, 55, WHITE);
 display.drawPixel(87, 55, WHITE);   
 display.drawPixel(97, 55, WHITE);
 display.drawPixel(98, 55, WHITE);
 display.drawPixel(99, 56, WHITE);
 //txt**
 display.setTextSize(2);             
 display.setTextColor(WHITE);        
 display.setCursor(39,11);             
 display.println(F(" AA"));
    //baloon mmmh*
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(104,47);            
 display.println(F("mmmh"));
 //buzz**
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(1000);
  }
  
   else  if ((colorTemp < kBad && colorTemp >= kAvg) and ((lux > lAvg && lux <= lGud) or (lux > lGud && lux <= lOem) or (lux > lOem && lux <= lOvr))) {
 //show result AA
 display.clearDisplay();
 display.setTextSize(2);             
 display.setTextColor(WHITE);
 display.setCursor(4,55); 
 display.print(" ...MEH!"); 
 //head**
 display.drawCircle(93,52, 10, WHITE);
 //eyes circle**
 display.fillCircle(89, 49, 2, WHITE);
 display.fillCircle(97, 49, 2, WHITE);  
 //smile meh** 
 display.drawLine(90, 55, 96, 55, WHITE);
 display.drawPixel(89, 55, WHITE);
 display.drawPixel(88, 55, WHITE);
 display.drawPixel(87, 55, WHITE);   
 display.drawPixel(97, 55, WHITE);
 display.drawPixel(98, 55, WHITE);
 display.drawPixel(99, 56, WHITE);
 //txt**
 display.setTextSize(2);             
 display.setTextColor(WHITE);        
 display.setCursor(39,11);             
 display.println(F(" AA"));
 //baloon mmmh*
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(104,47);            
 display.println(F("mmmh"));
 //buzz**
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(1000);
  }

   else if ((lux > lAvg && lux <= lGud) and ((colorTemp < kAvg && colorTemp >= kGud) or (colorTemp < kGud && colorTemp >= kOem) or (colorTemp < kOem && colorTemp >= kOvr))) {
 //show result AAA
 display.clearDisplay();
 display.setTextSize(2);          
 display.setTextColor(WHITE);
 display.setCursor(4,55);
 display.print("GOOD!");
 //head**  
 display.drawCircle(93,52, 10, WHITE);
 //eyes circle**
 display.fillCircle(89, 49, 2, WHITE);
 display.fillCircle(97, 49, 2, WHITE); 
 //smile good** 
 display.drawLine(90, 58, 96, 58, WHITE);
 display.drawPixel(89, 57, WHITE);
 display.drawPixel(88, 56, WHITE);
 display.drawPixel(87, 55, WHITE);   
 display.drawPixel(97, 57, WHITE);
 display.drawPixel(98, 56, WHITE);
 display.drawPixel(99, 55, WHITE);
 //txt**
 display.setTextSize(2);             
 display.setTextColor(WHITE);        
 display.setCursor(39,11);           
 display.println(F(" AAA"));
 //baloon nice*
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(105,47);            
 display.println(F("nice"));
 //buzz**
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(1000);
  } 

   else if ((colorTemp < kAvg && colorTemp >= kGud) and ((lux > lGud && lux <= lOem) or (lux > lOem && lux <= lOvr))) {
 //show result AAA 
 display.clearDisplay();
 display.setTextSize(2);          
 display.setTextColor(WHITE);
 display.setCursor(4,55);
 display.print("GOOD!");  
 //head**
 display.drawCircle(93,52, 10, WHITE);
 //eyes circle**
 display.fillCircle(89, 49, 2, WHITE);
 display.fillCircle(97, 49, 2, WHITE);  
 //smile good**
 display.drawLine(90, 58, 96, 58, WHITE);
 display.drawPixel(89, 57, WHITE);
 display.drawPixel(88, 56, WHITE);
 display.drawPixel(87, 55, WHITE);   
 display.drawPixel(97, 57, WHITE);
 display.drawPixel(98, 56, WHITE);
 display.drawPixel(99, 55, WHITE);
 //txt**
 display.setTextSize(2);             
 display.setTextColor(WHITE);        
 display.setCursor(39,11);           
 display.println(F(" AAA"));
 //baloon nice*
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(105,47);            
 display.println(F("nice"));
 //buzz**
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(1000);
  } 


   else if  ((lux > lGud && lux <= lOem) and ((colorTemp < kGud && colorTemp >= kOem) or (colorTemp < kOem && colorTemp >= kOvr))) {
 //show result AAA+
 display.clearDisplay();
 display.setTextSize(2);          
 display.setTextColor(WHITE);
 display.setCursor(4,55);
 display.print("GREAT!");  
 //head**
 display.drawCircle(93,52, 10, WHITE); 
 //eyes wow**
 display.drawLine(87, 50, 91, 50, WHITE); 
 display.drawLine(95, 50, 99, 50, WHITE); 
 display.drawPixel(87, 49, WHITE); 
 display.drawPixel(91, 49, WHITE);
 display.drawPixel(87, 48, WHITE); 
 display.drawPixel(91, 48, WHITE);
 display.drawPixel(88, 47, WHITE); 
 display.drawPixel(90, 47, WHITE);
 display.drawPixel(89, 47, WHITE);
 display.drawPixel(95, 49, WHITE); 
 display.drawPixel(99, 49, WHITE);
 display.drawPixel(95, 48, WHITE); 
 display.drawPixel(99, 48, WHITE);
 display.drawPixel(96, 47, WHITE); 
 display.drawPixel(98, 47, WHITE);
 display.drawPixel(97, 47, WHITE);
 //smile wow**
 display.drawLine(87, 53, 99, 53, WHITE);
 display.drawPixel(87, 54, WHITE); 
 display.drawPixel(99, 54, WHITE);
 display.drawPixel(87, 55, WHITE); 
 display.drawPixel(99, 55, WHITE);
 display.drawPixel(87, 56, WHITE); 
 display.drawPixel(99, 56, WHITE);
 display.drawPixel(88, 57, WHITE);
 display.drawPixel(98, 57, WHITE);
 display.drawPixel(89, 58, WHITE);
 display.drawPixel(97, 58, WHITE);   
 display.drawLine(90, 59, 96, 59, WHITE);
 //txt**
 display.setTextSize(2);             
 display.setTextColor(WHITE);       
 display.setCursor(42,11);             
 display.println(F("AAA+"));
 //baloon yeah**
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(105,47);            
 display.println(F("yeah"));
 //buzz**
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(1000);
  }

   else if  ((colorTemp < kGud && colorTemp >= kOem) and (lux > lOem && lux <= lOvr)) {
 //show result AAA+
 display.clearDisplay();
 display.setTextSize(2);          
 display.setTextColor(WHITE);
 display.setCursor(4,55);
 display.print("GREAT!");  
 //head**
 display.drawCircle(93,52, 10, WHITE);
 //eyes wow**
 display.drawLine(87, 50, 91, 50, WHITE); 
 display.drawLine(95, 50, 99, 50, WHITE); 
 display.drawPixel(87, 49, WHITE); 
 display.drawPixel(91, 49, WHITE);
 display.drawPixel(87, 48, WHITE); 
 display.drawPixel(91, 48, WHITE);
 display.drawPixel(88, 47, WHITE); 
 display.drawPixel(90, 47, WHITE);
 display.drawPixel(89, 47, WHITE);
 display.drawPixel(95, 49, WHITE); 
 display.drawPixel(99, 49, WHITE);
 display.drawPixel(95, 48, WHITE); 
 display.drawPixel(99, 48, WHITE);
 display.drawPixel(96, 47, WHITE); 
 display.drawPixel(98, 47, WHITE);
 display.drawPixel(97, 47, WHITE);
 //smile wow**
 display.drawLine(87, 53, 99, 53, WHITE);
 display.drawPixel(87, 54, WHITE); 
 display.drawPixel(99, 54, WHITE);
 display.drawPixel(87, 55, WHITE); 
 display.drawPixel(99, 55, WHITE);
 display.drawPixel(87, 56, WHITE); 
 display.drawPixel(99, 56, WHITE);
 display.drawPixel(88, 57, WHITE);
 display.drawPixel(98, 57, WHITE);
 display.drawPixel(89, 58, WHITE);
 display.drawPixel(97, 58, WHITE);   
 display.drawLine(90, 59, 96, 59, WHITE);
 display.setTextSize(2);             
 display.setTextColor(WHITE);       
 display.setCursor(4,11);             
 display.println(F("AAA+"));
    //baloon yeah**
  display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(105,47);            
 display.println(F("yeah"));
 //buzz**
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(1000);
  }

   else if  ((lux > lOem && lux <= lOvr) and (colorTemp < kOem && colorTemp >= kOvr)) {
 //show result TOP_Q
 display.clearDisplay();
 display.setTextSize(2);          
 display.setTextColor(WHITE);
 display.setCursor(4,55);
 display.print("WOW!"); 
 //head**
 display.drawCircle(93,52, 10, WHITE);
 //eyes wow**
 display.drawLine(87, 50, 91, 50, WHITE); 
 display.drawLine(95, 50, 99, 50, WHITE); 
 display.drawPixel(87, 49, WHITE); 
 display.drawPixel(91, 49, WHITE);
 display.drawPixel(87, 48, WHITE); 
 display.drawPixel(91, 48, WHITE);
 display.drawPixel(88, 47, WHITE); 
 display.drawPixel(90, 47, WHITE);
 display.drawPixel(89, 47, WHITE);
 display.drawPixel(95, 49, WHITE); 
 display.drawPixel(99, 49, WHITE);
 display.drawPixel(95, 48, WHITE); 
 display.drawPixel(99, 48, WHITE);
  display.drawPixel(96, 47, WHITE); 
 display.drawPixel(98, 47, WHITE);
 display.drawPixel(97, 47, WHITE);
 //smile wow**
 display.drawLine(87, 53, 99, 53, WHITE);
 display.drawPixel(87, 54, WHITE); 
 display.drawPixel(99, 54, WHITE);
 display.drawPixel(87, 55, WHITE); 
 display.drawPixel(99, 55, WHITE);
 display.drawPixel(87, 56, WHITE); 
 display.drawPixel(99, 56, WHITE);
 display.drawPixel(88, 57, WHITE);
 display.drawPixel(98, 57, WHITE);
 display.drawPixel(89, 58, WHITE);
 display.drawPixel(97, 58, WHITE);   
 display.drawLine(90, 59, 96, 59, WHITE);
 //txt
 display.setTextSize(1);             
 display.setTextColor(WHITE);     
 display.setCursor(43,11);            
 display.println(F(" TOP_Q"));
    //baloon top**
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(105,47);            
 display.println(F("TOP!"));
 //buzz**
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(10);
 digitalWrite(3,HIGH);
 delay(60);
 digitalWrite(3,LOW);
 delay(1000);
  }

   else {
 //show result STAND-BY
 display.clearDisplay();
 display.setTextSize(2);             
 display.setTextColor(WHITE);
 display.setCursor(4,55); 
 display.print(" SLEEP");
 //head** 
 display.drawCircle(93,52, 10, WHITE);
 //eyes sleep**
 display.drawLine(87, 50, 91, 50, WHITE); 
 display.drawLine(95, 50, 99, 50, WHITE);  
  //smile sleep**
 display.drawLine(87, 55, 99, 55, WHITE); 
 //txt**
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(42,10);            
 display.println(F("STAND-BY"));
 //baloon zzz**
 display.setTextSize(1);             
 display.setTextColor(WHITE);        
 display.setCursor(105,47);            
 display.println(F("ZZZ"));
  } 
 }
 //static+readings routine
 display.drawLine(0, 15, 128, 15, WHITE);
 display.drawLine(0, 16, 128, 16, WHITE);
 display.drawLine(0, 40, 128, 40, WHITE);
 display.drawLine(64, 15, 64, 40, WHITE);
 display.drawLine(35, 0, 35, 15, WHITE);
 display.drawLine(93, 0, 93, 15, WHITE);
 display.drawRect(i, i, display.width()-2*i, display.height()-2*i, WHITE);
 display.setTextSize(1);           
 display.setTextColor(WHITE);
 display.setCursor(6,10); 
 display.print("Kelvin           "); display.print("cd/m2");
 display.setTextSize(2);             
 display.setTextColor(WHITE);
 display.setCursor(3,31); 
 display.print(colorTemp, DEC); 
 display.setTextSize(2);            
 display.setTextColor(WHITE);
 display.setCursor(70,31);  
 display.print(lux, DEC);
 display.display();
 //code end

 }
