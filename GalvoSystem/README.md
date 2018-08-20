# Laser-Galvanometer System 


---
## System Overview


---

## (*MCU*) *DM320010* Microcontroller Development Board
* *PIC32MZ2064DAG169*

Firmware for the *DM320010* is under development using Microchip's *MPLAB IDE* and *Harmony Configurator*.


### USART:
Communication between the MCU board and Host PC uses USART2 via an onboard USB interface on J5.

* **Module / Driver:** 'USART_ID_2' / `DRV_USART0`
  * **Implementation\:**  Static 'Byte Mode' w/ Interrupt Callback.
  * **Baudrate:** 115200
  * **Interrupt Priority:** TX = 1, RX =1 
  * **Users:** Host PC application <-> Embedded client application

### SPI:
Each MAX74 board communicates with the microcontroller using a single SPI Driver.
The DAC and ADC modules each are assigned a `ClientConfiguration`,
 which dynamically sets the baudrate and attaches the required chip select pins.
* **Module / Driver / Device:** 'SPI_ID_2' / `DRV_SPI0` / `[GALVO]_DRV0`
  * **Implementation\:**  Static, Master, Interrupt Enabled, 8-bit Data Width.
  * **Interrupt Priority:** TX = 4, RX = 4 
  * **Baudrate:** w/ DAC = *50MHz*, w/ ADC = *12.5MHz*

* **Module / Driver / Device:** 'SPI_ID_6' / `DRV_SPI1` / `[GALVO]_DRV1`
  * **Implementation\:**  Static, Master, Interrupt Enabled, 8-bit Data Width.
  * **Interrupt Priority:** TX = 3, RX = 3 
  * **Baudrate:** w/ DAC = *50MHz*, w/ ADC = *12.5MHz*
  
### TIMER:

* **Module / Driver / Device:** 'TMR_ID_2' / `DRV_TMR0` / `DAC0` & `DAC1`
  
  `TMR0` synchronizes the output of the DACs for the two driver instances (motors/axis)
  * **Implementation\:**  Static
  * **Interrupt Priority:** 2
  * **Clock Source:** *100MHz*, Internal
  * **Prescale:** 2
  * **Frequency:**  *50MHz*
  * **Max Period:** `0xFFFF`, *1310 µS*
  * **Active Update Period:**  *16 µs*
  

* **Module / Driver / Device:** 'TMR_ID_4' / `DRV_TMR1` / `ADC0` & `ADC1`

  `TMR1` Sets the acquisition timing for both ADCs.
  * **Implementation\:**  Static
  * **Interrupt Priority:** 2
  * **Clock Source:** *100MHz*, Internal
  * **Prescale:** 2


### Pin Connections:

**Header J15:**

|  Function  	|  ID 	| Pin 	| Pin 	|  RID 	|  Function  	|
|:----------:	|:---:	|:---:	|:---:	|:----:	|:----------:	|
|     3V3    	|  -  	|  1  	|  2  	|   -  	|     5V     	|
|  LASER_OK  	| RF2 	|  3  	|  4  	|   -  	|     5V     	|
|            	| RF8 	|  5  	|  6  	|   -  	|     GND    	|
|            	| RE4 	|  7  	|  8  	|  RC3 	|            	|
|     GND    	|  -  	|  9  	|  10 	|  RE8 	|            	|
|            	| RE7 	|  11 	|  12 	|  RH3 	|  LASER_EN  	|
|   MOT0_OK  	| RB8 	|  13 	|  14 	|   -  	|     GND    	|
|   MOT0_EN  	| RA9 	|  15 	|  16 	|  RB4 	|   MOT1_OK  	|
|     3V3    	|  -  	|  17 	|  18 	|  RH4 	|   MOT1_EN  	|
|  SPI2_MOSI 	| RG8 	|  19 	|  20 	|   -  	|            	|
|  SPI2_MISO 	| RD7 	|  21 	|  22 	|  RH6 	|   DRV1_EN  	|
|  SPI2_SCLK 	| RG6 	|  23 	|  24 	|  RD0 	|  SPI6_MISO 	|
|     GND    	|  -  	|  25 	|  26 	| RD14 	|   DAC1_CS  	|
|   ADC0_CS  	| RB2 	|  27 	|  28 	|   -  	|      -     	|
|   DAC0_CS  	| RK1 	|  29 	|  30 	|   -  	|     GND    	|
| DAC0_LATCH 	| RK2 	|  31 	|  32 	|  RJ2 	| DAC1_LATCH 	|
| (USRT2_TX) 	| RG9 	|  33 	|  34 	|   -  	|     GND    	|
| (USRT2_RX) 	| RB0 	|  35 	|  36 	| RB15 	|  SPI6_MOSI 	|
|   DRV0_EN  	| RH7 	|  37 	|  38 	| RH12 	|   ADC1_CS  	|
|     GND    	|  -  	|  39 	|  40 	| RD15 	|  SPI6_SCLK 	|

