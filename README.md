TridentTD_OpenWeather
============
[TridentTD] Manabu's Esp8266 IoT Library
---------------------------------------------

TridentTD_OpenWeather is a library for ESP8266   
to get Weather Status at any place by latitude, longitude   
from OpenWeatherMap API in the simplest method.

You can use functions like this

- TridentTD_OpenWeather myPlace(OpenWeather_APIKEY);
- myPlace.wificonnect( ssid,password );
- myPlace.setLocation( lat, lon );
- myPlace.setUnit("metric");  // "metric" (celcius, meter/sec) or "imperial" (fahrenheit, miles/hour)
- myPlace.weatherNow();
- myPlace.readTemperature();  // unit = celcius (metric) or Fahrenheit (imperial)
- myPlace.readHumidity();     // unit = %
- myPlace.readPressure();      // unit = hPa
- myPlace.readWeather(); 
- myPlace.readWindSpeed(); // unit = meter/sec (metric) or miles/hour (imperial)
- myPlace.readWindDeg();    // unit = degrees
- myPlace.readCloudiness();  // unit = %
- myPlace.readSunrise(timezone);
- myPlace.readSunset(timezone);
- myLine.getVersion();

Version
=====
1.0.0  TridentTD_OpenWeather

@ 11 April 2560 BE (Buddism Era)  / 2017  
Ven. Phaisarn Techajaruwong
