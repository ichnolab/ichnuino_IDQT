#  :iphone::mag: ***IDQT V 1.1***:octocat: 
## **Iphone Display Quality Tester**

<img src="https://scontent-mxp1-1.cdninstagram.com/vp/6cf9d5bb728e1ff2b5643d2e2bf81656/5D32CF72/t51.2885-15/e35/56374470_125597435198751_264366501058092392_n.jpg?_nc_ht=scontent-mxp1-1.cdninstagram.com" width="300" height="300" />

#### *youtube link to demo video:*  **https://youtu.be/L-VOf1LVC_Q**

### **Device purpose:** 
Automatic iphone OEM & A/M display white color quality classification on 5-levels scale

### **How it works:**
The device detects the brightness and color temperature of the iphone white screen, classifying the display quality on a five-levels scale and showing Kelvin and cd/m2 readings...plus a very cute dynamic emoji with comment! 
All of this stuffed togheter with some annoying beeps :) 

### **Features:**
- real time 5lev-scale Quality classification (A/AA/AAA/AAA+/TOP_Q)
- Realtime Kelvin&cd/m2 readings with 3.8M: dynamic range
- Handmade emoji set w/balloon&comment (different for each lev)
- Buzzer (increasing beeps when higher quality)
- TestingEngineDB rev_2.2 (>150 OEM&A/M parts tested, real cd/m2 readings)
- Serial data logging of RGBC readings (COMport)
- Emergency torch (unplug LED pin from sensor to turn/ON, replug to turn/OFF, DON'T USE WHEN TESTING)
- Adjustable flexible arm with sensor (don't need to push sensor on glass w/finger, just adjust arm's eight)
- ...already said about the very cute emoji?? yep so that's all, folks!

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

**Power specs**
DC-IN: 5V/0.5A USB/B_port (EXT power port not supported)
    
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
ichnuinoidqt_1.1 (update 040819)

### **How the code works:** 

- **sensor settings:**
  - custom init values (int time = 700ms, gain = 1x)
  - colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  - lux = (tcs.calculateLux(r, g, b) /2);
  
  
- **5 levels brightness (L)**:  
  - *150/199 - 200/249 - 250/374 - 375/474 - 475/900*
- **5 levels color temp (K)**: 
  - *8500/7501 - 7500/7001 - 7000/6501 - 6500/6001 - 6000/4750*


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
- **(SLEEP)**
  - (if out of range)


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


<img src="https://scontent-mxp1-1.cdninstagram.com/vp/5c130981eb8c1741a824d579f934b38a/5D380CC9/t51.2885-15/e35/55758150_369565443658852_4937224586675128474_n.jpg?_nc_ht=scontent-mxp1-1.cdninstagram.com" width="300" height="300" />

<img src="https://scontent-mxp1-1.cdninstagram.com/vp/5e053f664d1c2718ca9374a163da8b53/5D4D8312/t51.2885-15/e35/52829592_2590464110968167_1702059385461725751_n.jpg?_nc_ht=scontent-mxp1-1.cdninstagram.com" width="300" height="300" />



