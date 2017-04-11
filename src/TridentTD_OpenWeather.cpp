/*

 [TridentTD] : MANABU's Esp8266 IoT Library
 www.facebook.com/miniNodeMCU
 
 TridentTD_OpenWeather.h - A simple client for OpenWeatherMap

 Version 1.0  03/04/2560 Buddism Era  (2017)
 

Copyright (c) 2016 TridentTD

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "TridentTD_OpenWeather.h"
#include "time.h"

/**
 * Constructor.
 */
TridentTD_OpenWeather::TridentTD_OpenWeather(String api_key){
  _api_key = api_key;
  _unit_type = "metric";  //or "imperial"
}

void TridentTD_OpenWeather::setLocation(float lat, float lon){
  // _lat = lat;
  // _lon = lon;

  char _llat[10], _llon[10];

  sprintf( _llat, "%d.%05d", (int) lat, (int)(lat*100000)%100000) ;
  sprintf( _llon, "%d.%05d", (int) lon, (int)(lon*100000)%100000) ;

  _lat = _llat;
  _lon = _llon;

}

void TridentTD_OpenWeather::setUnit(String unit_type){
  if( unit_type == "imperial"){
    _unit_type = "imperial";
  } else {
    _unit_type = "metric";
  }
}


String TridentTD_OpenWeather::latitude(){
  return _lat;
}

String TridentTD_OpenWeather::longitude(){
  return _lon;
}


bool TridentTD_OpenWeather::weatherNow(){



  //------------ OpenWeather API ----------------------------
  String  url  = "http://api.openweathermap.org/data/2.5/weather";
          url += "?lat="   + _lat;
          url += "&lon="   + _lon;
          url += "&units=" + _unit_type;
          url += "&appid=" + _api_key;

  DEBUG_PRINTLN(url);

  _http.begin(url);  
  int httpCode = _http.GET();
  if(httpCode > 0) {
    if(httpCode == HTTP_CODE_OK) {
      String payload = _http.getString();
      
      DEBUG_PRINTLN(payload);DEBUG_PRINTLN();
      
      _http.end();
      
      _weather      = payload.substring( 14+payload.indexOf("description"), payload.indexOf("icon")-3);
      _temperature  = payload.substring( 6+payload.indexOf("temp\""),payload.indexOf("pressure")-2).toFloat();
      _pressure     = payload.substring( 10+payload.indexOf("pressure"),payload.indexOf("humidity")-2).toFloat();
      _humidity     = payload.substring( 10+payload.indexOf("humidity"),payload.indexOf("temp_min")-2).toFloat();
      _windspeed    = payload.substring( 7+payload.indexOf("speed"), payload.indexOf("deg")-2).toFloat();
      _winddeg      = payload.substring( 5+payload.indexOf("deg"), payload.indexOf("},\"clouds")).toFloat();
      _cloudiness   = payload.substring( 15+payload.indexOf("clouds\":{\"all"),payload.indexOf("dt")-3).toFloat();
      
      _sunrise      = (time_t) payload.substring( 9+payload.indexOf("sunrise"),payload.indexOf("sunset")-2).toFloat();
      _sunset       = (time_t) payload.substring( 8+payload.indexOf("sunset"),payload.indexOf("},\"id\"")).toFloat();
      


      return true;
    }
  } else {
    DEBUG_PRINT("[HTTP] GET... failed, error: "); DEBUG_PRINTLN(_http.errorToString(httpCode).c_str());
    _http.end();
    return false;
  }
}

float TridentTD_OpenWeather::readTemperature(){
  return _temperature;
}

float TridentTD_OpenWeather::readHumidity(){
  return _humidity;
}

int TridentTD_OpenWeather::readPressure(){
  return _pressure;
}

String TridentTD_OpenWeather::readWeather(){
  return _weather;
}

float TridentTD_OpenWeather::readWindSpeed(){
  return _windspeed;
}

int TridentTD_OpenWeather::readWindDeg(){
  return _winddeg;
}

int TridentTD_OpenWeather::readCloudiness(){
  return _cloudiness;
}

String TridentTD_OpenWeather::readSunrise(int timezone){

  time_t t = _sunrise + timezone*3600;
  String buffer  = ctime(&t);
  String sunrise = buffer.substring( buffer.indexOf(":") - 2, buffer.indexOf(":") + 6);

  return  sunrise;
}


String TridentTD_OpenWeather::readSunset(int timezone){
  time_t t = _sunset + timezone*3600;
  String buffer  = ctime(&t);
  String sunset  = buffer.substring( buffer.indexOf(":") - 2, buffer.indexOf(":") + 6);

  return  sunset;
}


// String TridentTD_OpenWeather::getTimeStr(time_t t) {

//   if (t != 0 ) {
//     String timeStr = "";
//     timeStr += ( (hour(t)<10)? "0":"" )+ hour(t);
//     timeStr += ":";
//     timeStr += ( (minute(t)<10)? "0":"" )+ minute(t);
//     timeStr += ":";
//     timeStr += ( (second(t)<10)? "0":"" )+ second(t);

//     return timeStr;
//   }
//   else return "Time not set";
// }



bool TridentTD_OpenWeather::wificonnect(char* ssid, char* pass){
  WiFi.begin(ssid, pass);
  
  DEBUG_PRINTLN();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    DEBUG_PRINT(".");
  }
  DEBUG_PRINTLN();
  DEBUG_PRINTLN("WiFi connected");
  DEBUG_PRINT("IP address: ");
  DEBUG_PRINTLN(WiFi.localIP());

}

String TridentTD_OpenWeather::getVersion(){
  return (String)("[TridentTD_OpenWeather] Version ") + String(_version);
}
