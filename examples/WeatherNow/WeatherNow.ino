#include <TridentTD_OpenWeather.h>

#define ssid      "----- SSID -----"
#define pass      "----- PASS -----"

#define OpenWeather_APIKEY    "----- API KEY -----"

#define lat       13.7530216
#define lon       100.4897376

#define timezone  7


TridentTD_OpenWeather myPlace(OpenWeather_APIKEY);
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println(myPlace.getVersion());
  Serial.println();

  myPlace.wificonnect(ssid, pass);

  myPlace.setLocation( lat, lon );

  /* OPTIONAL to set "unit_type"
     by default   "metric"   ( Celcius, meter/sec) 
     or change to "imperial" ( Fahrenheit, miles/hour) */
  //myPlace.setUnit("metric");
  //myPlace.setUnit("imperial");
  
  myPlace.weatherNow();

  Serial.println("--------------------------------------------");
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
  Serial.println("--------------------------------------------");


}

void loop() {
  // put your main code here, to run repeatedly:

}