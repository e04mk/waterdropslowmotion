# waterdropslowmotion
Arduino based project to make water drops from a pump look like they fall in slow motion or even backwards.

![Almost finished build](https://github.com/e04mk/waterdropslowmotion/blob/master/version1.jpg)

One potentiometer controls the pump speed and the other potentiometer controls the frequency of the stroboscope(LED strip).
Once the pump speed matches the strobe frequency the water drops will appear to be levitating in the air. With the frequency slightly faster the drops move downwards in slow motion, and with the strobe frequency slightly slower the drops move upwards.

The user can play with the potentiometers to get the effect of their liking.

## Electronics schematics
Since this is built using modules, no real schematic is needed and the only soldering is to connect the peristaltic pump and the LED Strip.

     LED Strip       +->Pump  
        ^           |  
        |           |  
        +           +  
      MosFET<-+ +->MosFET  
              | |  
              + +  
         +>Arduino<-+  
         |          |  
         +          +  
        Pot        Pot  


## Inventory list
* 12V LED Strip (~30W was used)
* Peristaltic Pump 200g 12V 100ml/min
* 2xTinkerKit MosFET
* 2xTinkerKit Rotary Potentiometer
* TinkerKit Sensor Shield v.2
* TinkerKit Cables
* Genuino Uno rev3 (Arduino Uno)
* 12V Power supply

## External links
Inspiration from Mehdi@electroboom: http://www.electroboom.com/?p=268
