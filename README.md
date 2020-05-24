TridentTD_OpenWeather: ASIF NADEEM
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
  
and install ArduinoJson library version 6.x  

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
### readTempMin()
### readTempMax()
### readTempFeelsLike()
### readHumidity()
### readPressure()
### readWeather()
### readWeatherIcon()
### readWindSpeed()
### readWindDeg()
### readCloudiness()
### readSunrise(timezone)
### readSunset(timezone)
### readDateTime(int timezone)

```c++
  Serial.println("[OpenWeather] Location   : " + myPlace.latitude() + ", "+ myPlace.longitude() );
  Serial.println("[OpenWeather] Temperature: " + String(myPlace.readTemperature()));  // [metric] Celcius  or [imperial] Fahrenheit
  Serial.println("[OpenWeather] Temp Min   : " + String(myPlace.readTempMin()));  // [metric] Celcius  or [imperial] Fahrenheit
  Serial.println("[OpenWeather] Temp Max   : " + String(myPlace.readTempMax()));  // [metric] Celcius  or [imperial] Fahrenheit
  Serial.println("[OpenWeather] Feels-Like : " + String(myPlace.readTempFeelsLike()));  // [metric] Celcius  or [imperial] Fahrenheit
  Serial.println("[OpenWeather] Humidity   : " + String(myPlace.readHumidity()));     // %
  Serial.println("[OpenWeather] Pressure   : " + String(myPlace.readPressure()));     // hPa
  Serial.println("[OpenWeather] Weather    : " + myPlace.readWeather());
  Serial.println("[OpenWeather] Wind Speed : " + String(myPlace.readWindSpeed()));    // [metric] meter/sec  or [imperial] miles/hour
  Serial.println("[OpenWeather] Wind Deg   : " + String(myPlace.readWindDeg()));      // degrees
  Serial.println("[OpenWeather] Cloudiness : " + String(myPlace.readCloudiness()));   // %
  Serial.println("[OpenWeather] Sunrise    : " + String(myPlace.readSunrise(timezone)));
  Serial.println("[OpenWeather] Sunset     : " + String(myPlace.readSunset(timezone)));
  Serial.println("[OpenWeather] DateTime   : " + String(myPlace.readDateTime(timezone)));
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
3.0.0  json parser by ArduinoJson 6.x  
  
@ 6 May 2563 BE (Buddhism Era) / 2020  
Ven. Phaisarn Techajaruwong

