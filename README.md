

![logo](https://scontent-mxp1-1.cdninstagram.com/vp/5a0d69fc3391eb50d7b0182028333320/5D4D234C/t51.2885-19/s150x150/52319422_359091484685613_2091248657645961216_n.jpg?_nc_ht=scontent-mxp1-1.cdninstagram.com)

#  :iphone::mag: ***IDQT V 1.0***:octocat: 
## **Iphone Display Quality Tester**

### **Device purpouse:** 
Automatic iphone OEM & A/M display white color quality classification on 5 levels 

### **How it works:**
The device detects the brightness and color temperature of the iphone white screen, classifying the display quality on a five-level scale (A/AA/AAA/AAA+/TOP-Q) and showing Kelvin and cd/m2 readings...plus a very cute dynamic emoji with comment! 
All of this stuffed togheter with some annoying beeps :) 

### **Instructions:** 
1. remove any protective glass (if present);
1. set  brightness at 100% and disable night shift (if enabled); 
1. open phone app at the dialer screen; 
1. put the sensor on a white sector of the screen (it must touch the glass);
1. enjoy the results;

### **models supported:**
- [x] iphone 5/5S/5C/SE *(max lev. AAA (also if OEM)*
- [x] iphone 6/6P
- [x] iphone 6S/6SP
- [x] iphone 7/7P
- [x] iphone 8/8P
- [ ] iphone XR     *(still not supported)*
- [ ] iphone X/XS/XSM *(still not supported)*

### **Hardware:** 

 **Sensor specs:**
RGBC w/IR filter; dynamic range 3.800.000:1 w/adjustable timing; 

- **Components**
  - ARDUINO_UNO
  - OLED_128x64_I2C
  - TCS34725_RGB_SENSOR
  - PIEZO_BUZZER
  - 100OHM_RESISTOR

 **Wiring:**
 
- *Sensor*
  - *TCS34725*: LED --> *ARDUINO*: GND
  - *TCS34725*: INT --> (*NOT USED*)
  - *TCS34725*: SDA --> *ARDUINO*: SDA
  - *TCS34725*: SLC --> *ARDUINO*: SLC
  - *TCS34725*: 3V3 --> (*NOT USED*)
  - *TCS34725*: GND --> *ARDUINO*: GND
  - *TCS34725*: VIN --> *ARDUINO*: 5V

- *Display*
  - *OLED_128x64*: GND --> *ARDUINO*: GND 
  - *OLED_128x64*: VCC --> *ARDUINO*: 5V
  - *OLED_128x64*: SLC --> *ARDUINO*: SLC
  - *OLED_128x64*: SDA --> *ARDUINO*: SDA

- *Buzzer*
  - *BUZZER*: + -> *ARDUINO*: PIN 3
  - *BUZZER*: - --> *100OHM RESISTOR* --> *ARDUINO*: GND
  

### **Software:** 
ichnuinoidqt_1.0 *(C++)*

### **How the code works:** 

- **sensor settings:**
  - custom init values (int time = 700ms, gain = 1x)
  - colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  - lux = tcs.calculateLux(r, g, b);
  
  
  
- **5 levels brightness (L)**:  
  - *300/449 - 450/549 - 550/849 - 850/1049 - 1050/1850*
- **5 levels color temp (K)**: 
  - *8500/7501 - 7500/6501 - 6500/6001 - 6000/5501 - 5500/5000*


- **grade A:**
  - L1 K1/K2/K3/K4/K5 *or*
K1 L2/L3/L4/L5;
- **grade AA:**
  - L2 K2/K3/K4/K5 *or* 
K2 L3/L4/L5;
- **grade AAA:**
  - L3 K3/K4/K5 *or* 
K3 L4/L5;
- **grade AAA+:**
  - L4 K4/K5 *or*
K4 L5;
- **grade TOP_Q:**
  - L5 K5;
- **(SLEEP if out of range)**
- **Buzzer:** 
  - (better the quality, more the beeps)




### **Notes:** 
The results are for reference only. This is a spare time project, made in few weekend just for fun, don't take it seriously. Also if the testing engine and the levels classification dababase are the result of over a hundred values reading on OEM and A/M iphone displays, further research is still in progress.


#### *Made in Italy* :it:
*by* @ichnolab

- *website* 
  - www.ichnolab.it
- *socials*
  - [instagram](https://www.instagram.com/ichnolab/)
  - [facebook](https://www.facebook.com/ichnolab)
  - [twitter](https://twitter.com/ichnolab)


- Picture of V_0.1.2
![V_0-1-2](https://scontent-mxp1-1.cdninstagram.com/vp/35754da099cce1d603ed31845ef3fd30/5D4477C6/t51.2885-15/e35/53830487_2019080171730101_4242390874289956636_n.jpg?_nc_ht=scontent-mxp1-1.cdninstagram.com)
