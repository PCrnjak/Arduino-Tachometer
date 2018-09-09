# Arduino-Tachometer
## THIS IS STILL WORK IN PROGRESS!!
This is open source tachometer project that is focused on making small ,compact and precise tachometer.
In this github repository you will find everything needed to build this , from code to the STL files and building instructions.
There are 2 design versions that use same code but cases are slightly different , but that will be discussed elseweree in this repository.
![tacho gif](https://user-images.githubusercontent.com/30388414/45233427-0108d600-b2d3-11e8-978f-0932cf2c5d5f.gif)




## Table of contents<a name="table"></a>

 1. [Intro](#intro)
 2. [Table of contents](#table)
 3. [How to use](#use)
 3. [Bill of materials](#bill)
 4. [Building instructions](#inst)
 5. [Code](#code)
 6. [Troubleshooting](#Trouble)
 
 
 
 
 ## How to use<a name="use"></a>
 ![tacho1](https://user-images.githubusercontent.com/30388414/44235748-ded7d880-a1aa-11e8-8a46-6ecb252717dc.jpg)
 
 There are 2 versions of this tachometer . Only difference is in size and boost converters used.Version that worked for me was [v2.0 STL](https://github.com/PCrnjak/Arduino-Tachometer/tree/master/Tacho%20v2.0%20STL) v1.0 STL didnt work correctly for me because i think i had defective boost convereter . So V2 uses larger boost convereter and V1 uses smaller boost convereter(THAT MIGHT NOT WORK FOR YOU TOO).There is also version with buttons and without buttons.I used version without buttons( they also have no use in code).
 
 ![tacho tape](https://user-images.githubusercontent.com/30388414/45235566-87c0b180-b2d9-11e8-9ce9-2bc8f3f73be6.jpg)

 
 To use this tachometer you will need to have some kind of reflective tape( I used aluminium foil) that will cover about 1-1.5 cm of the
 shaft that will be rotating.Rest of the shaft can be any other colour , but i recommend to make rest of the rotating object black because you will have much less trouble calibrating .After you placed tape on shaft you can check at what distance does sensor trigger .Slowly move side of rotating object with reflective tape closer to the sensor , once bottom led triggers rotate object so that non-reflective side is on sensor , it sould not trigger the sensor .If it does go to Troubleshooting. If it does not trigger you can try to mesure speed of your object.I managed to mesure speeds up to 6000 RPM , but it might be able to mesure higher I just didnt have motors that spin faster.
 
 
 ## Bill of materials<a name="bill"></a>
 
 | Name   | Link | Comment |
| ------------- | ------------- | ------------- |
| Arduino pro mini  | [link](https://www.ebay.com/itm/Pro-Mini-Enhancement-ATMEGA328P-5V-16MHz-Compatible-to-Arduino-PRO-mini/191679508570?hash=item2ca0fd305a:g:AxIAAOSwT6pV5YIu)  |    |
| IR sensor  |   |  |
| Li ion battery charger   |     |       |
| 18650 Li-Ion battery   |     |       |
| Slide switch   |     |       |
|15mm M3 screws    |     |       |
|M3 nuts    |     |       |
| Boost converter   |     |       |
| Boost converter   |     |       |
| Female header pins   |     |       |
| SMD push button   |     |       |
| Perf board   |     |       |
|    |     |       |

 
 
 
 ## Building instructions<a name="inst"></a>
 
 
## Code<a name="code"></a>
[Speed test](https://github.com/PCrnjak/Arduino-Tachometer/blob/master/speed_test.ino) is code I used to comfirm that my tachometer was mesuring right speed.More about how it works and how to implement the code can be found in the file.[RPM tacho display](https://github.com/PCrnjak/Arduino-Tachometer/blob/master/rpm_tacho_display.ino) is code used on tachometer to mesure speed.

## Troubleshooting<a name="Trouble"></a>
Firstly test if your sensor works correctly.One of its leds should trigger at specific distance that you can tweek by blue pot on board.
If it does not trigger at all or stays triggered all the time you maybe have defective sensor.
If your sensor on tachometer triggers on both reflective tape and rest of the object try to make rest of the object black. You can print black circle on your printer or 3D print costum part like i did.

## TRIGGERED
![tacho on](https://user-images.githubusercontent.com/30388414/45235799-4f6da300-b2da-11e8-8de0-3457acb897f5.jpg)

## NOT TRIGGERED
![tacho off](https://user-images.githubusercontent.com/30388414/45235804-52689380-b2da-11e8-91d4-8290ce59e689.jpg)

Other problems i noticed:
- When mesuring speed i noticed that changes in light can faulty trigger sensor and cause "spike" of wrong speed.
  - If sensor is too far from mesured object it will start to shoot random speed values.
    - Quick change in speed can cause "spike" in displayed speed