---
## (*DAQ*) *MAXREFDES74* Data Acquisition Board
The *MAX74*'s 18-bit DAC and ADC are used to interface a single axis galvanometer motor driver card with the MCU.
Communication is provided via an electrically isolated SPI interface. On each board, the DAC and ADC share a single clock signal.
The serial data output of the MCU is routed exclusively to the DAC, and its serial data input is connected exclusively with the ADC. 
Power is supplied by a single *18V* supply, and the board is active when the MCU's `DRV*_EN` signal connected to J20,1 is set low.

### **DAC: MAX5318 Digital to Analog Converter**

  The DAC runs using its default configuration with no static offset.
  With the `TC/SB` pin set low, the incoming data is interpreted as an unsigned 18-bit integer between *0x0* and *0x3FFFF*.
  The MCU sets the chip select pin low to write data to the DAC.
  The new value become valid on the falling-edge of the `DAC*_LATCH` signal.
  
  The DAC uses an external *4.096V* reference to produce an unscaled output between 0 and *4.096V* full scale at TP53. 
  Op Amps U27-U29 and Jumper J5,6,18 are configured to produce *±12.288V* at the bipolar output CON10,11.
  
  
### **ADC: MAX11156 Analog to Digital Converter**
  
  The ADC runs using its default configuration. A new conversion is started on the falling edge of `ADC*_CS`. 
  The MCU blocks for approximately *2 µs* before reading the conversion over SPI.
  
  Using the internal *4.096V* reference the ADC produces *±4.096V* full scale single-ended measurements relative to AGND.
  
### **Jumper Settings**

| Jumper 	|    Connections    	| Description 	|
|:------:	|:-----------------:	|:-----------:	|
|   J5   	|       {1-2}       	|             	|
|   J9   	|       {3-4}       	|             	|
|   J18  	|       {1-2}       	|             	|
|   J21  	| {7-(+5V)}, {9-10} 	|             	|
|   J6   	|       {1-2}       	|             	|
|   J8   	|       {1-2}       	|             	|
|   J10  	|   {1-2}, {9-10}   	|             	|
|   J32  	|       {1-2}       	|             	|

### **Pin Connections:**

**Header J25:**

| MCU Connection 	| Function 	| Pin 	| Pin 	| Function 	| MCU Connection 	|
|:--------------:	|:--------:	|:---:	|:---:	|:--------:	|:--------------:	|
|    `ADC*_CS`   	|  ADC_CS  	|  1  	|  2  	|  DAC_CS  	|    `DAC*_CS`   	|
|        -       	|  ADC_DIN 	|  3  	|  4  	|  DAC_DIN 	|   `SPI*_MOSI`  	|
|   `SPI*_MISO`  	| ADC_DOUT 	|  5  	|  6  	| DAC_DOUT 	|        -       	|
|   `SPI*_SCLK`  	| ADC_SCLK 	|  7  	|  8  	| DAC_SCLK 	|   (short 7-8)  	|
|       GND      	|  ADC_GND 	|  9  	|  10 	|  DAC_GND 	|       GND      	|
|        -       	|    3V3   	|  11 	|  12 	|    3V3   	|        -       	|
|        -       	|     -    	|  -  	|  x  	|   LDAC   	|  `DAC*_LATCH`  	|
