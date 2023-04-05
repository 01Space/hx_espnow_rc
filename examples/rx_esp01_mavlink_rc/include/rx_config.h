#pragma once

/* ESP-01
            ____________
           |  -.-._.   |  
           |           |
           | **  ****  |
           | **  ****  |
           |     ****  |
           |  o o o o  |         GND   GPIO2   GPIO1   RX      
           |__o o o o__|         TX    CH_EN   RESET   VCC 

https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/ 

*/

//Use Mavlink v1 ( 8 RC Channels ) or Mavlink v2 (15 RC Channels)
#define USE_MAVLINK_V1 false

//Telemetry/mavlink port speed
#define TELEMETRY_BAUDRATE 115200

//send packet every ?ms
//Note: If RC messages are sent too frequently, inav will not be able to send telemetry.
//Practical rate it 40...50ms. At 20ms, inav is not able to send telemetry at all.
//This can be fixed only by fixing inav sources.
//inav/src/main/telemetry/mavlink.c, remove "if (!incomingRequestServed) ..."
//See https://github.com/iNavFlight/inav/pull/8274
#define MAVLINK_RC_PACKET_RATE_MS   40  //Rate in Hz = 1000 / MAVLINK_RC_PACKET_RATE_MS

//note: 
//Mavlink v1: 18 bytes(message size) * 25(rate) * 10(bits) = 4500 baud
//Mavlink v2: 34 bytes(message size) * 25(rate) * 10(bits) = 8500 baud

//=============================================================================
//Receiver binding
#define USE_WIFI_CHANNEL 3
#define USE_KEY 0 