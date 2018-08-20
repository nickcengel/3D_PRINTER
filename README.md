# *A Future Printing System*
## Introduction
```
                             LASER-GALVO SYSTEM
+----------+           +--------------------------+
|          |           |            ||            |
|   HOST   +---+       |            ||            |
| COMPUTER |   |       |            ||GALVANOMETER|
|          |   |       |    MCU     ||   SYSTEM   |
+----------+   |       |   CLIENT   ||            |
               V       |    APP     |-------------+
+----------------+     |            ||            |
|                |     |            ||   LASER    |
|    USB HUB     +---> |            ||   SYSTEM   |
|                |     |            ||            |
+--+---------+---+     +--------------------------+
   |         |         +-------------+    +-------+
   |         +-------> | SINGLE AXIS |    | BUILD |
   v                   | CONTROLLER  | -> | PLATE |
+--+----------+   +--+ |             |    | MOTOR |
|             |   |    +-------------+    +-------+
| ENVIRONMENT |   |    +-------------+    +-------+
| CONTROLLER  |   |    |             |    | MATL. |
|             |   |    |             | -> | HOPPER|
+-------------+   |    |    DUAL     |    | MOTOR |
                  +--> |    AXIS     |    +-------+
                       | CONTROLLER  |    +-------+
                       |             |    | MATL. |
                       |             | -> | SPREAD|
                       |             |    | MOTOR |
                       +-------------+    +-------+
```
## Hardware Components
### Material Delivery:
### Galvanometer:
### Laser:
### Environment Control:
## Software Components
### Host Application:
### Client Application:


