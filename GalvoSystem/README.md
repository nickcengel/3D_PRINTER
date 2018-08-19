# Laser-Galvanometer System Readme


---
## System Overview


---

## PIC32MZ-DM320010 Development Platform
* Microcontroller: PIC32MZ2064DAG169

### Pin Connections:


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
### USART:
Communications with the Host PC uses USART2 via an onboard USB interface on J5.

* **Module / Driver:** 'USART_ID_2' / `DRV_USART0`
  * **Implementation\:**  Static 'Byte Mode' w/ Interrupt Callback.
  * **Baudrate:** 115200
  * **Interrupt Priority:** TX = 1, RX =1 
  * **Users:** Host PC application <-> Embedded client application

### SPI:
Each MAX74 board communicates with the microcontroller (MCU) using a single SPI Driver.
The DAC and ADC modules each are assigned a `ClientConfiguration`
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
  
  * **Implementation\:**  Static, Master, Interrupt Enabled, 8-bit Data Width.
  * **Interrupt Priority:** TX = 3, RX = 3 
  * **Baudrate:** w/ DAC = *50MHz*, w/ ADC = *12.5MHz*

---
  
  