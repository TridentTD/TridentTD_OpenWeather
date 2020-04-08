TridentTD_OpenWeather
============
[TridentTD] Esp8266, ESP32 's OpenWeather Library
---------------------------------------------

`TridentTD_OpenWeather` is a library for `ESP8266` , `ESP32` board  
to get Weather Status at any place by latitude, longitude   
from OpenWeatherMap API in the simplest method.

# Install

Clone (or download and unzip) the repository to `~/Documents/Arduino/libraries`
where `~/Documents/Arduino` is your sketchbook directory.

    > cd ~/Documents/Arduino
    > mkdir libraries
    > cd libraries
    > git clone https://github.com/TridentTD/TridentTD_OpenWeather.git TridentTD_OpenWeather

# Usage

### Include

You need to have the `ESP8266` or `ESP32`board support already included.

```c++
#include <TridentTD_OpenWeather.h>
```

### TridentTD\_OpenWeather  myPlace(OpenWeather_APIKEY)

Constructor to create an TridentTD\_OpenWeather object.

```c++
 TridentTD_OpenWeather  myPlace(OpenWeather_APIKEY);
```

### wificonnect( ssid,password)

Setup the `ESP8266` board's `wifi` to the `ssid` . 
However you can connect by yourself.

```c++
myPlace.wificonnect( ssid,password );
```

### setLocation( lat, lon )

Set up your location by latitude and longitude.

```c++
myPlace.setLocation( lat, lon );
```

### setUnit( unit_type)

Set up unit type.  By default "metric" (celcius, meter/sec).  
Or "imperial" (fahrenheit, miles/hour)

```c++
myPlace.setUnit("metric");
myPlace.setUnit("imperial");
```

### weatherNow()

Get weather information of your place at now.

```c++
myPlace.weatherNow();
```

### readTemperature()
### readHumidity()
### readPressure()
### readWeather()
### readWindSpeed()
### readWindDeg()
### readCloudiness()
### readSunrise(timezone)
### readSunset(timezone)


```c++
myPlace.readTemperature();  // unit = celcius (metric) or Fahrenheit (imperial)
myPlace.readHumidity();       // unit = %
myPlace.readPressure();        // unit = hPa
myPlace.readWeather(); 
myPlace.readWindSpeed();   // unit = meter/sec (metric) or miles/hour (imperial)
myPlace.readWindDeg();      // unit = degrees
myPlace.readCloudiness();   // unit = %
myPlace.readSunrise(timezone);
myPlace.readSunset(timezone);
```

### getVersion()

Get version of this library.

```c++
myPlace.getVersion();
```

Version
=====
1.0.0  TridentTD_OpenWeather  
2.0.0  support ESP32  
  
@ 25 May 2561 BE (Buddhism Era) / 2018  
Ven. Phaisarn Techajaruwong
