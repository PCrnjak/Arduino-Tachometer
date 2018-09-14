# Arduino-Tachometer
## THIS IS STILL WORK IN PROGRESS!!
This is open source tachometer project that is focused on making small ,compact and precise tachometer.
In this github repository you will find everything needed to build this , from code to the STL files and building instructions.
There are 2 design versions that use same code but cases are slightly different , but that will be discussed elsewhere in this repository.YouTube [link](https://www.youtube.com/watch?v=HuFqqmQe_AE) of device in action.
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
| IR sensor  | [Link](https://www.ebay.com/itm/2Pcs-Reflective-3pin-IR-Infrared-Obstacle-Avoidance-Sensor-Module-for-Arduino/192067056868?hash=item2cb816b4e4:g:Fr8AAOSwUKxYaNZU)  |  |
| Li ion battery charger   | [Link](https://www.ebay.com/itm/5V-Mini-USB-Charger-Module-for-3-7V-Lithium-Li-ion-18650-Battery-4-2V-Protection/232746845709?hash=item3630cb060d:g:MTkAAOSwai5a4Sbu)     |       |
| 18650 Li-Ion battery   |     | Got mine from laptop battery      |
| Slide switch   |[Link](https://www.ebay.com/itm/10Pcs-On-Off-SPDT-Vertical-3-Pin-1P2T-Mini-Micro-Vertical-Slide-Switch/391684755384?hash=item5b323b0fb8:g:sSQAAOSwt5hYfYif)     |       |
|15mm M3 screws    |     | 2 pieces     |
|5mm M2 screws    |     |  4 pieces     |
|M3 nuts    |     | 2 pieces      |
| Boost converter V1   |[Link](https://www.ebay.com/itm/1-2-5-10PCS-DC-DC-Boost-Converter-Step-Up-Module-1-5V-to-5V-500mA-for-Arduino/311945927376?hash=item48a16d1ad0:m:mfLwIvhD6DkRf64ivaRKXRQ)    | This one is used in V1 and might not work      |
| Boost converter V2   |[Link](https://www.ebay.com/itm/DC-3-24V-to-5V-28V-9V-12V-24V-2A-Adjustable-Boost-Step-Up-Converter-Power-Module/112619032791?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2057872.m2749.l2649)     |This is used in V2 and is proven to work       |
| Female header pins   | [Link](https://www.ebay.com/itm/10PCS-40Pin-2-54mm-Single-Row-Straight-Female-Pin-Header-Strip-PBC-Ardunio/180974322541?epid=1263175571&hash=item2a22e9036d:g:VDQAAOSwbsBXkHSd)    |       |
| SMD push button   | [Link](https://www.ebay.com/itm/100pcs-3X6X2-5mm-Tactile-Push-Button-Switch-Tact-Switch-Micro-Switch-2Pin-SMD-S2/261995936109?epid=1046591979&hash=item3d002cb96d:g:RSsAAOSwyQtVxKPd)    | OPTIONAL       |
| Perf board   |[Link](https://www.ebay.com/itm/10pcs-New-PCB-Prototype-Perf-Universal-Board-Breadboard-5cm-x-7cm-PCB-Board/292371392551?hash=item4412b16827:g:lBIAAOSw-z9Zu5c3)    | OPTIONAL       |

You will also need [FTDI USB to TTL Serial Adapter Module](https://www.ebay.com/itm/FT232RL-3-3V-5-5V-FTDI-USB-to-TTL-Serial-Adapter-Module-for-Arduino-Mini-Port/381374421597?epid=930497168&hash=item58cbafda5d:g:jk8AAOSwrklVMjIp) to program your arduino pro mini.


 
 
 
 ## Building instructions<a name="inst"></a>
 
 Building instructions can be found on instructables page of this [project](https://www.instructables.com/id/Arduino-Tachometer/).
 
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

