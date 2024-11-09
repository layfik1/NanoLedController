# NanoLedController
Simple 12V LED Strip Controller with Encoder made with Arduino Nano and TIP-122 MOSFET <br>
## How it works
This controller (dimmer) uses Arduino Nano to handle Encoder input <br>
And controlls brightness of LED strip via sending PWM signal to TIP-122 <br>

![Example](/images/exampleGif.gif "Example")

## How to use
On mode one (it is default) , you can decrease or increase **brightness** of LED strip by spining the Encoder <br>
On mode two ("How it works" GIF) , you can decrease or increase **speed** of blinking <br>

## Circuit Diagram

What parts do you need: <br>
   Arduino Nano <br>
   TIP-122 MOSFET <br>
   KY-040 Encoder <br>
   
![](/images/led.png "Circuit Diagram") <br>

### **Encoder Pins:**
   D2 - SW <br>
   D3 - DT <br>
   D4 - CLK <br>
   GND - GND <br>
   "+"  -  5V <br>
### **MOSFET Pins:**
  Base - D11 <br>
  Collector - LED Strip Ground <br>
  Emitter - 12V In Vcc <br>
### **Arduino Pins:**
  VIN - 12V in Vcc <br>
  GND - 12V in Ground <br>
  
You can dm me in Discord (layfik1) if i made mistakes in this diagram.
