# Tasmota-thinger.io-bridge
Bridge to *safely* monitor Tasmota devices over the internet

## Tasmota devices are very popular.  
You can purchase inexpensive devices that are very easy to integrate into your local WiFi  
e.g. 4 smart plugs with energy monitoring:  
Moreover you can flash any ESPdevice to Tasmota and configure it to a large number of sensors without need to write code, using just a browser.   
Tasmota works on WiFi and not on the low range Bluetooth and can be used on Smartphones and PCs altogether. However, the standard display of values is quite primitive.  
You get the feature to exchange MQTT messages and hence to provide additional monitoring functions.  
Caveat: devices based on the ESP8266 (quite all commercial devices) cannot encrypt communication.  
That is a very serious security flaw, if you use an external MQTT server.   
It is really very easy to hijack your device and turn it into a malware bot !  
Inside your WLAN you are safe, but ***never*** use it with external addresses !.  
## Project Goals:
Being able to remotely monitor Tasmota devices using safe Thinger.io communication. 
This project uses an ESP8266 as a bridge to thinger.io to log values, provide gorgeous dashboards and much more
In a previous project, I used MQTT to Thinger unencrypted, which worked, but was inherently unsafe. ***Don’t do that !***
## Hardware Used: 
•	ESP8266 Wemos D1 Mini or similar  ($4)
•	Up to 4 Tasmota devices e.g. Refind P11, Sonoff, Shelly…
- meta-device 5 as sum of the four real devices, or sum of the 3 first devices minus the 4th one.
- meta device gathering weather conditions from the internet
•	A wider choice of Tasmota sensors to come…

## Project progress
Currently the code provides support for 4 Refoss P11 smart plugs, which get integrated into one thinger.io combo-device with 4 subdevices.

It will rapidly evolve with following features:
- add more Tasmota sensors: please give me the MQTT strings here: https://github.com/arendst/Tasmota/discussions/22204
- add relay outputs
- add conditions to control the relays
- ... 
