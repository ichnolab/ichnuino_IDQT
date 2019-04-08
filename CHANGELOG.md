# **VERSION HISTORY**


#### **V_2.0** (work in progress / status: early_alpha)

*scheduled features (pinned if confirmed)*
- [x] small size HW, built on arduino nano;
- [x] dedicated professional brightness sensor, with 600M:1 dynamic range;
- [ ] iphone X/XS/XSM OLED support (OEM+A/M);
- [ ] new REF_DB with more readings from OEM and A/M parts;
- [ ] new Testing Engine, for more accurate classification;
- [ ] general software improvements;
- [ ] ...something else;



#### **V_1.1** (03.31.2019)

  - fixed unrealistic brightness values, that twice as real;
    (now the readings are real cd/m2 values w/dynamic range 3.8M:1)



#### **V_1.0** (03.31.2019)

*Features:*
- real time 5lev-scale Quality classification (A/AA/AAA/AAA+/TOP_Q)
- Realtime Kelvin&cd/m2 readings with 3.8M: dynamic range
- Handmade emoji set w/balloon&comment (different for each lev)
- Buzzer (increasing beeps when higher quality)
- TestingEngineDB rev_2.2 (>150 OEM&A/M parts tested, real cd/m2 readings)
- Serial data logging of RGBC readings (COMport)
- Emergency torch (unplug LED pin from sensor to turn/ON, replug to turn/OFF, DON'T USE WHEN TESTING)
- Adjustable flexible arm with sensor (don't need to push sensor on glass w/finger, just adjust arm's eight)

*models supported:*
- [x] iphone 5/5S/5C/SE *(max lev. AAA (also if OEM)*
- [x] iphone 6/6P
- [x] iphone 6S/6SP
- [x] iphone 7/7P
- [x] iphone 8/8P
- [ ] iphone XR     *(still not supported)*
- [ ] iphone X/XS/XSM *(still not supported)*
