#include <TridentTD_OpenWeather.h>

#define ssid      "----- SSID -----"
#define pass      "----- PASS -----"

#define OpenWeather_APIKEY    "----- API KEY -----"

#define lat       ----- LATITUDE  -----
#define lon       ----- LONGITUDE -----


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

  float TempNow  = myPlace.readTemperature();
  float HumidNow = myPlace.readHumidity();

  Serial.print("Temp Outside Now  : "); Serial.println(TempNow);
  Serial.print("Humid Outside Now : "); Serial.println(HumidNow);
}

void loop() {
  // put your main code here, to run repeatedly:

}