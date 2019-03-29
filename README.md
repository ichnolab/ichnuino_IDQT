

![logo](https://scontent-mxp1-1.cdninstagram.com/vp/5a0d69fc3391eb50d7b0182028333320/5D4D234C/t51.2885-19/s150x150/52319422_359091484685613_2091248657645961216_n.jpg?_nc_ht=scontent-mxp1-1.cdninstagram.com)

# ***IDQT PROTOTYPE V 1.0***

## **-Device purpouse:** 
Automatic iphone OEM & A/M display white color quality classification on 5 levels 

## **-How it works:**
The device detects the brightness and color temperature of the iphone white screen, classifying the display quality on a five-level scale (A/AA/AAA/AAA+/TOP-Q) and showing live Kelvin and cd/m2 readings...plus a very cute dynamic emoji with comment! All of this stuffed togheter with some annoying beeps :) 

## **-sensor specs:** 
RGBC w/IR-filter; dynamic range 3.800.000:1 w/adjustable timing;

## -**models supported:**
- [x] iphone 5/5S/5C/SE *(max lev.reachable AAA (also if OEM)*
- [x] iphone 6/6P
- [x] iphone 6S/6SP
- [x] iphone 7/7P
- [x] iphone 8/8P
- [ ] iphone XR     *(still not supported)*
- [ ] iphone X/XS/XSM *(still not supported)*

## **-hardware:** 
Arduino UNO, Adafruit OLED 0,91" 128x64, Adafruit tcs34725, piezo buzzer, 100ohm resistor, Sunfounder housing, wires;

## **-software:** 
ichnuinoidqt_1.0 *(C++)*

## **How the code works:** 
- 5 levels brightness **(L)**:  
  - *300/449 - 450/549 - 550/849 - 850/1049 - 1050/1850*
- 5 levels color temp **(K)**: 
  - *8500/7501 - 7500/6501 - 6500/6001 - 6000/5501 - 5500/5000*
  
- **(SLEEP if out of range)**

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
  
- **Buzzer:** 
(better the quality, faster the beeps)

## **-instructions:** 
remove any protective glass (if present); set 100% brightness and disable night filter (if enabled); open phone app at the dialer screen; put the sensor on a white sector of the screen (it must touch the glass); enjoy the results;

## **Note:** 
The results are for reference only. This is a spare time project, made in few weekend just for fun, don't take it seriously. Also if the testing engine and the levels classification dababase are the result of over a hundred values reading on OEM and A/M iphone displays, further research is still in progress.

-Picture of V_0.1.2
![V_0-1-2](https://scontent-mxp1-1.cdninstagram.com/vp/35754da099cce1d603ed31845ef3fd30/5D4477C6/t51.2885-15/e35/53830487_2019080171730101_4242390874289956636_n.jpg?_nc_ht=scontent-mxp1-1.cdninstagram.com)
