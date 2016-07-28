# waterdropslowmotion
Code to make water drops from a pump look like they fall in slow motion or even backwards.

One potentiometer controls the pump speed and the other potentiometer controls the frequency of the stroboscope(LED strip).
Once the pump speed matches the strobe frequency the water drops will appear to be levitating in the air.
The user can play with the potentiometers to get the effect of their liking.


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
